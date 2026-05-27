#include <bits/stdc++.h>
using namespace std;

int N, A[1010];
vector<int> Same, Diff;

void Reverse(){ reverse(A+1, A+N+1); }
void Flip(){ for(int i=1; i<=N; i++) if(A[i] != -1) A[i] ^= 1; }

int Ask(int x){
    cout << "? " << x << endl;
    int res; cin >> res; return res;
}

void Get(int x){
    A[x] = Ask(x);
    A[N-x+1] = Ask(N-x+1);
    if(A[x] == A[N-x+1]) Same.push_back(x);
    else Diff.push_back(x);
}

void Balance(){
    if(Diff.empty()){
        int x = Ask(Same[0]); Ask(Same[0]);
        if(A[Same[0]] != x) Flip();
    }
    else if(Same.empty()){
        int x = Ask(Diff[0]); Ask(Diff[0]);
        if(A[Diff[0]] != x) Flip();
    }
    else{
        bool x = Ask(Same[0]) == A[Same[0]];
        bool y = Ask(Diff[0]) == A[Diff[0]];
        if(x && !y) Reverse();
        if(!x && y) Reverse(), Flip();
        if(!x && !y) Flip();
    }
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    memset(A, -1, sizeof A);
    for(int i=1, cnt=0; i<=N/2; i++){
        Get(i); cnt++;
        if(cnt == 5) Balance(), cnt = 1;
    }
    if(N % 2 == 1) A[N/2+1] = Ask(N/2+1);
    cout << "! ";
    for(int i=1; i<=N; i++) cout << A[i] << " ";
}