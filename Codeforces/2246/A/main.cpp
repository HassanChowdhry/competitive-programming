#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  
  for (int i = 1; i <= n; ++i) {
    cout << (n + 1 - i) << " ";
  } cout << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}