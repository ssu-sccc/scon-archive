#include "testlib.h"
#include "constraints.h"
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int mode = opt<int>("mode", 0);
    int odd = opt<int>("odd", 0);
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
    
    if (odd == 1) {
        if (~n & 1) n--;
    }    
    

    
    int type = opt<int>("type", 0);
    vector<int> a(n + 1);

    if (type == 0) {
        // 완전 랜덤
        for (int i = 1; i <= n; i++) {
            a[i] = rnd.next(0, 1);
        }
    }
    else if (type == 1) {
        // 전부 같은 값
        int x = rnd.next(0, 1);
        for (int i = 1; i <= n; i++) a[i] = x;
    }
    else if (type == 2) {
        // 번갈아 나옴
        int st = rnd.next(0, 1);
        for (int i = 1; i <= n; i++) {
            a[i] = st ^ ((i - 1) & 1);
        }
    }
    else if (type == 3) {
        // palindrome
        for (int i = 1; i <= (n + 1) / 2; i++) {
            a[i] = rnd.next(0, 1);
            a[n + 1 - i] = a[i];
        }
    }
    else if (type == 4) {
        // anti-palindrome: a[i] != a[n+1-i]
        for (int i = 1; i <= n / 2; i++) {
            a[i] = rnd.next(0, 1);
            a[n + 1 - i] = a[i] ^ 1;
        }
    }
    else if (type == 5) {
        // 긴 블록들
        int cur = rnd.next(0, 1);
        int i = 1;
        while (i <= n) {
            int len = rnd.next(1, min(20, n - i + 1));
            for (int j = 0; j < len; j++) a[i + j] = cur;
            i += len;
            cur ^= rnd.next(0, 1); // 가끔 유지, 가끔 뒤집기
        }
    }
    else if (type == 6) {
        // 0이 많고 1이 적은 케이스
        for (int i = 1; i <= n; i++) {
            a[i] = (rnd.next(1, 10) == 1);
        }
    }
    else if (type == 7) {
        // 1이 많고 0이 적은 케이스
        for (int i = 1; i <= n; i++) {
            a[i] = (rnd.next(1, 10) != 1);
        }
    }
    else {
        quitf(_fail, "unknown type");
    }
    vector<int> change_sq (133);
    for (int &i : change_sq) i = rnd.next(0, 3);
    cout << n << '\n';
    for (int i = 1; i <= n; i++) cout << a[i] << " \n"[i == n];
    for (int s = 0; s < 133; s++) cout << change_sq[s] << " \n"[s == 132];
    
    return 0;
}