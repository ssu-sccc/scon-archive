#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char* argv[]){
    registerGen(argc, argv, 1);
    int N = opt<int>("n"), L = opt<int>("len");
    int P = rnd.next(1, N);
    
    string S = "-";
    for(int i=0; i<10; i++) S += char(i+'0');
    for(int i=0; i<26; i++) S += char(i+'A');
    for(int i=0; i<26; i++) S += char(i+'a');
    
    cout << N << "\n";
    for(int i=1; i<=N; i++){
        if(i == P) cout << "a123456789\n";
        else{
            for(int j=0; j<20; j++) cout << S[rnd.next(0, (int)S.size()-1)];
            cout << "\n";
        }
    }
    return 0;
}