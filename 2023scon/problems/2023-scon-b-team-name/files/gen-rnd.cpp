#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int len = opt<int>("len");
    int ord1 = opt<int>("ord1");
    int ord2 = opt<int>("ord2");

    vector<int> P(3), Y(3);
    vector<string> S(3);
    for(int i=0; i<3; i++) P[i] = rnd.next(6666 * i + 1, 6666 * (i + 1));
    for(int i=0; i<3; i++) Y[i] = 2010 + rnd.next(30 * i, 30 * i + 29);
    for(int i=0; i<3; i++) for(int j=0; j<len; j++) S[i] += rnd.next(0, 25) + 'A';
    if(len == 1) S = {"A", "B", "C"};
    if(len == 2) S = {"AB", "CD", "EF"};

    for(int i=0; i<ord1; i++) next_permutation(P.begin(), P.end());
    for(int i=0; i<ord2; i++) next_permutation(Y.begin(), Y.end());

    for(int i=0; i<3; i++) cout << P[i] << " " << Y[i] << " " << S[i] << "\n";

    return 0;
}