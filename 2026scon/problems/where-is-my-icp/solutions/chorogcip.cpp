#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int a, b; string s ,t; cin >> a >> s >> b >> t;
    string asd = "ICPC";
    for (auto ch : asd) {
        auto ind = s.find(ch);
        if (ind != string::npos) {
            s[ind] = '#';
        } else {
            auto ind2 = t.find(ch);
            if (ind2 != string::npos) {
                t[ind2] = '#';
            } else {
                cout << "m4us sad"; exit(0);
            }
        }
    }
    cout << "m4us happy";
}