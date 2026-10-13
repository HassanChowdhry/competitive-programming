#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;

  int x0,y0,s0;
  int x1,y1,s1;
  x0 = y0 = s0 = 0;
  double ans = 0, curr;
  for (int i = 1; i <= n; ++i) {
    cin >> x1 >> y1 >> s1;

    curr = sqrt(
      (x1 - x0) * (x1 - x0) + (y1 - y0) * (y1 - y0)
    ) / (double) s1;


    if (ans == 0) ans = curr;
    if (curr > ans) ans += curr;
    x0 = x1, y0 = y1, s0 = s1;
  }

  int M; cin >> M;
  cout << ans;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}