#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int n = opt<int>("n"), a = opt<int>("a");
    cout << n << "\n";
    for(int i=1; i<=n; i++) cout << a << " \n"[i==n];
    return 0;
}