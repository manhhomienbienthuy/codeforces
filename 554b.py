#!/usr/bin/env python3

room = [input() for _ in range(int(input()))]
print(max(room.count(el) for el in room))
