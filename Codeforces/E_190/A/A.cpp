#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, a, b; cin >> n >> a >> b;

  if (b <= a) {
    long long res = (1LL * n + 2LL) / 3LL * b * 1LL;
    cout << res << "\n"; return;
  }

  if (b >= 3LL * a) {
    long long res = 1LL * n * a;
    cout << res << "\n"; return;
  }

  long long p1 = (n * 1LL / 3LL) * b * 1LL;
  long long p2;
  int left = n % 3;
  if (1LL * left * a < 1LL * b) p2 = left * 1LL * a;
  else p2 = b * 1LL;
  long long res = p1 + p2;
  cout << res << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while (t--)
  solve();
  return 0;
}