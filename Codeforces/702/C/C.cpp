#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<long long> a(n + 5), b(m + 5);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < m; ++i) cin >> b[i];
  // 3 cases
  // find r using b search
  // r is valid if all are within r
  // for ai, bi checks. 
  //  while not range(ai, bj, r) 
  //    if ai > bj: j++
  //    if ai < bj: not valid
  // if in range(valid)

  auto valid = [&](long long r) -> int {
    int i = 0, j = 0;
    while (i < n && j < m) {
      if (abs(a[i] - b[j]) > r) {
        if (a[i] > b[j]) ++j;
        else if (a[i] < b[j]) return 0;
      } else {
        ++i;
      }
    }
    
    return (i == n ? 1 : 0);
  };

  long long l = 0, r = 2e9 + 5;
  long long ans = -1;
  // cout << r << "\n";
  while (l <= r) {
    long long mid = (l + r) / 2;
    // cout << valid(mid) << "\n";
    if (valid(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << ans;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}