#include <bits/stdc++.h>
using namespace std;

int N, M, C, D, A[202], dp[202][25252];
deque<int> Q[25252];
int f(int i, int j){ return M - abs(A[i] - j); }

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M >> C >> D;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=M; i++) dp[1][i] = f(1, i);
    for(int i=2; i<=N; i++){
        for(int j=1; j<=M; j++){
            int m = j % C;
            while(!Q[m].empty() && j - Q[m].front() > D) Q[m].pop_front();
            while(!Q[m].empty() && dp[i-1][Q[m].front()] <= dp[i-1][j]) Q[m].pop_front();
            Q[m].push_back(j);
            dp[i][j] = max(dp[i][j], dp[i-1][Q[m].front()] + f(i, j));
        }
        for(int j=M; j>=1; j--){
            int m = j % C;
            while(!Q[m].empty() && Q[m].front() - j > D) Q[m].pop_front();
            while(!Q[m].empty() && dp[i-1][Q[m].front()] <= dp[i-1][j]) Q[m].pop_front();
            Q[m].push_back(j);
            dp[i][j] = max(dp[i][j], dp[i-1][Q[m].front()] + f(i, j));
        }
    }
    cout << *max_element(dp[N]+1, dp[N]+M+1);
}