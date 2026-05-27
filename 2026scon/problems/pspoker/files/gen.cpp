#include "testlib.h"
#include "constraints.h"
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<int,int> gen_random_pair() {
    int A = rnd.next(MIN_A, MAX_A);
    int B = rnd.next(MIN_A, MAX_A);
    return {A, B};
}

// 모든 사람이 같은 비율 B/A 를 갖도록 생성
pair<int,int> gen_same_ratio_pair(int p, int q) {
    int mx = min(MAX_A / p, MAX_A / q);
    int t = rnd.next(1, max(1, mx));
    return {q * t, p * t}; // B/A = p/q
}

// 매우 가까운 비율들을 만들어 부동소수 비교를 망가뜨리기 좋게 생성
pair<int,int> gen_close_ratio_pair() {
    int A = rnd.next(MAX_A - 100000, MAX_A);
    int delta = rnd.next(0, 30);
    int B = A - delta;
    if (B < 1) B = 1;
    return {A, B};
}

// 큰 값 위주 경계 생성
pair<int,int> gen_boundary_pair() {
    int A = rnd.next(MAX_A - 1000, MAX_A);
    int B = rnd.next(MAX_A - 1000, MAX_A);
    return {A, B};
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int mode = opt<int>("mode", 0);
    int n;

    if (mode == 0) {
        n = opt<int>("n", MAX_N);
    } else if (mode == 1) {
        int l = opt<int>("l", MIN_N);
        int r = opt<int>("r", MAX_N);
        n = rnd.next(l, r);
    } else {
        quitf(_fail, "unknown mode");
    }

    if (!(MIN_N <= n && n <= MAX_N)) {
        quitf(_fail, "n must be in [1, %d]", MAX_N);
    }

    int type = opt<int>("type", 0);

    vector<pair<int,int>> v;

    if (type == 0) {
        // 완전 랜덤
        for (int i = 0; i < n; i++) {
            v.push_back(gen_random_pair());
        }
    }
    else if (type == 1) {
        // 모든 비율이 같음 -> tie-break(번호 순) 검사용
        int p = rnd.next(1, 1000);
        int q = rnd.next(1, 1000);
        for (int i = 0; i < n; i++) {
            v.push_back(gen_same_ratio_pair(p, q));
        }
    }
    else if (type == 2) {
        // 매우 가까운 비율들 -> double 정렬 오답 유도
        for (int i = 0; i < n; i++) {
            v.push_back(gen_close_ratio_pair());
        }
    }
    else if (type == 3) {
        // 큰 값 경계 위주
        for (int i = 0; i < n; i++) {
            v.push_back(gen_boundary_pair());
        }
    }
    else if (type == 4) {
        // 일부는 같은 비율, 일부는 랜덤
        int p = rnd.next(1, 1000);
        int q = rnd.next(1, 1000);
        int k = rnd.next(0, n);
        for (int i = 0; i < k; i++) {
            v.push_back(gen_same_ratio_pair(p, q));
        }
        for (int i = k; i < n; i++) {
            v.push_back(gen_random_pair());
        }
        shuffle(v.begin(), v.end());
    }
    else if (type == 5) {
        // 작은 분모/분자 기반 비율들 많이 생성
        // 중복 ratio가 꽤 자주 나오게 함
        vector<pair<int,int>> fracs;
        for (int x = 1; x <= 20; x++) {
            for (int y = 1; y <= 20; y++) {
                int g = gcd(x, y);
                fracs.push_back({x / g, y / g}); // ratio = x/y
            }
        }
        for (int i = 0; i < n; i++) {
            auto [p, q] = fracs[rnd.next(0, (int)fracs.size() - 1)];
            v.push_back(gen_same_ratio_pair(p, q));
        }
    } else if (type == 6) {
        int op1 = opt<int>("op1", 0);
        int op2 = opt<int>("op2", 0);
        v.resize(n);
        for (int s = 0; s < n; s++) v[s].first = (op1 ? 1 : MAX_A);
        for (int s = 0; s < n; s++) v[s].second = (op2 ? 1 : MAX_A);
    }
    else {
        quitf(_fail, "unknown type");
    }

    cout << n << '\n';
    for (int i = 0; i < n; i++) cout << v[i].first << " \n"[i==n-1];
    for (int i = 0; i < n; i++) cout << v[i].second << " \n"[i==n-1];
    
    return 0;
}