run() {
    g++ $1 && ./a.exe < ../input.txt
}

read -p "Roud #: " round

# create template for problem A, B, C
cr() {
    echo "/*!" > $round$1.cpp
    echo " * author: manhhomienbienthuy" >> $round$1.cpp
    echo " * created: $(date -u -Iseconds)" >> $round$1.cpp
    echo " * https://codeforces.com/contest/${round}/problem/${1^^}" >> $round$1.cpp
    echo " */" >> $round$1.cpp
    echo "" >> $round$1.cpp
    echo "#include <bits/stdc++.h>" >> $round$1.cpp
    echo "using namespace std;"  >> $round$1.cpp
    echo ""  >> $round$1.cpp
    echo "int main() {"  >> $round$1.cpp
    echo "    ios::sync_with_stdio(false);"  >> $round$1.cpp
    echo "    cin.tie(nullptr);"  >> $round$1.cpp
    echo ""  >> $round$1.cpp
    echo "    int t;"  >> $round$1.cpp
    echo "    cin >> t;"  >> $round$1.cpp
    echo "    while (t--) {"  >> $round$1.cpp
    echo "        int n;"  >> $round$1.cpp
    echo "        cin >> n;"  >> $round$1.cpp
    echo "        vector<int> a(n);"  >> $round$1.cpp
    echo "        for (int i = 0; i < n; i++) cin >> a[i];"  >> $round$1.cpp
    echo "    }"  >> $round$1.cpp
    echo ""  >> $round$1.cpp
    echo "    return 0;"  >> $round$1.cpp
    echo "}"  >> $round$1.cpp
}
