#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> a(n + 1);
  vector<int> cnt(1001);
  int ans = 0, res = 0, check;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    ++cnt[a[i]];
    ++ans;
    res += a[i];
  }

  int m1 = 0;
  check = a[0];

  for (int i = 1; i <= 1000; ++i) {
    // if (cnt[i]) cout << cnt[i] << " ";
    if (m1 < cnt[i]) {
      check = i;
      m1 = max(m1, cnt[i]);
    }
  }

  ans -= m1;
  if (ans > m1) {
    cout << res << "\n";
  } else {
    // 5, 6
    if (m1 > ans + 2) {
      res -= m1 * check;
      res += (ans + 2) * check;
    }
    cout << res << "\n";
  }
  

}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t; 
  cin >> t;
  while(t--)
  solve();
  return 0;
}

// 2 3 6

// a b c

// c b c b c b c a c a c