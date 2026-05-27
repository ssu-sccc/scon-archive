#include "testlib.h"
#include "koosaga-bigint.h"
#include <bits/stdc++.h>
using namespace std;

BigInt D[2020];

bool IsUnique(vector<int> a, vector<int> b){
    vector<int> v;
    v.insert(v.end(), a.begin(), a.end());
    v.insert(v.end(), b.begin(), b.end());

    sort(v.begin(), v.end());
    return unique(v.begin(), v.end()) == v.end();
}

int Check(int n, InStream &in){
    int x = in.readInt(1, n, "X");
    vector<int> a = in.readInts(x, 1, n, "A");
    int y = in.readInt(1, n, "Y");
    vector<int> b = in.readInts(y, 1, n, "B");
    if(!IsUnique(a, b)) in.quitf(_wa, "not unique");

    BigInt A = 0, B = 0;
    for(auto i : a) A += D[i];
    for(auto i : b) B += D[i];
    if(A != B) in.quitf(_wa, "not equal");

    if(n % 3 == 0 && x + y < n) in.quitf(_wa, "less");
    if(n % 3 == 2 && x + y < n) in.quitf(_wa, "less");
    if(n % 3 == 1 && x + y < n - 1) in.quitf(_wa, "less");

    return x + y;
}

int main(int argc, char* argv[]){
    registerTestlibCmd(argc, argv);
    D[1] = D[2] = 1;
    for(int i=3; i<=2000; i++) D[i] = D[i-1] + D[i-2];

    int n = inf.readInt();
    int ans_cnt = Check(n, ans);
    int out_cnt = Check(n, ouf);

    if(out_cnt < ans_cnt) quitf(_wa, "less");
    if(out_cnt > ans_cnt) quitf(_fail, "more");

    quitf(_ok, "ok");
    return 0;
}