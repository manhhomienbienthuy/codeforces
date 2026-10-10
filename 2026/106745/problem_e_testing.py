#!/usr/bin/env python3
import argparse
import queue
import random
import shlex
import subprocess
import sys
import threading


def fail(msg, proc=None):
    print(f"[JUDGE ERROR] {msg}", file=sys.stderr, flush=True)
    if proc is not None and proc.poll() is None:
        proc.kill()
    raise SystemExit(1)


def output_reader(stream, out_q):
    try:
        for line in iter(stream.readline, ""):
            out_q.put(line)
    finally:
        out_q.put(None)


def read_line(proc, out_q, timeout):
    try:
        line = out_q.get(timeout=timeout)
    except queue.Empty:
        fail("Timeout while waiting for the solution. Did you flush output?", proc)

    if line is None:
        fail("Solution terminated unexpectedly.", proc)

    return line.strip()


def send(proc, s, verbose):
    if verbose:
        print(f"judge -> solution: {s}", file=sys.stderr, flush=True)

    try:
        proc.stdin.write(s + "\n")
        proc.stdin.flush()
    except (BrokenPipeError, OSError):
        fail("Cannot send input because the solution has terminated.", proc)


def make_cases(args):
    cases = list(args.case)
    rng = random.Random(args.seed)

    for _ in range(args.random):
        n = rng.randint(args.min_n, args.max_n)
        cases.append("".join(rng.choice("01") for _ in range(n)))

    if not cases:
        cases = ["1100", "11111", "0000", "101010", "01101001"]

    for b in cases:
        if not 4 <= len(b) <= 1000 or any(c not in "01" for c in b):
            fail(f"Invalid hidden sequence: {b!r}")

    if len(cases) > 1000:
        fail("At most 1000 test cases are allowed.")

    return cases


def main():
    parser = argparse.ArgumentParser(
        description="Windows-compatible local interactor"
    )
    parser.add_argument(
        "--solver",
        required=True,
        help='Solution command, for example: main.exe or "python sol.py"',
    )
    parser.add_argument(
        "--case",
        action="append",
        default=[],
        help="Hidden binary sequence; may be used multiple times",
    )
    parser.add_argument("--random", type=int, default=0)
    parser.add_argument("--min-n", type=int, default=4)
    parser.add_argument("--max-n", type=int, default=1000)
    parser.add_argument("--seed", type=int, default=1)
    parser.add_argument("--timeout", type=float, default=3.0)
    parser.add_argument("--quiet", action="store_true")
    args = parser.parse_args()

    if not 4 <= args.min_n <= args.max_n <= 1000:
        fail("Require 4 <= min-n <= max-n <= 1000.")

    cases = make_cases(args)

    # posix=False preserves Windows paths and quoting correctly.
    cmd = shlex.split(args.solver, posix=(sys.platform != "win32"))

    try:
        proc = subprocess.Popen(
            cmd,
            stdin=subprocess.PIPE,
            stdout=subprocess.PIPE,
            stderr=None,
            text=True,
            bufsize=1,
        )
    except OSError as e:
        fail(f"Could not start the solution: {e}")

    out_q = queue.Queue()
    thread = threading.Thread(
        target=output_reader,
        args=(proc.stdout, out_q),
        daemon=True,
    )
    thread.start()

    verbose = not args.quiet
    send(proc, str(len(cases)), verbose)

    for tc, b in enumerate(cases, 1):
        n = len(b)
        send(proc, str(n), verbose)
        queries = 0

        while True:
            line = read_line(proc, out_q, args.timeout)

            if verbose:
                print(f"solution -> judge: {line}", file=sys.stderr, flush=True)

            tok = line.split()
            if not tok:
                fail(f"Case {tc}: empty output line.", proc)

            if tok[0] == "?":
                if len(tok) != 3:
                    fail(f"Case {tc}: expected '? m r', got {line!r}.", proc)

                try:
                    m, r = map(int, tok[1:])
                except ValueError:
                    fail(f"Case {tc}: m and r must be integers.", proc)

                queries += 1
                if queries > 35:
                    fail(f"Case {tc}: query limit exceeded.", proc)
                if not 2 <= m <= n - 1:
                    fail(f"Case {tc}: m={m} is outside [2, {n - 1}].", proc)
                if r < 1 or m - r < 1 or m + r > n:
                    fail(f"Case {tc}: invalid r={r} for m={m}, n={n}.", proc)

                ans = sum(
                    int(b[m - d - 1]) + int(b[m + d - 1])
                    for d in range(1, r + 1)
                )
                send(proc, str(ans), verbose)

            elif tok[0] == "!":
                if len(tok) != 2:
                    fail(f"Case {tc}: expected '! x', got {line!r}.", proc)

                try:
                    got = int(tok[1])
                except ValueError:
                    fail(f"Case {tc}: answer must be an integer.", proc)

                want = b.count("1")
                if got != want:
                    fail(
                        f"Case {tc}: wrong answer for B={b}. "
                        f"Expected {want}, received {got}. Queries={queries}.",
                        proc,
                    )

                print(f"Case {tc}: OK, n={n}, ones={want}, queries={queries}")
                break

            else:
                fail(f"Case {tc}: expected '?' or '!', got {line!r}.", proc)

    proc.stdin.close()

    try:
        code = proc.wait(timeout=args.timeout)
    except subprocess.TimeoutExpired:
        fail("Solution did not terminate after all test cases.", proc)

    if code != 0:
        fail(f"Solution exited with code {code}.")

    print(f"All {len(cases)} test cases passed.")


if __name__ == "__main__":
    main()
