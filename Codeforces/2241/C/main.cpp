#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;

  if (n == 1) {
    cout << 1 << "\n";
    return;
  }

  int sw = 0;
  char b = s[0];
  
  for (char c : s) {
    if (b != c) {
      ++sw; b = c;
    }
  }

  if (sw == 1) {
    cout << 2 << "\n";
  } else cout << 1 << "\n";

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  
  int t; cin >> t;
  while (t--)
  solve();
  
  return 0;
}