#include "testlib.h"
#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int> > gen_tree_like(int n, int t)
{
	vector<int> p(n);
	for (int i = 1; i < n; i++)
		p[i] = rnd.wnext(i, t);

	vector<int> perm = rnd.perm(n);

	vector<pair<int, int>> edges;
	for (int i = 1; i < n; i++)
		if (rnd.next(2))
			edges.push_back(make_pair(perm[i], perm[p[i]]));
		else
			edges.push_back(make_pair(perm[p[i]], perm[i]));

	for(auto &[a,b] : edges) if (a > b) swap(a, b); //

	int rep = rnd.next(0, n*(n-1)/2);
	while(n > 1 && rep--)
	{
		int a = rnd.next(0, n-2);
		int b = rnd.next(a+1, n-1);
		edges.push_back({a, b});
	}
	sort(edges.begin(), edges.end());
	edges.erase(unique(edges.begin(), edges.end()), edges.end());

	shuffle(edges.begin(), edges.end());

	return edges;
}

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);

	int lo = opt<int>(1);
	int hi = opt<int>(2);
	assert(lo <= hi);

	vector<pair<int, int> > e;
	int n = 0, m = 0;
	while(n+lo <= 40)
	{
		int cnt = rnd.next(lo, min(hi, 40-n));
		auto v = gen_tree_like(cnt, 0);
		for(auto [a,b] : v)
			e.push_back({n+a, n+b});
		n += cnt, m += (int)v.size();
	}

	vector<int> p(n);
	for(int i=0; i<n; i++)
		p[i] = i;
	shuffle(p.begin(), p.end());
	for(auto &[a,b] : e)
	{
		a = p[a], b = p[b];
		if (a > b) swap(a, b);
	}

	shuffle(e.begin(), e.end());

	cout << n << " " << m << endl;
	for(auto [a,b] : e)
		cout << a+1 << " " << b+1 << endl;
	return 0;
}