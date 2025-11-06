#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll maxN = 200005;
int MOD = 1e9 + 7;
ll nums[maxN];

void solve() {
  int n; cin >> n;
  map<ll, ll> cnt;
  for (int i = 0; i < n; ++i) {
    ll num; cin >> num;
    ++cnt[num];
  }

  ll res = 1;
  for (auto [key, value] : cnt) {
    res = (res * (value + 1)) % MOD;
  }

  if (res > 1) res = (res - 1 + MOD) % MOD;

  cout << res;
}

int main() {
  solve();
  return 0;
}