#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;

  long long ans = 0;

  for (long long i = 1; i <= n; ++i) {
    long long curr = n / i;
    ans += (curr * curr);
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