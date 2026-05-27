#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;
int main() {
    int n; cin >> n;
    vector<pair<char, int>> v;

    char _; cin >> _;
    v.push_back({_, 1});
    for (int i = 0; i < n-1; i++) {
        char ch; cin >> ch;
        if (ch == v.back().x) v.back().y++;
        else if (ch < v.back().x) v.back().y = 1, v.push_back({ch, 1});
        else v.push_back({ch, 1});
    }

    for (int i = 0; i < v.size() - 1; i++) {
        for (int j = 0; j < v[i].y; j++) cout << v[i].x;
    }
    cout << v.back().x;

    return 0;
}