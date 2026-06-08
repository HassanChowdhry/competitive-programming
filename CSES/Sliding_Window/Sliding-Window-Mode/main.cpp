#include <bits/stdc++.h>
using namespace std;


void solve() {
  int n, k; cin >> n >> k;

  vector<int> a(n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  set<pair<int, int>> heap;
  map<int, int> cnt;

  for (int i = 1; i < k; ++i) {
    heap.erase({ cnt[a[i]], -a[i] });
    ++cnt[a[i]];
    heap.insert({ cnt[a[i]], -a[i] });
  }

  int j = 1;
  for (int i = k; i <= n; ++i) {
    heap.erase({ cnt[a[i]], -a[i] });
    ++cnt[a[i]];
    heap.insert({ cnt[a[i]], -a[i] });

    pair<int, int> x = *heap.rbegin();

    cout << -x.second << " ";

    heap.erase({ cnt[a[j]], -a[j] });
    --cnt[a[j]];
    heap.insert({ cnt[a[j]], -a[j] });
    ++j;
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}