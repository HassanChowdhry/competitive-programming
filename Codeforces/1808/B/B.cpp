#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n, m; cin >> n >> m;
  vector<vector<long long>> c(n, vector<long long>(m));
  vector<vector<long long>> cr(m, vector<long long>(n));

  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j)
    cin >> c[i][j];
  }
  
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < n; ++j)
    cr[i][j] = c[j][i];
    
    sort(cr[i].rbegin(), cr[i].rend());
  }
  
  long long ans = 0;

  for (int i = 0; i < m; ++i) {
    long long curr = 0;
    for (int j = 0; j < n; ++j) curr += cr[i][j];
    
    for (int j = 0; j < n; ++j) {
      // cout << cr[i][j] << "\n";
      curr -= cr[i][j];
      rem rem = n - j - 1;
      // cout << cr[i][j] << " rem: " << rem << " ans: " << cr[i][j] * rem << "\n";
      ans += ((cr[i][j] * rem*1LL) - curr);
    }
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