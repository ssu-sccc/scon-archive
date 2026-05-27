#include<bits/stdc++.h>
using namespace std;

#define INF 1234567890
#define ll long long

#define FLOW_MAX 1234567890
template<class Cap> struct Dinic {
	struct Edge { int next, rev; Cap c, f; };
	int N;
	vector<vector<Edge> > g;
	vector<int> lv, work;
	queue<int> q;
	Dinic(int n) : N(n), g(n), lv(n), work(n) {}
	void AddEdge(int a, int b, Cap c) {
		g[a].push_back({ b, (int)g[b].size(), c, 0 });
		g[b].push_back({ a, (int)g[a].size() - 1, 0, 0 });
	}
	Cap dfs(int n, int snk, Cap flow) {
		if (n == snk) return flow;
		for (int &i = work[n]; i < g[n].size(); i++) {
			auto &e = g[n][i];
			if (e.c - e.f > 0 && lv[e.next] == lv[n] + 1) {
				Cap cost = dfs(e.next, snk, min(flow, e.c - e.f));
				if (cost > 0) {
					e.f += cost;
					g[e.next][e.rev].f -= cost;
					return cost;
				}
			}
		}
		return 0;
	}
	Cap Run(int src, int snk, Cap upper = FLOW_MAX) {
		Cap ret = 0;
		while (1) {
			fill(lv.begin(), lv.end(), -1);
			q.push(src); lv[src] = 0;
			while (!q.empty()) {
				int n = q.front(); q.pop();
				for (auto &e : g[n])
					if (e.c - e.f > 0 && lv[e.next] == -1)
						q.push(e.next), lv[e.next] = lv[n] + 1;
			}
			if (lv[snk] == -1) break;
			fill(work.begin(), work.end(), 0);
			while (1) {
				Cap flow = dfs(src, snk, upper - ret);
				ret += flow;
				if (flow == 0 || ret == upper) break;
			}
			if (ret == upper) break;
		}
		return ret;
	}
};

int N, K, X;
bool can[15][15];
vector<pair<int, int> > v;

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	cin >> N >> K >> X;
	Dinic<int> dinic(N+K+2);
	int src = N+K, snk = N+K+1;
	for(int i=0; i<N; i++)
		dinic.AddEdge(src, i, 1);
	for(int i=0; i<K; i++)
		dinic.AddEdge(i+N, snk, X);

	for(int i=0; i<N; i++)
	{
		int x, y;
		cin >> x;
		while(x--)
		{
			cin >> y;
			y--; // 0-based
			can[i][y] = true;
		}
	}
	for(int i=0; i<N; i++)
	{
		int x;
		cin >> x;
		v.push_back({x, i});
	}
	sort(v.rbegin(), v.rend());

	vector<vector<int> > p(N, vector<int>(K));
	vector<vector<int> > res(K);
	for(auto [x,i] : v)
	{
		for(int k=0; k<K; k++)
			if (can[i][k])
			{
				p[i][k] = dinic.g[i].size();
				dinic.AddEdge(i, k+N, 1);
			}
		dinic.Run(src, snk);
	}

	for(int i=0; i<N; i++)
		for(int k=0; k<K; k++)
			if (can[i][k] && dinic.g[i][p[i][k]].f)
				res[k].push_back(i);

	for(int k=0; k<K; k++)
	{
		cout << res[k].size() << " ";
		for(int x : res[k])
			cout << x+1 << " ";
		cout << "\n";
	}
	return 0;
}