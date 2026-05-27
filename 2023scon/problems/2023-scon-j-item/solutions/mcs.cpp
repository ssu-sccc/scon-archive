#include<bits/stdc++.h>
using namespace std;
using ll = long long;
 
int n, trie[12020020][2], c[12020020], cnt;
ll a[200200];


int dfs(int u, int left) {
    if(!u) return 0;
    if(c[u] < left) return -n; // check

    int L = trie[u][0], R = trie[u][1];
    if(!L && !R) return c[u]-left;
    if(c[u] == left) return 0;

    if(!L) return dfs(R, left+1) + 1;
    if(!R) return dfs(L, left+1) + 1;

    return max(dfs(L, max(0, left+1-c[R])), dfs(R, max(0, left+1-c[L]))) + 1;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    
    for(int i=1;i<=n;i++) {
        int u = 0; c[u]++;
        for(int j=0;j<60;j++) {
            int x = (a[i] >> j) & 1;
            if(!trie[u][x]) trie[u][x] = ++cnt;
            u = trie[u][x], c[u]++;
        }
    }

    cout << max(dfs(trie[0][1], 0), dfs(trie[0][0], 0));
}
