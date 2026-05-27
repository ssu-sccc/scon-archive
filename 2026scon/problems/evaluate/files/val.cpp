#include "testlib.h"
#include "constraints.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);
 
 
    int N = inf.readInt(MINN, MAXN, "N");
    inf.readSpace();
    inf.readInt(MINB, MAXB, "B");
    inf.readEoln();
 
    
    inf.readLongs(N, MINA, MAXA, "A");
    inf.readEoln();
 
    inf.readEof();
    return 0;
}
