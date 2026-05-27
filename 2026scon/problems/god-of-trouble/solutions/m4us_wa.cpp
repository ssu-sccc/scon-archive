#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define prs(v) sort(all(v)), (v).erase(unique(all(v)), (v).end())
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;

int N, A[1010];

int qry(int x) {
  cout << "? " << x << endl;
  int y;
  cin >> y;
  return y;
}

void flip() {
  for (int i = 1; i <= N; i++)
    A[i] ^= 1;
}
void rev() { reverse(A + 1, A + N + 1); }

void sol(int tc) {
  cin >> N;
  for (int i = 1; i <= N; i++)
    A[i] = -1;
  int idx = 1, qc = 10, s = -1, d = -1;
  
   if (N <= 10) {
    for (int i = 1; i <= N; i++)
      A[i] = qry(i);
    cout << "! ";
    for (int i = 1; i <= N; i++)
      cout << A[i] << ' ';
    cout << endl;
    return;
  }

  for (int i = 1; i <= 5; i++) {
    int x = A[i] = qry(i);
    int y = A[N - i + 1] = qry(N - i + 1);
    if (x == y)
      s = i;
    else
      d = i;
  }

  while (idx <= N+1>>1) {
    if (qc % 10 == 0) {
      if (s == -1) {
        int x = qry(d);
        qry(d);
        qc += 2;
        if (A[d] != x)
          rev();
      } else if (d == -1) {
        int x = qry(s);
        qry(s);
        qc += 2;
        if (A[s] != x)
          flip();
      } else {
        int x = qry(s);
        int y = qry(d);
        qc += 2;

        if (A[s] != x && A[d] != y)
          flip();
        else if (A[s] != x)
          flip(), rev();
        else if(A[d] != y)
          rev();
      }
    } else {
      int x = A[idx] = qry(idx);
      int y = A[N - idx + 1] = qry(N - idx + 1);
      if (x == y)
        s = idx;
      else
        d = idx;
      qc += 2;
      idx++;
    }
  }

  cout << "! ";
  for (int i = 1; i <= N; i++)
    cout << A[i] << ' ';
  cout << endl;
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  int t = 1;
  // cin >> t;
  for (int i = 1; i <= t; i++)
    sol(i);
  return 0;
}