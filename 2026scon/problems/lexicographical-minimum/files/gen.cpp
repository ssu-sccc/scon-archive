#include "testlib.h"
#include "constraints.h"
#include <bits/stdc++.h>
using namespace std;
char randLower() {
    return char('a' + rnd.next(0, 25));
}

char randLowerExcept(char ban) {
    char c = randLower();
    while (c == ban) c = randLower();
    return c;
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int mode = opt<int>("mode", 0);
    int n;

    if (mode == 0) {
        n = opt<int>("n", MAXN);
    } else if (mode == 1) {
        int l = opt<int>("l", MINN);
        int r = opt<int>("r", MAXN);
        n = rnd.next(l, r);
    } else {
        quitf(_fail, "unknown mode");
    }

    int type = opt<int>("type", 0);

    string s;

    if (type == 0) {
        s.resize(n);
        for (int i = 0; i < n; i++) s[i] = randLower();
    }
    else if (type == 1) {
        char c = randLower();
        s = string(n, c);
    }
    else if (type == 2) {
        s.resize(n);
        if (n > 0) s[0] = randLower();
        for (int i = 1; i < n; i++) {
            s[i] = randLowerExcept(s[i - 1]);
        }
    }
    else if (type == 3) {
        while ((int)s.size() < n) {
            int len = rnd.next(1, min(10, n - (int)s.size()));
            char c = s.empty() ? randLower() : randLowerExcept(s.back());
            s += string(len, c);
        }
    }
    else {
        quitf(_fail, "unknown type");
    }

    cout << n << '\n' << s << '\n';
    return 0;
}