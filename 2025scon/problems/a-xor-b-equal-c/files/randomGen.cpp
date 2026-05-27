#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;
 
int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int mx = __testlib_opts.count("mx") ? opt<int>("mx") : 3'000;
    int a = 0, b = 0;
    do{
        a = rnd.next(0, mx/2)*2;
        b = rnd.next(0, mx);
    }while((a + b) % 3 != 0 && a + b >= 3);
    cout << a << ' ' << b << endl;
    return 0;
}