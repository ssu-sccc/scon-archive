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

    auto gen_hhmm = [&conv]() {
      int duration = rnd.next(1, 60 * 24 - 1);
      int start = rnd.next(0, 60 * 24 - duration);
      int end = rnd.next(start + 1, 60 * 24 - 1);
      return make_pair(conv(start), conv(end));
    };

    int n = rnd.next(1, 15);
    cout << n << "\n";
    vector<int> cnt = rnd.partition(n, rnd.next(n, 15));
    for (int i: cnt) {
        cout << i << "\n";
        while (i--) {
            auto [a, b] = gen_hhmm();
            int credit = rnd.next(1, 3);
            int day = rnd.next(1, 7);
            cout << credit << " " << day << " " << a << " " << b << "\n";
        }
    }
}
