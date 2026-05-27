#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

string make_valid(int len) {
    int body = len - 1;
    int a = rnd.next(1, body - 1);
    int b = body - a;

    if (rnd.next(0, 1)) {
        return string(a, 'C') + string(b, 'J') + 'S';
    } else {
        return string(a, 'J') + string(b, 'C') + 'S';
    }
}

string make_invalid(int len) {
    int body = len - 1;

    int mode = rnd.next(0, 3);

    if (mode == 0) {
        return string(body, 'C') + 'S';
    }
    if (mode == 1) {
        return string(body, 'J') + 'S';
    }
    if (mode == 2 && body >= 3) {
        int a = rnd.next(1, body - 2);
        int b = rnd.next(1, body - a - 1);
        int c = body - a - b;
        return string(a, 'C') + string(b, 'J') + string(c, 'C') + 'S';
    }
    if (body >= 3) {
        int a = rnd.next(1, body - 2);
        int b = rnd.next(1, body - a - 1);
        int c = body - a - b;
        return string(a, 'J') + string(b, 'C') + string(c, 'J') + 'S';
    }

    // len=3이면 위 3블록이 어려우니 단일 토핑만
    return string(body, rnd.next(0, 1) ? 'C' : 'J') + 'S';
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);
    string s;

    while (true) {
        int rem = N - (int)s.size();
        if (rem < 3) break;

        int len = rnd.next(3, min(10, rem));
        if (rnd.next(0, 1)) s += make_valid(len);
        else s += make_invalid(len);
    }

    int rem = N - (int)s.size();
    if (rem == 1) s += 'S';
    else if (rem == 2) s += rnd.next("[CJ]") + 'S';

    println(N);
    println(s);
}