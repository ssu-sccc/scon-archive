#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int max_scone_flavor(int N, int M, int C, int D, vector<int>& optimal_temps) {
    vector<int> prev_dp(M + 1, -1), curr_dp(M + 1, -1);

    for (int k = 1; k <= M; ++k) {
        prev_dp[k] = M - abs(optimal_temps[0] - k);
    }

    for (int t = 1; t < N; ++t) {
        int k_t = optimal_temps[t];
        deque<pair<int, int>> left_dq, right_dq;

        for (int k = 1; k <= M; ++k) {
            while (!left_dq.empty() && left_dq.front().first < k - D) {
                left_dq.pop_front();
            }
            if (prev_dp[k] != -1) {
                while (!left_dq.empty() && left_dq.back().second <= prev_dp[k]) {
                    left_dq.pop_back();
                }
                left_dq.emplace_back(k, prev_dp[k]);
            }

            int max_val = -1;
            if (!left_dq.empty() && (k - left_dq.front().first) % C == 0) {
                max_val = left_dq.front().second;
            }

            while (!right_dq.empty() && right_dq.front().first < k) {
                right_dq.pop_front();
            }
            if (k + D <= M && prev_dp[k + D] != -1) {
                while (!right_dq.empty() && right_dq.back().second <= prev_dp[k + D]) {
                    right_dq.pop_back();
                }
                right_dq.emplace_back(k + D, prev_dp[k + D]);
            }

            if (!right_dq.empty() && (k - right_dq.front().first) % C == 0) {
                max_val = max(max_val, right_dq.front().second);
            }

            if (max_val != -1) {
                curr_dp[k] = max_val + M - abs(k_t - k);
            }
        }

        swap(prev_dp, curr_dp);
        fill(curr_dp.begin(), curr_dp.end(), -1);
    }

    return *max_element(prev_dp.begin(), prev_dp.end());
}

int main() {
    int N, M, C, D;
    cin >> N >> M >> C >> D;

    vector<int> optimal_temps(N);
    for (int i = 0; i < N; ++i) {
        cin >> optimal_temps[i];
    }

    cout << max_scone_flavor(N, M, C, D, optimal_temps) << endl;
    return 0;
}

