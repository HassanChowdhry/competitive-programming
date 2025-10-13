#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ump unordered_map
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ln "\n"

void solve() {
  int t; cin >> t;
  int res = 0;
  for (int i = 0; i < t; ++i) {
    int x, y, z; cin >> x >> y >> z;
    int check = x + y + z;
    if (check > 1) ++res;
  }
  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}