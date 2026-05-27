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
    bool seenOther = false;

    for (char ch : s) {
        if (ch == 'S') {
            if (first != 0 && seenOther) {
                if (first == 'C') creamTop++;
                else jamTop++;
            }
            first = 0;
            seenOther = false;
        } else {
            if (first == 0) {
                first = ch;
            } else if (ch != first) {
                seenOther = true;
            }
        }
    }

    cout << creamTop << '\n';
    cout << jamTop << '\n';
    return 0;
}