#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string s;
    cin >> N >> s;

    int creamFirst = 0, jamFirst = 0;
    int i = 0;

    while (i < N) {
        int start = i;
        while (i < N && s[i] != 'S') i++;

        int len = i - start;

        if (len >= 2) {
            char first = s[start];
            int j = start;

            while (j < i && s[j] == first) j++;
            int secondLen = i - j;

            bool valid = true;

            if (first == 'S' || j == start || secondLen == 0) {
                valid = false;
            } else {
                char second = s[j];
                if (second == first || second == 'S') valid = false;

                for (int k = j; k < i; k++) {
                    if (s[k] != second) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    if (first == 'C' && second == 'J') creamFirst++;
                    else if (first == 'J' && second == 'C') jamFirst++;
                }
            }
        }

        i++;
    }

    cout << creamFirst << '\n' << jamFirst << '\n';
    return 0;
}