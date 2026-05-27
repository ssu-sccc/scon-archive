#include <iostream>
#include <vector>
#include <cmath>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll NEG_INF = -1e18;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M, C, D;
    cin >> N >> M >> C >> D;
    
    // 최적 온도 k_t (t=1~N)
    vector<int> k(N+1);
    for (int t = 1; t <= N; t++){
        cin >> k[t];
    }
    
    // [1, M] 범위 내의 온도를 C로 나눈 나머지(동치류)에 따라 분리
    vector<vector<int>> groups(C);
    for (int x = 1; x <= M; x++){
        int r = x % C; 
        groups[r].push_back(x);
    }
    
    // 한 번에 움직일 수 있는 인덱스 차이의 최대값 (m * C <= D)
    int L = D / C;
    
    // dp[r]는 각 동치류 r에서, 그룹 내 index에 따른 현재까지 맛의 누적 최댓값을 저장합니다.
    vector<vector<ll>> dp(C);
    // t = 1 (초기엔 자유롭게 온도 선택 가능)
    for (int r = 0; r < C; r++){
        int sz = groups[r].size();
        dp[r].resize(sz, NEG_INF);
        for (int j = 0; j < sz; j++){
            int temp = groups[r][j];
            dp[r][j] = (ll) M - abs(k[1] - temp);
        }
    }
    
    // t = 2부터 t = N까지 DP 전개
    for (int t = 2; t <= N; t++){
        vector<vector<ll>> newDp(C);
        for (int r = 0; r < C; r++){
            int sz = groups[r].size();
            if(sz == 0) continue;
            newDp[r].assign(sz, NEG_INF);
            
            // 왼쪽 윈도우 최대값 배열: leftMax[j] = max{ dp[r][i] : i in [max(0,j-L), j] }
            vector<ll> leftMax(sz, NEG_INF);
            deque<int> dq;
            for (int j = 0; j < sz; j++){
                while(!dq.empty() && dq.front() < j - L) dq.pop_front();
                while(!dq.empty() && dp[r][dq.back()] <= dp[r][j]) dq.pop_back();
                dq.push_back(j);
                leftMax[j] = dp[r][dq.front()];
            }
            
            // 오른쪽 윈도우 최대값 배열: rightMax[j] = max{ dp[r][i] : i in [j, min(sz-1,j+L)] }
            vector<ll> rightMax(sz, NEG_INF);
            dq.clear();
            for (int j = sz - 1; j >= 0; j--){
                while(!dq.empty() && dq.front() > j + L) dq.pop_front();
                while(!dq.empty() && dp[r][dq.back()] <= dp[r][j]) dq.pop_back();
                dq.push_back(j);
                rightMax[j] = dp[r][dq.front()];
            }
            
            // 그룹 r의 각 온도에 대해 dp 업데이트  
            // newDp[r][j] = (M - |k[t] - groups[r][j]|) + max( leftMax[j], rightMax[j] )
            for (int j = 0; j < sz; j++){
                ll bestPrev = max(leftMax[j], rightMax[j]);
                newDp[r][j] = bestPrev + ((ll) M - abs(k[t] - groups[r][j]));
            }
        }
        dp = move(newDp);
    }
    
    // 모든 그룹 내에서 최댓값을 최종 답으로 출력
    ll ans = NEG_INF;
    for (int r = 0; r < C; r++){
        for (ll val : dp[r]){
            ans = max(ans, val);
        }
    }
    
    cout << ans << "\n";
    return 0;
}