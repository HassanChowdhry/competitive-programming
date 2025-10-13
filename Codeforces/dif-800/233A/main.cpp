#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long
#define ump unordered_map
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ln "\n"

void solve() {
  int n; cin >> n;

  if (n % 2) { cout << -1; return; }

  for (int i = 1; i <= n; ++i) {
    if (i % 2) cout << i + 1 << " ";
    else cout << i - 1 << " ";
  }

}

int main() {
  flash;
  solve();
  return 0;
}