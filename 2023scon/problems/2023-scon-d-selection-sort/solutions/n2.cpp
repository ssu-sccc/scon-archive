#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int SZ = 500'000;

int N, A[SZ+1];
long long R[SZ+1];

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++){
        int j = find(A+1, A+N+1, i) - A;
        R[A[i]] += abs(i - j);
        R[A[j]] += abs(i - j);
        swap(A[i], A[j]);
    }
    for(int i=1; i<=N; i++) cout << R[i] << " \n"[i==N];
}