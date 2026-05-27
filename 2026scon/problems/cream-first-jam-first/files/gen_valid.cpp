#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

string make_valid(int len) {
    // len >= 3
    int body = len - 1; // excluding S
    int a = rnd.next(1, body - 1);
    int b = body - a;

    if (rnd.next(0, 1)) {
        return string(a, 'C') + string(b, 'J') + 'S';
    } else {
        return string(a, 'J') + string(b, 'C') + 'S';
    }
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);
    string s;

    while (true) {
        int rem = N - (int)s.size();
        if (rem < 3) break;

        int len = rnd.next(3, min(10, rem));
        s += make_valid(len);
    }

    int rem = N - (int)s.size();
    if (rem == 1) s += 'S';
    else if (rem == 2) s += rnd.next("[CJ]") + 'S';

    println(N);
    println(s);
}