#!/usr/bin/env python3

lucky = input()
bin_lucky = "1" + lucky.replace("4", "0").replace("7", "1")
print(int(bin_lucky, 2) - 1)
