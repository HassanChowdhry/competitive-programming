#include <bits/stdc++.h>
using namespace std;

int n;
long long sum, sum2;

void solve() {
	cin >> n;
  long long x; sum = 0;

  for (int i = 1; i <= n; ++i) {
    cin >> x;
    // cout << x << " ";
    x %= 4;
    sum ^= x;
  }

  cout << (sum != 0 ? "first" : "second") << "\n";
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
	int t; cin >> t;
  while (t--) solve();
	return 0;
}