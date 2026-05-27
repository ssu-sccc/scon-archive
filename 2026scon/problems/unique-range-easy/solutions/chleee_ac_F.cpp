#include <bits/stdc++.h>

using namespace std;
int main() {
    int n; cin >> n;
    
    vector<int> v; v.push_back(0);
    int target = 0; 
    for (int i = 1; i < n; i++) {
        target += (i&1) ? i : -i;
        v.push_back(target);
    }
    // sort(v.begin(), v.end());
    for (auto i : v) cout << i << ' ';
    return 0;
}
