#include "testlib.h"
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    const int MAX_N = 100000;
    const int MAX_M = 200000;
    const int MAX_Q = 100000;
    const int MAX_X = 100'000'000;

    // 1. N 설정 (-n 옵션 확인, 없으면 랜덤)
    // M이 0이 될 수 있으므로 N은 이제 1부터 가능합니다.
    int n = has_opt("n") ? opt<int>("n") : rnd.next(1, MAX_N);

    // 2. M 설정 (-m 옵션 확인, 없으면 랜덤)
    long long max_possible_m = 1LL * n * (n - 1) / 2;
    int m;
    if (has_opt("m")) {
        m = opt<int>("m");
        // M은 0 이상, 최대 가능 간선 수 이하로 보정
        m = max(0LL, min((long long)m, max_possible_m)); 
    } else {
        // M을 0부터 랜덤하게 생성
        m = rnd.next(0LL, min((long long)MAX_M, max_possible_m));
    }

    // 3. Q 설정 (-q 옵션 확인, 없으면 랜덤)
    int q = has_opt("q") ? opt<int>("q") : rnd.next(1, MAX_Q);

    cout << n << " " << m << " " << q << "\n";

    // 4. 마나 회로(간선) 생성 (단순 그래프 보장)
    if (m > 0) {
        if (max_possible_m <= 5000000 && m > max_possible_m / 2) {
            // N이 작고 꽉 찬 그래프(Dense Graph)에 가까울 때 TLE 방지
            vector<pair<int, int>> all_edges;
            for (int i = 1; i <= n; ++i) {
                for (int j = i + 1; j <= n; ++j) {
                    all_edges.push_back({i, j});
                }
            }
            shuffle(all_edges.begin(), all_edges.end());
            for (int i = 0; i < m; ++i) {
                int u = all_edges[i].first;
                int v = all_edges[i].second;
                if (rnd.next(0, 1)) swap(u, v);
                cout << u << " " << v << "\n";
            }
        } else {
            // 일반적인 희소 그래프(Sparse Graph)
            set<pair<int, int>> edges;
            for (int i = 0; i < m; ++i) {
                int u, v;
                do {
                    u = rnd.next(1, n);
                    v = rnd.next(1, n);
                    if (u > v) swap(u, v);
                } while (u == v || edges.count({u, v}));
                
                edges.insert({u, v});
                if (rnd.next(0, 1)) swap(u, v);
                cout << u << " " << v << "\n";
            }
        }
    }

    // 5. 조작(쿼리) 생성
    for (int i = 0; i < q; ++i) {
        int type = rnd.next(1, 2);
        if (type == 1) {
            int u = rnd.next(1, n);
            int x = rnd.next(1, MAX_X);
            cout << type << " " << u << " " << x << "\n";
        } else {
            int d = rnd.next(0, n - 1);
            cout << type << " " << d << "\n";
        }
    }

    return 0;
}