#include <bits/stdc++.h>
using namespace std;

void solve() {
  long long x; cin >> x;
  string x_s = to_string(x);
  int n = x_s.size();

  long long y = pow(10, n) + 1;

  // cout << y << "\n";
  // cout << res << " ";
  cout << y << "\n";

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}