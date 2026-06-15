run() {
    g++ $1
    ./a.exe < input.txt
}

cr() {
    echo "/*!" > $R$1.cpp
    echo " * author: manhhomienbienthuy" >> $R$1.cpp
    echo " * created: $(date -u -Iseconds)" >> $R$1.cpp
    echo " */" >> $R$1.cpp
    echo "" >> $R$1.cpp
    echo "#include <bits/stdc++.h>" >> $R$1.cpp
    echo "using namespace std;"  >> $R$1.cpp
    echo ""  >> $R$1.cpp
    echo "using ll = long long;"  >> $R$1.cpp
    echo ""  >> $R$1.cpp
    echo "int main()"  >> $R$1.cpp
    echo "{"  >> $R$1.cpp
    echo "    ios::sync_with_stdio(false);"  >> $R$1.cpp
    echo "    cin.tie(nullptr);"  >> $R$1.cpp
    echo ""  >> $R$1.cpp
    echo "    int t;"  >> $R$1.cpp
    echo "    cin >> t;"  >> $R$1.cpp
    echo "    while (t--) {"  >> $R$1.cpp
    echo "        int n;"  >> $R$1.cpp
    echo "        cin >> n;"  >> $R$1.cpp
    echo "        vector<int> a(n);"  >> $R$1.cpp
    echo "        for (int i = 0; i < n; i++) cin >> a[i];"  >> $R$1.cpp
    echo "    }"  >> $R$1.cpp
    echo ""  >> $R$1.cpp
    echo "    return 0;"  >> $R$1.cpp
    echo "}"  >> $R$1.cpp
}
