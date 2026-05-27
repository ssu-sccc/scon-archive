#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
using ll = long long;

int arr[101];
int main() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            int x; cin >> x; arr[x]++;
        }
    }

    int ret = 0;
    for (int i = 1; i <= 100; i++) {
        for (int j = i+1; j <= 100; j++) {
            for (int k = j+1; k <= 100; k++) {
                arr[i]++, arr[j]++, arr[k]++;
                
                int tmp = -1;
                for (int t = 100; t > 0; t--) {
                    if (arr[t] == 1) {
                        tmp = t;
                        break;
                    }
                }
                if (tmp == i || tmp == j || tmp == k) ret++;
                arr[i]--, arr[j]--, arr[k]--;
            }
        }
    }
    cout << ret << endl;
}