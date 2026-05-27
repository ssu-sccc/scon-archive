#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    string s, t;
    cin >> n >> s >> m >> t;
    string target = "ICPC";
    map<char,int> need;
    for (char c : target) need[c]++;
    for (char c : s) need[c]--;
    for (char c : t) need[c]--;
    bool ok = true;
    for (auto &[k,v] : need)
        if (v > 0) ok = false;
    cout << (ok ? "m4us happy" : "m4us sad") << endl;
}