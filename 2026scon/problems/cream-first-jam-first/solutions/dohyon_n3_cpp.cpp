#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    string T;
    cin >> T;

    int CJS = 0, JCS = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            if ((i == 0 || T[i - 1] == 'S') && T[j - 1] == 'S') {
                string S = T.substr(i, j - i);

                if (S.find("SC") != string::npos ||
                    S.find("SJ") != string::npos ||
                    S.find("SS") != string::npos)
                    continue;

                bool chk1 = (S.find("CJ") != string::npos);
                bool chk2 = (S.find("JC") != string::npos);

                if (chk1 && !chk2)
                    ++CJS;
                else if (!chk1 && chk2)
                    ++JCS;
            }
        }
    }

    cout << CJS << '\n' << JCS;
}