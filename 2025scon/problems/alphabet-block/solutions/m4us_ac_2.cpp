#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    int s,c,o,n; cin >> s >> c >> o >> n;
    int dap=0;
    // scon sccc
    while(1) {
        int ss = s - 2*dap, cc = c - 4*dap, oo = o - dap, nn = n - dap;

        // s and n are convertable
        if(ss + nn < 0) {
            break;
        }

        // c and o ar convertable
        if(cc + 2*oo < 0) {
            break;
        }

        dap++;
    }
    cout << dap-1;
    return 0;
}