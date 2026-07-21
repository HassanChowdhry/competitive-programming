#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> p(n + 1);
  vector<int> d(n + 1);
  vector<int> md(n + 1);
  vector<int> mdf(n + 1);
  vector<int> mds(n + 1);
  for (int i = 2; i <= n; ++i) {
    cin >> p[i];
    d[i] = d[p[i]] + 1;
    md[i] = d[i];
  }
  
  
  for (int i = 2; i <= n; ++i) {
    if (md[i] > mdf[p[i]]) {
      mds[p[i]] = mdf[p[i]];
      mdf[p[i]] = md[i];
    } else if (md[i] > mds[p[i]]) {
      mds[p[i]] = md[i];
    }
    md[p[i]] = max(md[p[i]], md[i]);
  }

  long long ans = n;

  for (int i = 1; i <= n; ++i) {
    if (mds[i] >= d[i])
      ans += (mds[i] - d[i]);
  }

  cout << ans << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}