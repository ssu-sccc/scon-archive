#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_N = 100'000;
constexpr int MAX_A = 10'000;

int N, M, A[101010], R;

int main(){
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=N; i++) A[i] = max(0, A[i-1] + A[i]);
    assert(*max_element(A+1, A+N+1) != MAX_N * MAX_A);
    for(int i=1; i<=N; i++) R += A[i] >= M;
    cout << R;
}