#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll N, A[202020], B[202020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) cin >> B[i];
    vector<int> O(N);
    iota(O.begin(), O.end(), 1);
    sort(O.begin(), O.end(), [](int x, int y){
        ll sgn = B[x] * A[y] - A[x] * B[y];
        return sgn ? sgn < 0 : x < y;
    });
    cout << O.back();
}