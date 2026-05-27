#include "testlib.h"
#include "constraints.h"
#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
 
    int mode = opt<int>("mode", 0);
    int n;
 
    if (mode == 0) {
        n = opt<int>("n", MAXN);
    } else if (mode == 1) {
        int l = opt<int>("l", MINN);
        int r = opt<int>("r", MAXN);
        n = rnd.next(l, r);
    } else {
        quitf(_fail, "unknown mode");
    }
 
    ensuref(MINN <= n && n <= MAXN, "n must be in [%d, %d]", MAXN, MAXN);
 
    int bmode = opt<int>("bmode", 0);
    ll B;
 
    if (bmode == 0) {
        B = opt<ll>("b", MAXB);
    } else if (bmode == 1) {
        ll bl = opt<ll>("bl", MINB);
        ll br = opt<ll>("br", MAXB);
        B = rnd.next(bl, br);
    } else {
        quitf(_fail, "unknown bmode");
    }
 
    ensuref(MINB <= B && B <= MAXB, "B must be in [%d, %d]", MINB, MAXB);
 
    int type = opt<int>("type", 0);
 
    vector<ll> A(n);
 
    if (type == 0) {
        // 완전 랜덤
        for (int i = 0; i < n; i++) {
            A[i] = rnd.next(MINA, MAXA);
        }
    }
    else if (type == 1) {
        // 전부 같은 값
        ll x = rnd.next(MINA, MAXA);
        for (int i = 0; i < n; i++) A[i] = x;
    }
    else if (type == 2) {
        // 작은 값 / 큰 값 번갈아
        ll lowL = MINA;
        ll lowR = MAXA / 10;
        ll highL = MAXA / 10 * 9;
        ll highR = MAXA;
        for (int i = 0; i < n; i++) {
            if (i & 1) A[i] = rnd.next(highL, highR);
            else A[i] = rnd.next(lowL, lowR);
        }
    }
    else if (type == 3) {
        // 앞은 작고, 중간은 중간, 뒤는 큰 값
        int cut1 = n / 3;
        int cut2 = 2 * n / 3;
 
        for (int i = 0; i < cut1; i++) {
            A[i] = rnd.next(MINA, MAXA / 20);
        }
        for (int i = cut1; i < cut2; i++) {
            A[i] = rnd.next(MAXA / 4, MAXA / 2);
        }
        for (int i = cut2; i < n; i++) {
            A[i] = rnd.next(MAXA / 5 * 4, MAXA);
        }
    }
    else if (type == 4) {
        // 특정 값 근처에 몰린 분포
        ll center = rnd.next(MAXA/10, MAXA/10*9);
        ll radius = rnd.next(MAXA/100, MAXA/10);
 
        ensuref(MINA <= center && center <= MAXA, "center must be in [%d, %d]", MINA, MAXA);
        ensuref(MINA <= radius && radius <= MAXA, "radius must be in [%d, %d]", MINA, MAXA);
 
        ll L = max(1ll*MINA, center - radius);
        ll R = min(1ll*MAXA, center + radius);
 
        for (int i = 0; i < n; i++) {
            A[i] = rnd.next(L, R);
        }
    } else if (type == 5) {
        for (int s = 0; s < n; s++) A[s] = MINA;
    } else if (type == 6) {
        for (int s = 0; s < n; s++) A[s] = MAXA;
    }
    else {
        quitf(_fail, "unknown type");
    }
 
    cout << n << ' ' << B << '\n';
    for (int i = 0; i < n; i++) {
        if (i) cout << ' ';
        cout << A[i];
    }
    cout << '\n';
 
    return 0;
}
