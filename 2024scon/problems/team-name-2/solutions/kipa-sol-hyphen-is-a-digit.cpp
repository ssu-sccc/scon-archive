#ifdef SIMD
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2")
#endif

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <compare>
#include <cstdio>
#include <cstring>
#include <functional>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <type_traits>
#include <vector>

#ifdef SIMD
#include <immintrin.h>
#include <smmintrin.h>
#endif

using namespace std;

typedef long long int lli;
typedef pair<int, int> pii;
typedef pair<lli, lli> plli;
#define byte unsigned char
typedef unsigned int uint;
typedef unsigned long long int ulli;

template <typename _T> class _vector: public vector<_T> {
public:
    _vector(): vector<_T>() {}
    _vector(size_t n, const _T& val = _T()): vector<_T>(n, val) {}
    template <class InputIterator> _vector(InputIterator first, InputIterator last): vector<_T>(first, last) {}
    _vector(const vector<_T>& x): vector<_T>(x) {}
    _vector(int n): vector<_T>(n) {}
    void sort() {
        std::sort(this->begin(), this->end());
    }
    template <typename _U> void sort(std::function<_U(const _T &)> key) {
        std::sort(this->begin(), this->end(), [=] (const _T &x, const _T &y) {
            return key(x) < key(y);
        });
    }
    void sort(std::function<bool(const _T &, const _T &)> compare) {
        std::sort(this->begin(), this->end(), compare);
    }
};

#define vector _vector

char S[100][30];
int crit[100];

int main() {
    int n;
    scanf("%d", &n);
    for (int i=0; i<n; ++i) {
        int big_count = 0, small_count = 0, digit_count = 0;
        scanf("%s", S[i]);
        char *const S = ::S[i];
        int j;
        for (j=0; S[j]; ++j) {
            if (S[j] >= 'a') {
                ++small_count;
            } else if (S[j] >= 'A') {
                ++big_count;
            } else {
                ++digit_count;
            }
        }
        crit[i] = (small_count >= big_count) + (j <= 10) + (digit_count < j);
    }
    for (int i=0; i<n; ++i) {
        if (crit[i] == 3) {
            printf("%s\n", S[i]);
            return 0;
        }
    }
    return 0;
}
