#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[]) {
	registerGen(argc, argv, 1);

	int n = __testlib_opts.count("n") ? opt<int>("n") : rnd.next(0, 999) * 2 + 1;
	int type = __testlib_opts.count("type") ? opt<int>("type") : rnd.next(0, 1); // 1 : and + F , 0 : or + T
	int count  = __testlib_opts.count("count") ? opt<int>("count") : rnd.next(0, 1);
	int target  = __testlib_opts.count("target") ? opt<int>("target") : rnd.next(0, 1);

	int idx = count ? (__testlib_opts.count("back") ? n - 1 : rnd.next(0, n / 2) * 2) : -1;
	cout << n << "\n";
	for (int i = 0; i < n; i++) {
		if (i) cout << " ";
		if (i % 2 == 0) cout << ((type ^ (idx == i)) ? "F" : "T");
		else cout << (type ? "&" : "|");
	}
	cout << "\n" << (target ? "T" : "F") << "\n";
}
