#include <bits/stdc++.h>
using namespace std;
 
const long long P = 10000;
const long long M = 1e9 + 7;
 
void solve() {
  string s; cin >> s;
  int n = s.size();
  
  vector<long long> base_pow(n);
  vector<long long> pre(n + 1);
  base_pow[0] = 1;
  for (int i = 1; i < n; ++i) {
    base_pow[i] = base_pow[i-1] * P % M;
  }
 
  for (int i = 1; i <= n; ++i) {
    pre[i] = (pre[i - 1] * P + s[i - 1]) % M;
  }
  
  auto get_hash = [&](int l, int r) -> long long {
    long long h = pre[r + 1] - (base_pow[r - l + 1] * pre[l] % M) % M;
    return h < 0 ? h + M : h;
  };
 
  for (int i = 0; i < n - 1; ++i) {
    int ok = get_hash(0, i) == get_hash(n - i - 1, n - 1);

    if (ok) {
      cout << i + 1 << " ";
    }
  }
 
}
 
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}