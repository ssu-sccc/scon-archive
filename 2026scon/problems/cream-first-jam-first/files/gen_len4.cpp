#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);
    string s;

    while ((int)s.size() + 4 <= N) {
        s += rnd.next("[CJ][CJ][CJ]") + "S";
    }

    int rem = N - (int)s.size();
    if (rem == 0);
    else if (rem == 1) s += 'S';
    else {
        for (int i = 0; i < rem - 1; i++) {
            s += rnd.next("[CJ]");
        }
        s += 'S';
    }

    println(N);
    println(s);
}