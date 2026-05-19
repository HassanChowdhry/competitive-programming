#include <bits/stdc++.h>
using namespace std;

void solve() {
  string s; cin >> s;
  int n = (int) s.size();
  
  vector<int> cnt = {0, 0}; 
  ++cnt[s[0]-'0'];

  for(int i = 1; i < n; ++i) {
    if (s[i] != s[i - 1]) {
      ++cnt[s[i]-'0'];
    }
  }

  if (cnt[0] >= 2) {
    cout << "2" << "\n";
  } else if (cnt[0] == 1) {
    cout << "1" << "\n";
  } else {
    cout << "0" << "\n";
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while (t--)
  solve();
  return 0;
}