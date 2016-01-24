#!/usr/bin/env python3

import re

length = int(input())
sample = input()

reg_search = ["vaporeon", "jolteon", "flareon",
              "espeon", "umbreon", "leafeon", "glaceon", "sylveon"]

for element in reg_search:
    if len(element) == length and re.search(sample, element):
        print(element)
