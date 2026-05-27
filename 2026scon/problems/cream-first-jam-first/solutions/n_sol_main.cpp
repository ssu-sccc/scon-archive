#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string s;
    cin >> N >> s;

    int creamTop = 0;
    int jamTop = 0;

    char first = 0;
    char last = 0;
    int changes = 0;

    for (char ch : s) {
        if (ch == 'S') {
            if (first != 0 && changes == 1) {
                if (first == 'C') creamTop++;
                else jamTop++;
            }
            first = 0;
            last = 0;
            changes = 0;
        } else {
            if (first == 0) first = ch;
            else if (last != ch) changes++;
            last = ch;
        }
    }

    cout << creamTop << '\n';
    cout << jamTop << '\n';

    return 0;
}