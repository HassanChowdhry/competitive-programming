#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln "\n"

void solve() {
  ll n; cin >> n;

  if (ceil(sqrt(n)) != floor(sqrt(n))) { cout << 0; return; }

  n = sqrt(n);
  ll ans = 0;
  // cout << x << ln;
  for (int i = 2; i*i < n; ++i) {
    if (n % i == 0) { ++ans; }
  }
  cout << ans << ln;
}

int main() {
  solve();
  return 0;
}