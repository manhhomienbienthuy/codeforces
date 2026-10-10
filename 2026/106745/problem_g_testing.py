#!/usr/bin/env python3

"""Local testing tool for the two-run tree communication problem.

Disclaimer: this is a contestant-side debugging tool, not the judge checker.
The official checker may use different private seeds and traversal choices.

Accepted data formats
---------------------

Judge-style batch input:

    first
    t
    n_1
    u v
    ...

or a convenient single-tree input:

    n
    u v
    ...

Run examples:

    python3 tree_communication_testing_tool2.py data.in ./solution
    python3 tree_communication_testing_tool2.py --trials 10 data.in ./solution
    python3 tree_communication_testing_tool2.py data.in python3 solution.py
    python3 tree_communication_testing_tool2.py --quiet data.in java -cp . Main

The tested program is started twice in every trial. The tool randomly chooses
the Euler-tour root and neighbor order for every tree, then randomly shuffles
the batch before the second run. The first input starts with ``first`` and the
second input starts with ``second``.
"""

from __future__ import annotations

import argparse
import random
import subprocess
import sys
from dataclasses import dataclass
from typing import Dict, List, Sequence, Tuple


Edge = Tuple[int, int]


class WrongAnswer(RuntimeError):
    pass


@dataclass
class Tree:
    n: int
    edges: List[Edge]


def parse_int(token: str, description: str) -> int:
    try:
        return int(token)
    except ValueError as exc:
        raise WrongAnswer(f"Invalid {description}: {token!r}.") from exc


def read_data(path: str) -> List[Tree]:
    with open(path, "r", encoding="utf-8") as file:
        tokens = file.read().split()
    if not tokens:
        raise ValueError("The data file is empty.")

    position = 0
    batch = tokens[0].lower() == "first"
    if batch:
        position += 1
        if position == len(tokens):
            raise ValueError("Missing t after 'first'.")
        t = int(tokens[position])
        position += 1
    else:
        t = 1

    if not 1 <= t <= 10000:
        raise ValueError(f"t={t} is outside [1, 10000].")

    trees: List[Tree] = []
    total_n = 0
    for case_id in range(1, t + 1):
        if position >= len(tokens):
            raise ValueError(f"Missing n for tree {case_id}.")
        n = int(tokens[position])
        position += 1
        if not 2 <= n <= 200000:
            raise ValueError(f"Tree {case_id}: n={n} is outside [2, 200000].")
        total_n += n
        if total_n > 200000:
            raise ValueError("The sum of n exceeds 200000.")

        edges: List[Edge] = []
        for edge_id in range(1, n):
            if position + 1 >= len(tokens):
                raise ValueError(f"Tree {case_id}: missing endpoints of edge {edge_id}.")
            u, v = int(tokens[position]), int(tokens[position + 1])
            position += 2
            if not (1 <= u <= n and 1 <= v <= n):
                raise ValueError(f"Tree {case_id}: endpoint out of range: {u} {v}.")
            edges.append((u - 1, v - 1))
        validate_tree(Tree(n, edges), f"input tree {case_id}")
        trees.append(Tree(n, edges))

    if position != len(tokens):
        raise ValueError(f"The data file contains {len(tokens) - position} extra token(s).")
    return trees


def adjacency(tree: Tree) -> List[List[int]]:
    graph = [[] for _ in range(tree.n)]
    for u, v in tree.edges:
        graph[u].append(v)
        graph[v].append(u)
    return graph


def validate_tree(tree: Tree, description: str) -> None:
    if len(tree.edges) != tree.n - 1:
        raise WrongAnswer(f"{description} has {len(tree.edges)} edges, expected {tree.n - 1}.")
    parent = list(range(tree.n))
    size = [1] * tree.n

    def find(x: int) -> int:
        while parent[x] != x:
            parent[x] = parent[parent[x]]
            x = parent[x]
        return x

    for u, v in tree.edges:
        if not (0 <= u < tree.n and 0 <= v < tree.n):
            raise WrongAnswer(f"{description} has an endpoint outside [1, {tree.n}].")
        if u == v:
            raise WrongAnswer(f"{description} has a self-loop at vertex {u + 1}.")
        a, b = find(u), find(v)
        if a == b:
            raise WrongAnswer(f"{description} contains a cycle.")
        if size[a] < size[b]:
            a, b = b, a
        parent[b] = a
        size[a] += size[b]

    root = find(0)
    if any(find(vertex) != root for vertex in range(tree.n)):
        raise WrongAnswer(f"{description} is disconnected.")


