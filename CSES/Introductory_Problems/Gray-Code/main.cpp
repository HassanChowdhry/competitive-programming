#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define ln "\n"

string int_to_bit_string(int num, int n) {
  bitset<32> bits(num);
  string bit_str = bits.to_string();
  return bit_str.substr(32 - n);
}

void rec(int curr, int n, set<int>& vis) {
  if (vis.count(curr) || vis.size() == (1 << n)) return;
  vis.insert(curr);
  cout << int_to_bit_string(curr, n) << ln;

  for (int idx = 0; idx < n; ++idx) {
    int mask = 1 << idx;
    int next = curr ^ mask;
    if (!vis.count(next)) {
      rec(next, n, vis); break;
    }
  }
}

void solve() {
  int n; cin >> n;
  set<int> vis;

  rec(0, n, vis);
}

int main() {
  flash;
  solve();
  return 0;
}