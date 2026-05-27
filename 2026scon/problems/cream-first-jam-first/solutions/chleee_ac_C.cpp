#include <bits/stdc++.h>

using namespace std;
int main() {
    int CJS, JCS; CJS = JCS = 0;
    int N; cin >> N;
    char prv = '^';
    string s = "";
    for (int i = 0; i < N; i++) {
        char ch; cin >> ch;
        if (ch == prv) continue;
        s += ch;
        prv = ch;
    }

    int c = 0, j = 0;
    s = "^^" + s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'S') {
            if (c == 1 && j == 1) {
                if (s[i-2] == 'J' && s[i-1] == 'C') JCS++;
                else if (s[i-2] == 'C' && s[i-1] == 'J') CJS++;
            }
            c = j = 0;
        }
        if (s[i] == 'C') c++; 
        if (s[i] == 'J') j++;
    }
    cout << CJS << endl << JCS << endl;
    return 0;
}