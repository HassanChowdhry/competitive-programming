#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n); for (int i = 0; i < n; ++i) cin >> a[i];
  map<int, int> cnt;
  ordered_set<int> ost;

  auto find = [&](int i, int j) -> int {
    int res = j + 1;
    while (i <= j) {
      int m = (i + j) / 2;

      if (ost.find(m) == ost.end()) res = min(res, m);

      // cout << m << " " << ost.order_of_key(m) << "\n";
      if (ost.order_of_key(m) != m) {
        j = m - 1;
      } else {
        i = m + 1;
      }
    }

    return res;
  };

  int r;
  for (r = 0; r < k - 1; ++r) {
    ++cnt[a[r]];
    ost.insert(a[r]);
  }
  int l = 0;
  for (; r < n;) {
    // add
    ++cnt[a[r]];
    ost.insert(a[r]);
    ++r;

    // check
    int min = *ost.begin();
    int max = *ost.rbegin();

    int res;
    if (min != 0) {
      res = 0;
    } else if (min == max) {
      res = 1;
    } else {
      res = find(min, max);
    }

    cout << res << " ";

    // remove
    --cnt[a[l]];
    if (!cnt[a[l]]) ost.erase(a[l]);
    ++l;
  }
}


int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}