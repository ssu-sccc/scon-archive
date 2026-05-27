#include "testlib.h"
#include <bits/stdc++.h>
#define MAX 1'000'000
using namespace std;
 
int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int op = __testlib_opts.count("one") ? 0 : 1;

    int n = rnd.next(1, MAX);
    println(n);
    
    vector<int> A(n), B(n);
    for(int &i:A) i = op;
    println(A);

    for(int &i:B) i = rnd.next(0, MAX);
    println(B);

    return 0;
}