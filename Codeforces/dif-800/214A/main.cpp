#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ump unordered_map
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ln "\n"

void solve() {
  ll n, m; cin >> n >> m;

  if (n < m) swap(n, m);
  ll cnt = 0;
  for (ll a = 0; a*a <= n; ++a) {
    ll b = n - (a * a);
    if ((b*b + a) == m) ++cnt;
  }
  cout << cnt;
}

int main() {
  flash;
  solve();
  return 0;
}