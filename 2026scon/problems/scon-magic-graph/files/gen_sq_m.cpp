#include "testlib.h"
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <set>

using namespace std;

int main(int argc, char* argv[]) {
    // Polygon 제너레이터 초기화
    registerGen(argc, argv, 1);

    int n = has_opt("n") ? opt<int>("n") : rnd.next(1, 100000);
    int q = has_opt("q") ? opt<int>("q") : rnd.next(1, 100000);

    // 1. 최대 K 찾기 (K개의 허브가 1...K 차수를 가지기 위해 필요한 최소 정점 수 <= n)
    int K = 0;
    while (1 + (K + 1) + 1LL * (K + 1) * K / 2 <= n) {
        K++;
    }

    vector<pair<int, int>> edges;
    int center = 1;
    int nxt_vertex = 2;
    vector<int> hubs;

    // 2. 허브 정점 생성 및 Center(1번 정점)에 연결
    for (int i = 1; i <= K; i++) {
        int hub = nxt_vertex++;
        hubs.push_back(hub);
        edges.push_back({center, hub}); // 허브와 센터 연결 (차수 1 확보)
        
        // 허브가 정확히 i의 차수를 가지도록 더미(Leaf) 정점 연결
        for (int j = 0; j < i - 1; j++) {
            int leaf = nxt_vertex++;
            edges.push_back({hub, leaf});
        }
    }
    
    // 3. 남은 정점들끼리 랜덤 그래프(컴포넌트) 생성
    vector<int> rem;
    while (nxt_vertex <= n) {
        rem.push_back(nxt_vertex);
        nxt_vertex++;
    }

    if (!rem.empty()) {
        // 남은 컴포넌트를 메인 그래프(Center)와 연결하여 단절되지 않게 함
        // (주의: 허브에 연결하면 허브의 차수가 망가지므로 반드시 Center에 연결)
        edges.push_back({center, rem[0]});
        
        set<pair<int, int>> used_rem_edges;

        // 3-1. 남은 정점들끼리 랜덤 트리 생성 (연결성 보장)
        for (int i = 1; i < (int)rem.size(); ++i) {
            int u = rem[i];
            int v = rem[rnd.next(0, i - 1)]; // 이전에 추가된 정점 중 랜덤 선택
            edges.push_back({u, v});
            
            if (u > v) swap(u, v);
            used_rem_edges.insert({u, v});
        }

        // 3-2. 남은 정점들 사이에 랜덤 간선 추가 (최대 제한인 20만 개를 넘지 않는 선에서)
        int current_m = edges.size();
        int max_extra = 200000 - current_m;
        long long possible_extra = 1LL * rem.size() * (rem.size() - 1) / 2 - (rem.size() - 1);
        
        if (max_extra > 0 && possible_extra > 0) {
            // 적당한 양의 추가 간선을 랜덤하게 삽입 (정점 수의 약 2배 정도)
            int extra = rnd.next(0, (int)min((long long)max_extra, min(possible_extra, (long long)rem.size() * 2)));
            int attempts = 0;
            
            while (extra > 0 && attempts < extra * 5) {
                attempts++;
                int u = rem[rnd.next(0, (int)rem.size() - 1)];
                int v = rem[rnd.next(0, (int)rem.size() - 1)];
                
                if (u == v) continue;
                if (u > v) swap(u, v);
                if (used_rem_edges.count({u, v})) continue;
                
                used_rem_edges.insert({u, v});
                edges.push_back({u, v});
                extra--;
            }
        }
    }

    // 4. 생성된 간선 수 M 확정
    int final_m = edges.size();
    cout << n << " " << final_m << " " << q << "\n";

    // 5. Permutation 적용 (정점 번호 완전히 섞기)
    vector<int> p(n);
    iota(p.begin(), p.end(), 1);
    shuffle(p.begin(), p.end());

    for(auto e : edges) {
        int u = p[e.first - 1];
        int v = p[e.second - 1];
        if(rnd.next(0, 1)) swap(u, v); // 방향도 섞음
        cout << u << " " << v << "\n";
    }

    // 6. 쿼리 생성 (1번과 2번 쿼리 번갈아가며 생성)
    int target_d = 1;
    for (int i = 0; i < q; ++i) {
        if (i % 2 == 0) {
            // 1번 쿼리 (마나 주입)
            int u = rnd.next(1, n);
            int x = rnd.next(1, 100000000); // MAX_X = 10^8
            cout << 1 << " " << u << " " << x << "\n";
        } else {
            // 2번 쿼리 (차수 d 공명 발현)
            int d;
            if (K > 0) {
                d = target_d;
                target_d++;
                if (target_d > K) target_d = 1; // 1...K 무한 반복 찌르기
            } else {
                d = 0;
            }
            cout << 2 << " " << d << "\n";
        }
    }

    return 0;
}