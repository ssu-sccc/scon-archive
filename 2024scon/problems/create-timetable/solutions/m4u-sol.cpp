#include <bits/stdc++.h>
using namespace std;
using sbj=tuple<int,int,int,int,int>;
 
int N;
 
int h(string s) { return stoi(s.substr(0,2))*60+stoi(s.substr(3,2)); }
 
vector<sbj> a;
int chk(int n, int sz) {
    int crd=0;
    vector<int> u(N,0);
    vector<pair<int,int>> day[8];
    for(int i=0;i<sz;i++) if((n>>i) & 1) {
        auto [idx,c,d,s,e]=a[i];
        crd+=c;
        if(u[idx]) return 0;
        u[idx]=1;
        day[d].push_back({s,e});
    }
    if(crd!=22) return 0;
    for(int i=1;i<=7;i++) {
        sort(day[i].begin(),day[i].end());
        for(int j=1;j<day[i].size();j++) {
            if(day[i][j-1].second > day[i][j].first) return 0;
        }
    }
    return 1;
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    for(int i=0,t;i<N;i++) {
        cin >> t;
        while(t--) {
            int c,d; string s,e;
            cin >> c >> d >> s >> e;
            a.emplace_back(i,c,d,h(s),h(e));
        }
    }
    int dap=0, n=a.size();
    for(int i=0;i<(1<<n);i++) dap+=chk(i, n);
    cout << dap;
    return 0;
}