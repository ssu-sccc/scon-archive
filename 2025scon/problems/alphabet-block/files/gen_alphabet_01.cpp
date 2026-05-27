#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    const int MAX = 100'000'000;
    int nS = rnd.next(0, MAX);
    int nC = rnd.next(0, MAX);
    int nO = rnd.next(0, MAX);
    int nN = rnd.next(0, MAX);
    printf("%d %d %d %d\n", nS, nC, nO, nN);
}