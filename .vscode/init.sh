read -p "Round #: " round
export R=$round

# create C++ template for problem A, B, C, ...
cr() {
    echo "/*!" > $R$1.cpp
    echo " * author: manhhomienbienthuy" >> $R$1.cpp
    echo " * created: $(date -u -Iseconds)" >> $R$1.cpp
    echo " * https://codeforces.com/contest/${round}/problem/${1^^}" >> $R$1.cpp
    echo " */" >> $R$1.cpp
    echo "" >> $R$1.cpp
    echo "#ifdef ONLINE_JUDGE" >> $R$1.cpp
    echo "#pragma GCC optimize(\"Ofast,unroll-loops\")" >> $R$1.cpp
    echo "#endif" >> $R$1.cpp
    echo "" >> $R$1.cpp
    echo "#include <bits/stdc++.h>" >> $R$1.cpp
    echo "using namespace std;" >> $R$1.cpp
    echo "" >> $R$1.cpp
    echo "int main() {" >> $R$1.cpp
    echo "  ios::sync_with_stdio(false);" >> $R$1.cpp
    echo "  cin.tie(nullptr);" >> $R$1.cpp
    echo "" >> $R$1.cpp
    echo "  int t;" >> $R$1.cpp
    echo "  cin >> t;" >> $R$1.cpp
    echo "  while (t--) {" >> $R$1.cpp
    echo "    int n;" >> $R$1.cpp
    echo "    cin >> n;" >> $R$1.cpp
    echo "    vector<int> a(n);" >> $R$1.cpp
    echo "    for (int i = 0; i < n; i++) cin >> a[i];" >> $R$1.cpp
    echo "  }" >> $R$1.cpp
    echo "" >> $R$1.cpp
    echo "  return 0;" >> $R$1.cpp
    echo "}" >> $R$1.cpp

}

# create Python template for problem A, B, C, ...
crp() {
    echo "# author: manhhomienbienthuy" > $R$1.py
    echo "# created: $(date -u -Iseconds)" >> $R$1.py
    echo "# https://codeforces.com/contest/${round}/problem/${1^^}" >> $R$1.py
    echo "" >> $R$1.py
    echo "import sys" >> $R$1.py
    echo "input = sys.stdin.readline" >> $R$1.py
    echo "" >> $R$1.py
    echo "t = int(input())" >> $R$1.py
    echo "for _ in range(t):" >> $R$1.py
    echo "    n = int(input())" >> $R$1.py
    echo "    a = list(map(int, input().split()))" >> $R$1.py

}

run() {
    g++ -Wall -Wextra -Winvalid-pch -Wconversion -static -O2 -std=c++23 $1 && ./a.exe < input.txt
}

cm() {
    git add -A && git commit -m "$(date -Iseconds)" && git push origin main
}
