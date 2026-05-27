#include "testlib.h"
#include <vector>
#include <set>

using namespace std;

const long long MIN_VAL = -1e9;
const long long MAX_VAL =  1e9;

int main(int argc, char * argv[]) {
    registerTestlibCmd(argc, argv);

    int N = inf.readInt(1, 5000, "N");
    vector<long long> a(N);
    set<long long> elements;

    for (int i = 0; i < N; i++) {
        a[i] = ouf.readLong(MIN_VAL, MAX_VAL, format("a[%d]", i + 1));
        elements.insert(a[i]);
    }

    if ((int)elements.size() != N) {
        quitf(_wa, "Elements are not mutually distinct. Expected %d, found %d", N, (int)elements.size());
    }

    set<long long> all_sums;
    for (int i = 0; i < N; i++) {
        long long current_sum = 0;
        for (int j = i; j < N; j++) {
            current_sum += a[j];
            all_sums.insert(current_sum);
        }
    }

    if ((int)all_sums.size() != N) {
        quitf(_wa, "The number of distinct subarray sums is %d, expected %d", (int)all_sums.size(), N);
    }

    quitf(_ok, "Correct! Length is %d and exact %d distinct sums found.", N, N);
}