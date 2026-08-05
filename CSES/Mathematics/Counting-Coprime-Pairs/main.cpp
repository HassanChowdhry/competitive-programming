#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5, maxX = 1e6;
long long n, ans, bpair;
long long x[maxN + 1], divcnt[maxX + 1], frq[maxX + 1], mobius[maxX + 1], prime[maxX + 1];

void sieve() {
  for (int i = 2; i <= maxX; ++i) {
    prime[i] = 1;
  }

  for (int i = 2; i <= maxX; ++i) {
    // for each d, harmonic sum nlogn
    for (int j = i; j <= maxX; j += i) {
      divcnt[i] += frq[j];
    }
  }
}

void compute_mobius() {
  mobius[1] = -1;
  for (int i = 1; i <= maxX; i++) {
    if (mobius[i]) {
      mobius[i] = -mobius[i];
      for (int j = 2 * i; j <= maxX; j += i) { 
          mobius[j] += mobius[i]; 
      }
    }
  }
}

void solve() {
  cin >> n;

  for (int i = 1; i <= n; ++i) {
    cin >> x[i]; 
    ++frq[x[i]];
  }
  sieve();
  compute_mobius();

  ans = n * (n - 1LL) / 2LL;
  bpair = 0LL;

  // inc/exc -> remove bad pairs
  

  // sum ( mob[d] * (divcnt[d] * divcnt[d] - 1 / 2) )
  // mobius is relevant here because we are checking inc/exc with respect to each div
  for (int i = 2; i <= maxX; ++i) {
    bpair += mobius[i] * (divcnt[i] * (divcnt[i] - 1LL) / 2LL);
  }

  ans = ans + bpair; // bpair is negative alr

  cout << ans;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  // int t; cin >> t;
  // while(t--)
  solve();
  return 0;
}