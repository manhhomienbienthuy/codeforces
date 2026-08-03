read -p "Round #: " round
export R=$round

read -p "Is this contest (Y/n)? " yn
if [ $yn = "Y" ] || [ $yn = "y" ]; then
    export T=contest
else
    export T=gym
fi

read -p "Create new folder (Y/n)? " yn
if [ $yn = "Y" ] || [ $yn = "y" ]; then
    mkdir -p "$(date +%Y)/$R"
    cd "$(date +%Y)/$R"
fi

# create C++ template for problem A, B, C, ...
cr() {
    echo "/*!" > $R$1.cpp
    echo " * author: manhhomienbienthuy" >> $R$1.cpp
    echo " * created: $(date -u -Iseconds)" >> $R$1.cpp
    echo " * https://codeforces.com/${T}/${round}/problem/${1^^}" >> $R$1.cpp
    echo " */" >> $R$1.cpp
    echo "" >> $R$1.cpp
    cat ../../template.cpp >> $R$1.cpp
}

# create Python template for problem A, B, C, ...
crp() {
    echo "# author: manhhomienbienthuy" > $R$1.py
    echo "# created: $(date -u -Iseconds)" >> $R$1.py
    echo "# https://codeforces.com/${T}/${round}/problem/${1^^}" >> $R$1.py
    echo "" >> $R$1.py
    cat ../../template.py >> $R$1.py
}

# Run C++ solution for problem A, B, C, ...
run() {
    g++ -Wall -Wextra -Winvalid-pch -Wconversion -static -O2 -std=c++23 $R$1.cpp && ./a.exe < input.txt
}

# git commit
cm() {
    git add -A && git commit -m "$(date -Iseconds)" && git push origin main
}
