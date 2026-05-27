
#include<bits/stdc++.h>

using namespace std;
using ll = long long;

int A[110];

int main(){
    cin.tie(0)->sync_with_stdio(0);

    int N; cin >> N;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            int x; cin >> x;
            A[x]++;
        }
    }

    ll res = 0;

    for(int i = 100, t = 100, cnt = 0; i > 0 && cnt < 3; i--){
        if(A[i] > 1) continue;
        if(A[i] == 1) {
            cnt++;
            continue;
        }

        if(cnt == 0) res += (--t)*(t-1)/2; 
        else if(cnt == 1) res += (--t-1); 
        else res++; 
    }

    cout << res << "\n";
}