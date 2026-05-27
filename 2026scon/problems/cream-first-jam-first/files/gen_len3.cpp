#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int N = atoi(argv[1]);
    string s;

    while ((int)s.size() + 3 <= N) {
        s += rnd.next("[CJ]") + "S";
    }

    int rem = N - (int)s.size();
    if (rem == 1) s += 'S';
    else if (rem == 2) s += (rnd.next("[CJ]") + 'S');

    println(N);
    println(s);
}