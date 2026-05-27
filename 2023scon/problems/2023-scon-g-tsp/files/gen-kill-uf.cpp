#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int N = opt<int>("n"), F = opt<int>("flag"), W = opt<int>("w");
    if(F == 0){
        cout << N << " " << N << " " << 1 << "\n";
        for(int i=1; i<N; i++) cout << i << " " << i + 1 << " " << min(W-1, i) << "\n";
        cout << 1 << " " << N << " " << W << "\n";
        for(int i=1; i<=N; i++) cout << i << " \n"[i==N];
    }
    else{
        cout << N << " " << N << " " << 1 << "\n";
        for(int i=1; i<N; i++) cout << N - i << " " << N - i + 1 << " " << min(W-1, i) << "\n";
        cout << 1 << " " << N << " " << W << "\n";
        for(int i=1; i<=N; i++) cout << i << " \n"[i==N];
    }
    return 0;
}