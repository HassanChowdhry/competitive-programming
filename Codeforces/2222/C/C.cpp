#include <bits/stdc++.h>
using namespace std;

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  long long INF = 1e12;
  int n; cin >> n;
  vector<long long> a(n + 1);
  vector<long long> b(n + 1);
  map<int, int> cnt;
  
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    b[i] = a[i];
    // ++cnt[a[i]];
  }

  sort(b.begin() + 1, b.end());
  int med = b[(n + 1) / 2];
  // cout << med << "\n";
  vector<int> pre(n + 1);
  for (int i = 1; i <= n; ++i) {
    if (a[i] > med) {
      pre[i] = pre[i - 1] + 1;
    } else if (a[i] < med) {
      pre[i] = pre[i - 1] - 1;
    } else {
      pre[i] = pre[i - 1];
    }
  }
  
  // ordered_set<pair<long long, int>> ost;
  vector<long long> dp(n + 1, -INF);
  dp[0]=0;
  long long res = -INF;

  for (int i = 1; i <= n; ++i) {
    int m = 0;
    int j = i;

    // ost.insert({ a[j], j });
    ++m;
    // cout << i << " ";
    int ok = 0;
    if (a[i] == med) ok = 1;
    while (j >= 1) {
      // long long curr = (*ost.find_by_order(m / 2)).first;
      // cout << curr << " ";
      if (ok && pre[i] - pre[j-1] == 0 && dp[j-1] != -INF && (i - j + 1) % 2 == 1) {
          dp[i] = max(dp[i], 1 + dp[j-1]);
      }
      --j; if (a[j] == med) ok = 1;
      if (j == 0) break;
      --j; if (a[j] == med) ok = 1;
      m += 2;
      
    }
    // cout << "\n";
    // ost.clear();
  }
  // }

  cout << dp[n] << "\n";
  
}

int main() {
  int t; cin >> t;
  while (t--)
  solve();

  return 0;
}