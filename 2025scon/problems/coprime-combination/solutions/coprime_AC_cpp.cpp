#include <bits/stdc++.h>
using namespace std;

#define MAX 5050

int T;
int n1, r1, n2, r2;
vector<int> primes;
bool isPrime[MAX];
int cnt[MAX][MAX];
int pre[MAX][MAX];

int main() {

  for (int i = 2; i <= MAX; i++) {
    if (!isPrime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= MAX; j += i) {
        isPrime[j] = true;
      }
    }
  }

  for (int i = 1; i <= 5000; i++) {
    int tmp = i;
    for (int p : primes) {
      while (tmp > 1 && tmp % p == 0) {
        cnt[i][p]++;
        tmp /= p;
      }
    }
    if (tmp > 1) cnt[i][tmp]++;
  }

  for (int i = 2; i <= 5000; i++) {
    for (int j = 2; j <= i; j++) {
      pre[i][j] = pre[i-1][j] + cnt[i][j];
    }
  }

  cin >> T;
  while (T--) {
    cin >> n1 >> r1 >> n2 >> r2;
    
    bool f = true;
    for (int i = 2; i <= 5000; i++) {
      int nCr1 = pre[n1][i] - pre[n1 - r1][i] - pre[r1][i];
      int nCr2 = pre[n2][i] - pre[n2 - r2][i] - pre[r2][i];
      if (nCr1 > 0 && nCr2 > 0) {
        f = false;
      }
    }
    cout << f << '\n';
  }
  return 0;
}