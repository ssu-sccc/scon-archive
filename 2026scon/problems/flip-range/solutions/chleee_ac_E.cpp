#include <bits/stdc++.h>

using namespace std;
bool cnt1[202020], cnt2[202020];
int main() {
    int n; cin >> n;
    string s; cin >> s;

    string t, tt; t = tt = "";
    for (int i = 0; i < n; i++) {
        if (i&1) t += '0', tt += '1';
        else t += '1', tt += '0';
    }

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) cnt1[i]=true;
        if (s[i] != tt[i]) cnt2[i]=true;
    }

    int ret = 424242;
    int tmp = 0;
    for (int i = 0; i < n; i++) {
        if (cnt1[i]) tmp++;
        while (cnt1[i] && i < n) {
            i++;
        }
    }
    ret = min(ret, tmp);
    tmp = 0;
    for (int i = 0; i < n; i++) {
        if (cnt2[i]) tmp++;
        while (cnt2[i] && i < n) {
            i++;
        }
    }
    ret = min(ret, tmp);
    cout << ret << endl;
    return 0;
}