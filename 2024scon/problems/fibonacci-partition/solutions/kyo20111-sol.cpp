#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
vector<int> v[2];

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    while(n >= 3) {
        v[0].push_back(n--);
        v[1].push_back(n--);
        v[1].push_back(n--);
    }
    if(n == 2) v[0].push_back(1), v[1].push_back(2);

    for(int i=0;i<2;i++) {
        cout << v[i].size() << "\n";
        for(auto x : v[i]) cout << x << " ";
        cout << "\n";
    }
}