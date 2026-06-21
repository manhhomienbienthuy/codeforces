#!/usr/bin/env python3
"""
Script to organize Codeforces solutions by year and session.
Contest folders are named by contest ID (from Codeforces URL).
This script fetches contest data from Codeforces API and reorganizes them.
"""

import os
import json
import shutil
from pathlib import Path
from datetime import datetime
from typing import Dict, List, Optional
import subprocess
import requests


class CodeforcesOrganizer:
    API_BASE = "https://codeforces.com/api"

    def __init__(self, repo_root: Path = Path(".")):
        self.repo_root = repo_root
        self.contests_cache: Dict[int, Dict] = {}
        self.moves: List[tuple] = []  # Track moves for git

    def get_contest_info(self, contest_id: int) -> Optional[Dict]:
        """Fetch contest info from Codeforces API"""
        if contest_id in self.contests_cache:
            return self.contests_cache[contest_id]

        try:
            response = requests.get(
                f"{self.API_BASE}/contest.list",
                params={"gym": "false"},
                timeout=5
            )
            response.raise_for_status()
            contests = response.json()["result"]

            # Cache all contests
            for contest in contests:
                self.contests_cache[contest["id"]] = contest

            return self.contests_cache.get(contest_id)
        except Exception as e:
            print(f"Error fetching contest data: {e}")
            return None

    def get_year_and_name(self, contest_id: int) -> tuple:
        """Get year and friendly name for a contest"""
        contest = self.get_contest_info(contest_id)

        if contest and "startTimeSeconds" in contest:
            year = datetime.fromtimestamp(contest["startTimeSeconds"]).year
            name = contest.get("name", "").replace("/", "_").replace(" ", "_")
            return year, name

        # Fallback: estimate year from contest ID
        # Older contests: 1-999 (2010-2011)
        # Recent contests: 1000+ (2012+)
        if contest_id < 100:
            year = 2010
        elif contest_id < 200:
            year = 2011
        elif contest_id < 500:
            year = 2012
        elif contest_id < 1000:
            year = 2013
        else:
            # Rough estimation: contests every day-ish
            # Contest 1000 ≈ late 2013
            year = 2013 + (contest_id - 1000) // 365

        return year, f"contest_{contest_id}"

    def get_contest_folders(self) -> List[str]:
        """Get all contest ID folders (numeric directories)"""
        contest_folders = []
        for item in os.listdir(self.repo_root):
            path = self.repo_root / item
            if path.is_dir() and item.isdigit() and item not in [".git", ".vscode"]:
                contest_folders.append(item)
        return sorted(contest_folders, key=int)

    def create_year_structure(self) -> Dict[int, List[str]]:
        """Organize contests by year"""
        year_contests: Dict[int, List[str]] = {}
        contest_folders = self.get_contest_folders()

        for contest_id_str in contest_folders:
            contest_id = int(contest_id_str)
            year, name = self.get_year_and_name(contest_id)

            if year not in year_contests:
                year_contests[year] = []
            year_contests[year].append(contest_id_str)

        return dict(sorted(year_contests.items()))

    def plan_moves(self, dry_run: bool = True) -> List[tuple]:
        """Plan file moves (source, destination)"""
        year_contests = self.create_year_structure()
        moves = []

        for year, contests in year_contests.items():
            year_dir = self.repo_root / str(year)

            for contest_id_str in contests:
                src = self.repo_root / contest_id_str
                dst = year_dir / contest_id_str

                if src.exists():
                    moves.append((src, dst))

        return moves

    def execute_moves(self, moves: List[tuple], use_git: bool = True):
        """Execute the reorganization"""
        if not moves:
            print("No moves to execute!")
            return

        # Create year directories
        years = set()
        for src, dst in moves:
            years.add(dst.parent)

        for year_dir in years:
            year_dir.mkdir(parents=True, exist_ok=True)
            print(f"Created: {year_dir}")

        # Execute moves with git mv
        for src, dst in moves:
            if not src.exists():
                print(f"⚠️  Source not found: {src}")
                continue

            if dst.exists():
                print(f"⚠️  Destination already exists: {dst}")
                continue

            try:
                if use_git:
                    subprocess.run(
                        ["git", "mv", src.as_posix(), dst.as_posix()],
                        cwd=self.repo_root,
                        check=True,
                        capture_output=True
                    )
                    print(f"✓ Moved (git): {src.name} → {dst.parent.name}/{dst.name}")
                else:
                    shutil.move(str(src), str(dst))
                    print(f"✓ Moved: {src.name} → {dst.parent.name}/{dst.name}")
            except Exception as e:
                print(f"✗ Error moving {src}: {e}")

    def print_summary(self):
        """Print organization summary"""
        year_contests = self.create_year_structure()

        print("\n" + "="*60)
        print("CODEFORCES CONTESTS ORGANIZATION PLAN")
        print("="*60 + "\n")

        for year, contests in year_contests.items():
            print(f"📅 {year}/ ({len(contests)} contests)")
            for contest_id in contests[:3]:  # Show first 3
                print(f"   ├─ {contest_id}/")
            if len(contests) > 3:
                print(f"   └─ ... and {len(contests) - 3} more")
            print()

        total = sum(len(c) for c in year_contests.values())
        print(f"Total: {total} contests")
        print("="*60 + "\n")


def main():
    import argparse

    parser = argparse.ArgumentParser(
        description="Organize Codeforces solutions by year"
    )
    parser.add_argument(
        "--execute",
        action="store_true",
        help="Execute the reorganization (default: dry-run)"
    )
    parser.add_argument(
        "--no-git",
        action="store_true",
        help="Use shutil instead of git mv"
    )
    parser.add_argument(
        "--root",
        default=".",
        help="Repository root directory"
    )

    args = parser.parse_args()

    organizer = CodeforcesOrganizer(Path(args.root))

    # Print plan
    organizer.print_summary()

    # Get moves
    moves = organizer.plan_moves(dry_run=True)

    if args.execute:
        print("\n🔄 Executing reorganization...\n")
        organizer.execute_moves(moves, use_git=not args.no_git)
        print("\n✅ Done!")
    else:
        print("\n💡 Run with --execute to apply changes")
        print("   python organize_contests.py --execute\n")


if __name__ == "__main__":
    main()
