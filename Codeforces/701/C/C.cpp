#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  unordered_set<char> chars;
  vector<int> cnt('z' + 5);
  for (char c : s) chars.insert(c);
  int m = chars.size();
  // cout << m << "\n";
  int pick = 0;
  int res = n;

  for (int r = 0, l = 0; r < n; ++r) {
    if (cnt[s[r]] == 0) ++pick;
    // cout << pick << "\n";
    ++cnt[s[r]];
    
    while (pick == m && l <= r) {
      // cout << pick << "\n";
      // cout << l << " " << r << "\n";
      res = min(r - l + 1, res);
      
      --cnt[s[l]];
      if (cnt[s[l]] == 0) --pick;
      ++l;
    }
  }

  cout << res;
}

int main() {
  cin.tie(0); cout.tie(0);
  ios_base::sync_with_stdio(0);
  solve();
  return 0;
}