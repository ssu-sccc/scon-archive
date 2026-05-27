#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
using namespace std;

using ll = long long;

static const int BAD_TYPE = 6; 

ll n, B;
vector<ll> A;

bool jud_bad1(ll x) {
    // 죽는 순간 현재 이벤트를 패치
    ll c = 0, cost = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] >= x) {
            c++;
        } else {
            c--;
            if (c < 0) {
                cost += x - A[i];
                if (cost > B) return false;
                c += 2;
            }
        }
    }
    return true;
}

bool jud_bad2(ll x) {
    // 죽는 순간 가장 오래된 reject를 패치
    ll c = 0, cost = 0;
    queue<ll> q; // cost = x - A[i]
    for (int i = 1; i <= n; i++) {
        if (A[i] >= x) {
            c++;
        } else {
            c--;
            q.push(x - A[i]);
            if (c < 0) {
                if (q.empty()) return false;
                cost += q.front();
                q.pop();
                if (cost > B) return false;
                c += 2;
            }
        }
    }
    return true;
}

bool jud_bad3(ll x) {
    // 전역 cheapest reject부터 예산 안에서 최대한 많이 패치
    vector<pair<ll,int>> V; // {cost, idx}
    for (int i = 1; i <= n; i++) {
        if (A[i] < x) V.push_back({x - A[i], i});
    }
    sort(all(V));

    vector<int> patched(n + 1, 0);
    ll cost = 0;
    for (auto [w, idx] : V) {
        if (cost + w <= B) {
            cost += w;
            patched[idx] = 1;
        }
    }

    ll c = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] >= x || patched[i]) c++;
        else c--;
        if (c < 0) return false;
    }
    return true;
}

bool jud_bad4(ll x) {
    // 죽는 순간 가장 작은 A_i 를 패치
    // = cost가 가장 큰 reject를 패치
    ll c = 0, cost = 0;
    priority_queue<ll> pq; // biggest cost first
    for (int i = 1; i <= n; i++) {
        if (A[i] >= x) {
            c++;
        } else {
            c--;
            pq.push(x - A[i]);
            if (c < 0) {
                if (pq.empty()) return false;
                cost += pq.top();
                pq.pop();
                if (cost > B) return false;
                c += 2;
            }
        }
    }
    return true;
}

bool jud_bad5(ll x) {
    // prefix는 무시하고 최종 credit만 0 이상이면 된다고 생각
    ll base = 0;
    vector<ll> costs;
    for (int i = 1; i <= n; i++) {
        if (A[i] >= x) base++;
        else {
            base--;
            costs.push_back(x - A[i]);
        }
    }

    if (base >= 0) return true;

    ll need = (-base + 1) / 2; 
    if ((ll)costs.size() < need) return false;

    sort(all(costs));
    ll cost = 0;
    for (int i = 0; i < need; i++) {
        cost += costs[i];
        if (cost > B) return false;
    }
    return true;
}

bool jud_bad6(ll x) {
    // credit이 0이 될 것 같으면 미리 패치
    ll c = 0, cost = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] >= x) {
            c++;
        } else {
            if (c == 1) {
                // reject 처리하면 0이 되므로 미리 패치
                cost += x - A[i];
                if (cost > B) return false;
                c++;
            } else {
                c--;
                if (c < 0) return false;
            }
        }
    }
    return true;
}

bool jud_bad7(ll x) {
    // 예산이 허락하면 싼 reject는 즉시 패치
    ll c = 0, cost = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] >= x) {
            c++;
        } else {
            ll w = x - A[i];
            if (cost + w <= B) {
                cost += w;
                c++;
            } else {
                c--;
                if (c < 0) return false;
            }
        }
    }
    return true;
}

bool jud(ll x) {
    if (BAD_TYPE == 1) return jud_bad1(x);
    if (BAD_TYPE == 2) return jud_bad2(x);
    if (BAD_TYPE == 3) return jud_bad3(x);
    if (BAD_TYPE == 4) return jud_bad4(x);
    if (BAD_TYPE == 5) return jud_bad5(x);
    if (BAD_TYPE == 6) return jud_bad6(x);
    if (BAD_TYPE == 7) return jud_bad7(x);
    return false;
}

void solve() {
    cin >> n >> B;
    A.assign(n + 1, 0);
    for (int i = 1; i <= n; i++) cin >> A[i];

    ll mx = 0;
    for (int i = 1; i <= n; i++) mx = max(mx, A[i]);

    ll l = 0, r = mx + B + 1;
    while (l + 1 < r) {
        ll m = (l + r) >> 1;
        if (jud(m)) l = m;
        else r = m;
    }
    cout << l << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}