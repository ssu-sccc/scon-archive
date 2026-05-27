#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string s;
    cin >> N >> s;

    regex creamPattern("^C+J+$");
    regex jamPattern("^J+C+$");

    int creamFirst = 0, jamFirst = 0;
    string cur;

    for (char ch : s) {
        if (ch == 'S') {
            if (regex_match(cur, creamPattern)) creamFirst++;
            else if (regex_match(cur, jamPattern)) jamFirst++;
            cur.clear();
        } else {
            cur += ch;
        }
    }

    cout << creamFirst << '\n' << jamFirst << '\n';
    return 0;
}