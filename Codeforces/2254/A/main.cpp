#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> A = {a, b, c};
  sort(A.begin(), A.end());

  int ans = min(A[2] - A[1], A[1] - A[0]);

  cout << ans << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while(t--)
  solve();
  return 0;
}