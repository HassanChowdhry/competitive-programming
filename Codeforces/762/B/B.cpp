#include <bits/stdc++.h>
using namespace std;

void solve() {
  int a, b, c; cin >> a >> b >> c;
  int m; cin >> m;
  vector<pair<long long, int>> mice(m);
  for (int i = 0; i < m; ++i) {
    long long cost; string mouse; cin >> cost >> mouse;
    int m_id = mouse == "USB" ? 0: 1;
    mice[i] = { cost, m_id };
  }
  sort(mice.begin(), mice.end());

  long long res = 0;
  int computers = 0;
  for (int i = 0 ; i < m; ++i) {
    if ( a == b && b == c && c == 0 ) break;

    auto [cost, id] = mice[i];
    if (id == 0) {
      if (a > 0) {
        res += cost; ++computers;
        --a;
      } else if (c > 0) {
        res += cost; ++computers;
        --c;
      }
    } else {
        if (b > 0) {
        res += cost; ++computers;
        --b;
      } else if (c > 0) {
        res += cost; ++computers;
        --c;
      }
    }
  }

  cout << computers << " " << res;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); cout.tie(0);
  solve();
  return 0;
}