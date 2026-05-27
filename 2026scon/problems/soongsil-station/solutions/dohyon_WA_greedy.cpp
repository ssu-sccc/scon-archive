#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> L(3);
    cin >> L[0] >> L[1] >> L[2];
    int H; 
    cin >> H;
    sort(L.rbegin(), L.rend()); 
    int ans = 0;
    for(int i = 0; i < 3; i++) {
        if(H > L[i] / 2) { 
            H -= L[i] / 2;
            ans += L[i] / 2;
        } else {
            ans += L[i];
        }
    }
    cout << ans;
}