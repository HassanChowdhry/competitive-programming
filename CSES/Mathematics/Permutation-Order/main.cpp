#include <bits/stdc++.h>
using namespace std;

const int maxN = 21;
long long n, f;
long long k;
long long p[maxN];
long long fact[21];
int vis[21];

void precalc_fact() {
  fact[0] = 1;

  for (int i = 1; i <= 20; ++i) {
    fact[i] = 1LL * i * fact[i - 1];
  }
}

void solve() {
  cin >> f >> n;

  // this has something to do with displacements
  // if 2 is in the position of 1, then we can assume
  // that we have gone through 1 * (n - 1)! ordering
  // and we can use this logic to go through the rest relative
  // out of place elements.


  // case 1: 
  // we make ci as large as possible without overflowing to > k


  // case 2:
  // for i we count the number of elements < p[i]
  // that is our ci * (n - i)!


  if (f == 1) {
    cin >> k;
    k -= 1;
    for (int i = 0; i <= 20; ++i) vis[i] = 0;
    
    for (int i = 1; i <= n; ++i) {
      long long x = 0;
      for (long long j = 0; j <= n; ++j) {
        if (j * fact[n - i] > k) break;
        x = j;
      }
      k -= (x * fact[n - i]);
      
      // cout << i << " " << x << " ";
      for (int j = 1; j <= n; ++j) {
        if (!vis[j] && !x) {
          vis[j] = 1;
          cout << j << " ";
          break;
        } else if (!vis[j] && x) {
          // cout << i << " " << j <<"\n";
          --x;
        }
      }
    }
    cout << "\n";
  } else if (f == 2) {
    for (int i = 1; i <= n; ++i) cin >> p[i];

    long long k = 1;

    for (int i = 1; i <= n; ++i) {
      long long cnt = 0;
      
      for (int j = i + 1; j <= n; ++j) {
        if (p[j] < p[i]) ++cnt;
      }

      cnt *= fact[n - i];
      k += cnt;
    }

    cout << k << "\n";
  }


  // cout << n;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  precalc_fact();
  int t; cin >> t;
  while(t--)
    solve();
  // solve();
  return 0;
}