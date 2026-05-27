#include "testlib.h"
#include <bits/stdc++.h>
#define MAX 1'000'000
using namespace std;
 
int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int mn = __testlib_opts.count("mn") ? opt<int>("mn") : 0;

    int n = __testlib_opts.count("n") ? opt<int>("n") : rnd.next(1, MAX);
    println(n);
    
    vector<int> A(n), B(n);
    for(int &i:A) i = rnd.next(0, 1);
    println(A);

    for(int &i:B) i = rnd.next(mn, MAX);
    println(B);

    return 0;
}