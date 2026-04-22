#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> divs(100001);

void init() {
  for (int i = 1; i <= 100000; i++) {
    for (int j = i; j <= 100000; j += i) {
      divs[j].push_back(i);
    }
  }
}

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  
  for (int i = 0; i < n; ++i ) {
    cin >> a[i];
  }
  
  sort(a.begin(), a.end());
  
  // int an = 1e5 + 1;
  vector<int> cnt(a[n-1] + 1);
  
  auto f = [&](int x, int parity) -> int {
    int res = 0;

    for (int d : divs[x]) {
      if (d > m) break;

      cnt[d] += parity;

      if ((parity == 1 && cnt[d] == 1) ||
          (parity == -1 && cnt[d] == 0)) {
        ++res;
      }
    }

    return res * parity;
  };

  auto valid = [&](int val) -> bool {
    int l = 0, r = 0;
    int pick = 0;
    int res = 0;

    while (r < n) {
      pick += f(a[r], 1);
      
      while (l < r && a[r] - a[l] > val) {
        pick += f(a[l], -1);
        ++l;
      }

      res = max(res, pick);
      
      ++r; 
    }
    
    // cout << " " << val << " " << pick << "\n";
    // cout << n << "\n";
    return res >= m;
  };

  int ans = -1;
  int l = 0, r = a[n-1] - a[0];
  while (l <= r) {
    int mid = (l + r) / 2;

    fill(cnt.begin(), cnt.end(), 0);
    if (valid(mid)) {
      r = mid - 1;
      ans = mid;
    } else {
      l = mid + 1;
    }
  }

  cout << ans << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  init();
  int t; cin >> t;
  while (t--) solve();
  return 0;
}