#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ump unordered_map
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ln "\n"

void solve() {
  string s; cin >> s;

  vector<int> cnt(26);
  for (char c : s) {
    ++cnt[c - 'a'];
  }

  int un = 0;
  for (int n: cnt) {
    if (n >= 1) ++un;
  }

  if (un % 2) cout << "IGNORE HIM!";
  else cout << "CHAT WITH HER!";
}

int main() {
  flash;
  solve();
  return 0;
}