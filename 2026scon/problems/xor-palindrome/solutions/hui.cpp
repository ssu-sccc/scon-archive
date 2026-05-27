#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr ll MOD = 1e9+7;

template<typename T>
struct xor_basis{
    vector<T> basis; int cnt;
    xor_basis() : basis(), cnt(0) {}
    void add(T x){ cnt++;
        for(int i=(int)basis.size()-1; i>=0; i--) x = min(x, basis[i]^x);
        if(x) basis.insert(lower_bound(basis.begin(), basis.end(), x), x);
    }
    T maximize(T r=T(0)) const {
        for(int i=(int)basis.size()-1; i>=0; i--) r = max(r, r^basis[i]);
        return r;
    }
    T minimize(T r=T(0)) const {
        for(int i=(int)basis.size()-1; i>=0; i--) r = min(r, r^basis[i]);
        return r;
    }
    int rank() const { return basis.size(); }
    bool contains(T x) const {
        if(x == 0) return rank() < cnt;
        for(int i=(int)basis.size()-1; i>=0; i--) x = min(x, basis[i]^x);
        return x == 0;
    }
};

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int N, M; cin >> N >> M;
    xor_basis<int> X;
    for(int i=1; i<=N; i++){
        string s; cin >> s;
        int now = 0;
        for(int j=0; j<M/2; j++) if(s[j] != s[M-j-1]) now |= 1 << j;
        X.add(now);
    }
    if(!X.contains(0)){ cout << 0; return 0; }
    ll res = 1;
    for(int i=0; i<N-X.rank(); i++) res = res * 2 % MOD;
    cout << res - 1;
}