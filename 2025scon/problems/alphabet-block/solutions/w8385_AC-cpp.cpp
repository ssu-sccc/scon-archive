#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

#define endl '\n'
#define int long long
#define all(v) v.begin(), v.end()
using namespace std;

auto operator>>(istream &is, pair<int, int> &p) -> istream & {
    return is >> p.first >> p.second;
}

auto operator<<(ostream &os, const pair<int, int> &p) -> ostream & {
    return os << p.first << ' ' << p.second;
}

template<typename T>
auto operator>>(istream &is, vector<T> &v) -> istream & {
    for (auto &i: v) is >> i;
    return is;
}

template<typename T>
auto operator<<(ostream &os, const vector<T> v) -> ostream & {
    for (auto i: v) cout << i << ' ';
    return os;
}

template<typename T>
auto operator<<(ostream &os, const set<T> v) -> ostream & {
    for (auto i: v) cout << i << ' ';
    return os;
}

auto main() -> signed {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int s, c, o, n;
    cin >> s >> c >> o >> n;

    c += 2 * o;
    s += n;

    cout << min(s / 3, c / 6) << endl;
}
