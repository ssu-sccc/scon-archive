#include <bits/stdc++.h>
using namespace std;
using ll=long long;

ll N, K, A[1010101], S[1010101], D[1010101][2];

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N >> K;
    for(int i=1;i<=N;i++) cin >> A[i];
    for(int i=1;i<=N+K;i++) S[i]=S[i-1]+A[i];

    for(int i=1;i<=N+K;i++) {
        D[i][0]=max(D[i-1][0],D[i-1][1]);
        D[i][1]=D[i-1][1]+A[i];
        if(i>=K) D[i][1]=max(D[i][1], D[i-K][0]+S[i]-S[i-K]);
    }
    cout << max(D[N+K][0],D[N+K][1]);
    return 0;
}