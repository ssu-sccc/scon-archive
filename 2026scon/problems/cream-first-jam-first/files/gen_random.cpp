#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);
    string s;

    for (int i = 0; i < N - 1; i++) {
        s += rnd.next("[CJS]");
    }
    s += 'S';

    println(N);
    println(s);
}