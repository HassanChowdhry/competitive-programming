#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;

  string res = "";
  int zero = 0, one = 0;

  for (char c: s) {
    if (c == '0' && !zero) {
      zero = 1; continue;
    } else if (c == '1' && !one) {
      one = 1; continue;
    }

    res += c;
  }

  cout << res << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while(t--)
  solve();
  return 0;
}