#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

ll N, A[202020], B[202020];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) cin >> B[i];
    vector<int> O(N);
    iota(O.begin(), O.end(), 1);
    sort(O.begin(), O.end(), [](int x, int y){
        ld v1 = ld(B[x]) / A[x], v2 = ld(B[y]) / A[y];
        return tie(v1, x) < tie(v2, y);
    });
    cout << O.back();
}