#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;

vector<int> pr;
vector<int> v[5050];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (int i = 2; i <= 5000; i++) {
		int flag = 1;
		for (int x : pr)
			if (i % x == 0) flag = 0;
		if (flag) pr.push_back(i);
	}

	for (int i = 1; i <= 5000; i++) {
		int k = i, t = 0;
		while (k > 1) {
			if (k % pr[t] == 0) {
				v[i].push_back(t);
				k /= pr[t];
			} else t++;
		}
	}

	int n;
	cin >> n;
	while (n--) {
		ll n1, r1, n2, r2;
		cin >> n1 >> r1 >> n2 >> r2;
		vector<int> mv1(pr.size() + 1), mv2(pr.size() + 1);

		for (int i = n1; i > r1; i--)
			for (int x : v[i]) mv1[x]++;
		for (int i = 1; i <= n1 - r1; i++)
			for (int x : v[i]) mv1[x]--;
		for (int i = n2; i > r2; i--)
			for (int x : v[i]) mv2[x]++;
		for (int i = 1; i <= n2 - r2; i++)
			for (int x : v[i]) mv2[x]--;

		int flag = 1;
		for (int i = 0; i < mv1.size(); i++) {
			if (mv1[i] && mv2[i]) flag = 0;
		}
		cout << flag << endl;
	}

	return 0;
}