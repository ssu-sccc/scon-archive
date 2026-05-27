#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);

	auto conv = [](int i) {
	  string h, m;
	  h = to_string(i / 60);
	  if (h.size() == 1) h.insert(h.begin(), '0');
	  m = to_string(i % 60);
	  if (m.size() == 1) m.insert(m.begin(), '0');
	  return h + ":" + m;
	};

	int cnt_per_group = __testlib_opts.count("cnt") ? opt<int>("cnt") : rnd.next(1, 20);
	int n = 15 / cnt_per_group, extra = 15 % cnt_per_group;
	vector<int> cnt(n);
	for (int &i : cnt) i = cnt_per_group;
	int sum = accumulate(cnt.begin(), cnt.end(), 0);
	while (sum < 15) {
		for (int i = 0; i < n && sum < 15; i++) cnt[i]++, sum++;
	}
	cout << n << "\n";
	int interval = 1440 / n;
	for (int i = 0; i < n; i++) {
		int st = i * interval, ed = i + 1 == n ? 1440 - 1 : (i + 1) * interval;

		cout << cnt[i] << "\n";
		for (int j = 0; j < cnt[i]; j++) {
			cout << 22 / n + (j * 2 < cnt[i] ? (22 % n + 1) / 2 : 0) << " " << rnd.next(1, 7) << " " << conv(st) << " " << conv(ed) << "\n";
		}
	}
}