def centers(graph: Sequence[Sequence[int]]) -> List[int]:
    n = len(graph)
    degree = [len(neighbors) for neighbors in graph]
    leaves = [vertex for vertex in range(n) if degree[vertex] <= 1]
    remaining = n
    while remaining > 2:
        remaining -= len(leaves)
        new_leaves: List[int] = []
        for u in leaves:
            degree[u] = 0
            for v in graph[u]:
                if degree[v] > 0:
                    degree[v] -= 1
                    if degree[v] == 1:
                        new_leaves.append(v)
        leaves = new_leaves
    return leaves


def rooted_type(
    graph: Sequence[Sequence[int]], root: int, blocked: int,
    interner: Dict[Tuple[int, ...], int]
) -> int:
    parent = [-1] * len(graph)
    parent[root] = blocked
    order = [root]
    for u in order:
        for v in graph[u]:
            if v != parent[u]:
                parent[v] = u
                order.append(v)

    subtree_type = [0] * len(graph)
    for u in reversed(order):
        children = sorted(subtree_type[v] for v in graph[u] if parent[v] == u)
        key = tuple(children)
        if key not in interner:
            interner[key] = len(interner)
        subtree_type[u] = interner[key]
    return subtree_type[root]


def isomorphic(first: Tree, second: Tree) -> bool:
    if first.n != second.n:
        return False
    graph1, graph2 = adjacency(first), adjacency(second)
    center1, center2 = centers(graph1), centers(graph2)
    if len(center1) != len(center2):
        return False
    interner: Dict[Tuple[int, ...], int] = {}
    if len(center1) == 1:
        return rooted_type(graph1, center1[0], -1, interner) == rooted_type(
            graph2, center2[0], -1, interner
        )
    type1 = sorted([
        rooted_type(graph1, center1[0], center1[1], interner),
        rooted_type(graph1, center1[1], center1[0], interner),
    ])
    type2 = sorted([
        rooted_type(graph2, center2[0], center2[1], interner),
        rooted_type(graph2, center2[1], center2[0], interner),
    ])
    return type1 == type2


def euler_tour(tree: Tree, rng: random.Random) -> List[int]:
    graph = adjacency(tree)
    for neighbors in graph:
        rng.shuffle(neighbors)
    root = rng.randrange(tree.n)

    parent = [-2] * tree.n
    index = [0] * tree.n
    stack = [root]
    tour = [root]
    parent[root] = -1
    while stack:
        u = stack[-1]
        while index[u] < len(graph[u]) and graph[u][index[u]] == parent[u]:
            index[u] += 1
        if index[u] == len(graph[u]):
            stack.pop()
            if stack:
                tour.append(stack[-1])
            continue
        v = graph[u][index[u]]
        index[u] += 1
        if v == parent[u]:
            continue
        parent[v] = u
        stack.append(v)
        tour.append(v)
    if len(tour) != 2 * tree.n - 1:
        raise RuntimeError("Internal error while producing an Euler tour.")
    return tour


def make_first_input(trees: Sequence[Tree]) -> str:
    lines = ["first", str(len(trees))]
    for tree in trees:
        lines.append(str(tree.n))
        lines.extend(f"{u + 1} {v + 1}" for u, v in tree.edges)
    return "\n".join(lines) + "\n"


def make_second_input(
    trees: Sequence[Tree], colors: Sequence[Sequence[int]], rng: random.Random
) -> Tuple[str, List[int]]:
    sequences: List[List[int]] = []
    for case_id, tree in enumerate(trees):
        tour = euler_tour(tree, rng)
        sequences.append([colors[case_id][vertex] for vertex in tour])

    order = list(range(len(trees)))
    rng.shuffle(order)

    lines = ["second", str(len(trees))]
    for case_id in order:
        lines.append(str(trees[case_id].n))
        lines.append(" ".join(map(str, sequences[case_id])))
    return "\n".join(lines) + "\n", order


def show_block(title: str, contents: str, quiet: bool) -> None:
    if quiet:
        return
    print(f"[{title}]")
    print(contents, end="" if contents.endswith("\n") else "\n")


