#include <bits/stdc++.h>
using namespace std;

void solve() {
  int r, g, b; cin >> r >> g >> b;
  vector<char> rgb = {'R', 'G', 'B'};

  // if (r == g && g == b && r == b) {
  //   string s = "";
  //   for (int i = 0; i < r; ++i) {
  //     int a = i % 3, b = (i + 1) % 3, c = (i + 2) % 3;
  //     s += rgb[a];
  //     s += rgb[b];
  //     s += rgb[c];
  //   }
  //   cout << s << "\n";
  //   return;
  // }

  
  auto can = [&](string& s, char c) -> bool {
    int n = s.size();
    if (n >= 1 && s[n - 1] == c) return false;
    if (n >= 3 && s[n - 3] == c) return false;
    return true;
  };
  
  auto check = [&](vector<int> order, vector<int> cnt) -> string {
    string s = "";
    while (true) {
      int n = s.size();
      int take1 = -1;
      int take2 = -1;
      for (int i = 0 ; i < 3; ++i) {
        if (!can(s, rgb[i])) continue;
        if (cnt[i] == 0) continue;

        int ok = 0;
        if (n < 2 || rgb[i] == s[n - 2]) {
          ok = 1;
        } else {
          for (int j = 0; j < 3; ++j) {
            if (rgb[j] != rgb[i] && rgb[j] != s[n-2] && cnt[j] > 0)
              ok = 1;
          }
        }

        if (ok) {
          if (take1 == -1 || cnt[take1] < cnt[i] || (cnt[take1] == cnt[i] && order[take1] > order[i]))
            take1 = i;
        } else {
          if (take2 == -1 || cnt[take2] < cnt[i] || (cnt[take2] == cnt[i] && order[take2] > order[i]))
            take2 = i;
        }

      }
      int take;
      if (take1 != -1) take = take1;
      else take = take2;
      if (take == -1) break;
      s += rgb[take];
      --cnt[take];
    }

    return s;
  };

  vector<string> ans(6);
  vector<int> cnt = {r, g, b};
  ans[0] = check({0, 1, 2}, cnt);
  ans[1] = check({0, 2, 1}, cnt);
  ans[2] = check({1, 0, 2}, cnt);
  ans[3] = check({1, 2, 0}, cnt);
  ans[4] = check({2, 1, 0}, cnt);
  ans[5] = check({2, 0, 1}, cnt);

  string res = "";
  for (const string& s : ans) {
    if (s.size() > res.size()) res = s;
  }

  cout << res << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while (t--)
  solve();
  return 0;
}