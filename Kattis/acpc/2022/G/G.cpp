#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln "\n"
#define fs first
#define sc second
void solve() {
  ll A, B; cin >> A >> B;
  vector<pair<ll, ll>> res;
  for (ll i = A; i <= B; ++i) {
    string a = to_string(i);
    for (ll j = i + 1; j <= B; ++j) {
      if (i * j > B) break;
      ll M = i * j;
      string b = to_string(j);
      string m = to_string(M);
      
      vector<int> cnt(10, 0);
      // cout << a << " " << b << " " << m << " " << ln;
      for(char c: a) ++cnt[c-'0'];
      for(char c: b) ++cnt[c-'0'];
      for(char c: m) --cnt[c-'0'];
      int ok = 1;
      for (int num: cnt) { if (num) { ok = 0; break; } }
      if (!ok) continue;
      // cout << ln;

      res.push_back({i, j});
    }
  }

  cout << res.size() << " digit-preserving pair(s)" << ln;
  for (auto [x, y] : res) {
    cout << "x = " << x << ", y = " << y << ", xy = " << x * y << ln;
  }
}

int main() {
  solve();
  return 0;
}