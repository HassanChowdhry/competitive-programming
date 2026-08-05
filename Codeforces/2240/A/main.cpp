#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, k; cin >> n >> k;

  if (n <= k) {
    cout << n << '\n';
    return;
  }

  long long ans = 0;
  for (int i = 0; i < 32; ++i) {
    long long num = min( n / ( 1 << i ), k);
		ans += num,
    n -= num * ( 1 << i );
  }

  cout << ans << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while(t--)
  solve();
  return 0;
}