def run_program(
    command: Sequence[str], phase: str, input_text: str, timeout: float, quiet: bool
) -> str:
    if not quiet:
        print(f"[{phase}] {' '.join(command)}")
        show_block(f"input to {phase}", input_text, quiet)
    try:
        completed = subprocess.run(
            list(command), input=input_text, stdout=subprocess.PIPE,
            stderr=subprocess.PIPE, text=True, timeout=timeout, check=False,
        )
    except subprocess.TimeoutExpired as exc:
        raise WrongAnswer(f"{phase} exceeded the {timeout:g}-second local timeout.") from exc
    if not quiet:
        show_block(f"output from {phase}", completed.stdout, quiet)
        if completed.stderr:
            show_block(f"stderr from {phase}", completed.stderr, quiet)
    if completed.returncode != 0:
        raise WrongAnswer(f"{phase} exited with code {completed.returncode}.")
    return completed.stdout


def parse_first_output(text: str, trees: Sequence[Tree]) -> List[List[int]]:
    tokens = text.split()
    expected = sum(tree.n for tree in trees)
    if len(tokens) != expected:
        raise WrongAnswer(
            f"First run produced {len(tokens)} token(s); exactly {expected} colors are required."
        )
    colors: List[List[int]] = []
    position = 0
    for case_id, tree in enumerate(trees, 1):
        current: List[int] = []
        for _ in range(tree.n):
            value = parse_int(tokens[position], f"color for tree {case_id}")
            position += 1
            if value not in (0, 1):
                raise WrongAnswer(f"Tree {case_id}: color {value} is not 0 or 1.")
            current.append(value)
        colors.append(current)
    return colors


def parse_second_output(text: str, expected_trees: Sequence[Tree]) -> List[Tree]:
    tokens = text.split()
    if not tokens:
        raise WrongAnswer("Second run produced no output.")
    position = 0
    answers: List[Tree] = []
    for case_id, expected in enumerate(expected_trees, 1):
        n = expected.n
        edges: List[Edge] = []
        for edge_id in range(1, n):
            if position + 1 >= len(tokens):
                raise WrongAnswer(f"Tree {case_id}: missing endpoints of edge {edge_id}.")
            u = parse_int(tokens[position], "edge endpoint")
            v = parse_int(tokens[position + 1], "edge endpoint")
            position += 2
            edges.append((u - 1, v - 1))
        answer = Tree(n, edges)
        validate_tree(answer, f"reconstructed tree {case_id}")
        answers.append(answer)

    if position != len(tokens):
        raise WrongAnswer(f"Second run contains {len(tokens) - position} extra token(s).")
    return answers


def run_trial(
    trees: Sequence[Tree], command: Sequence[str], seed: int,
    timeout: float, quiet: bool
) -> None:
    first_input = make_first_input(trees)
    first_output = run_program(command, "first run", first_input, timeout, quiet)
    colors = parse_first_output(first_output, trees)

    rng = random.Random(seed)
    second_input, order = make_second_input(trees, colors, rng)
    second_output = run_program(command, "second run", second_input, timeout, quiet)
    expected = [trees[index] for index in order]
    answers = parse_second_output(second_output, expected)
    for case_id, (original, answer) in enumerate(zip(expected, answers), 1):
        if not isomorphic(original, answer):
            raise WrongAnswer(
                f"Reconstructed tree {case_id} is not isomorphic to its original tree."
            )


def main() -> int:
    parser = argparse.ArgumentParser(
        usage="%(prog)s [options] data.in program [args...]",
        description="Run a solution twice and locally verify the tree communication protocol.",
    )
    parser.add_argument("--quiet", "-q", action="store_true", help="do not print full I/O")
    parser.add_argument("--seed", type=int, default=1, help="first random seed (default: 1)")
    parser.add_argument("--trials", type=int, default=1, help="number of independent runs")
    parser.add_argument("--timeout", type=float, default=10.0, help="timeout for each run")
    parser.add_argument("data", help="batch input beginning with 'first', or one bare tree")
    parser.add_argument("program", nargs=argparse.REMAINDER, help="program and its arguments")
    args = parser.parse_args()

    if not args.program:
        parser.error("a program must be specified")
    if args.trials < 1:
        parser.error("--trials must be positive")
    if args.timeout <= 0:
        parser.error("--timeout must be positive")

    try:
        trees = read_data(args.data)
        for trial in range(args.trials):
            seed = args.seed + trial
            if not args.quiet:
                print(f"===== trial {trial + 1}/{args.trials}, seed={seed} =====")
            run_trial(trees, args.program, seed, args.timeout, args.quiet)
            print(f"Trial {trial + 1}: accepted (all reconstructed trees are isomorphic).")
    except (OSError, ValueError, WrongAnswer) as exc:
        print(f"Error: {exc}", file=sys.stderr)
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
