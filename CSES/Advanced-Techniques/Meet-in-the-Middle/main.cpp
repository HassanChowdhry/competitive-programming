#include <bits/stdc++.h>
using namespace std;
 
int n, x;
const int maxN = 40;
unordered_map<long long, int> dp;
int t[maxN+1];
long long sum;
long long ans;
/**
 * obviously need bit masking for this, n = 40
 * meet in the middle, do bitmasking on n = 20, store
 * res in ds and use to query x - curr
 */
void solve() {
 
  cin >> n >> x;
  for (int i = 0; i < n; ++i) cin >> t[i];
 
  int m = (n > 20 ? 20 : n);
  int z = (n > 20 ? n - 20 : 0);
  
  dp.reserve(1 << m);
  for (int i = 1; i < (1 << m); ++i) {
    sum = 0;
 
    for (int j = 0; j < m; ++j) {
      if (i & (1 << j)) {
        sum += t[j];
      }
      if (sum > x || sum < 0) break;
    }
 
    if (sum <= 0 || sum > x) continue;
    ++dp[sum];
  }
 
  ans = dp[x];
 
  // cout << ans;
 
  for (int i = 1; i < (1 << z); ++i) {
    sum = 0;
 
    for (int j = 0; j < z; ++j) {
      if (i & (1 << j)) {
        sum += t[j + 20];
      }
      if (sum > x || sum < 0) break;
    }
 
    if (sum <= 0 || sum > x) continue;
    
    auto it = dp.find(x - sum);
    if (it != dp.end()) ans += it->second;
    if (sum == x) ++ans;
 
  }
  
  cout << ans;
 
}
 
int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  // int t; cin >> t;
  // while(t--)
  solve();
  return 0;
}