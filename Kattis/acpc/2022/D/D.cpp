#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln "\n"
#define fs first
#define sc second
void solve() {
  string s;
  getline(cin, s);
  s = " " + s;
  // cout << s;
  string ids; cin >> ids;
  int n = ids.size();
  string res = "";
  for (int i = 0; i < n; i=i+3) {
    string id = ids.substr(i, 3);
    int j = stoi(id);
    // cout<< j << ln;
    res += s[j];
  }
  cout << res;
}

int main() {
  solve();
  return 0;
}