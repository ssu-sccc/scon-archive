#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

struct Node {
	int g[2], cnt, dp;
	bool leaf;
	Node() { g[0] = g[1] = cnt = dp = leaf = 0; }
};
vector<Node> trie(2);

void Insert(int n, int k, ll x)
{
	trie[n].cnt++;
	if (k == 0)
	{
		trie[n].leaf = true;
		return;
	}
	if (trie[n].g[x%2] == 0) trie[n].g[x%2] = trie.size(), trie.push_back(Node());
	Insert(trie[n].g[x&1], k-1, x/2);
}

int N, res;

void DFS(int n)
{
	if (n == 0) return;
	if (trie[n].leaf) trie[n].dp = trie[n].cnt;
	for(int i=0; i<2; i++)
	{
		DFS(trie[n].g[i]);
		trie[n].dp = max(trie[n].dp, trie[trie[n].g[i]].dp + (trie[trie[n].g[i]].dp < trie[n].cnt));
	}
	if (n != 1) res = max(res, trie[n].dp);
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> N;
	for(int i=1; i<=N; i++)
	{
		ll x;
		cin >> x;
		Insert(1, 60, x);
	}
	DFS(1);
	cout << res << "\n";
	return 0;
}