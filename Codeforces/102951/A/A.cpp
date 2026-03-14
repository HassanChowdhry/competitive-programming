#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<long long> x(n), y(n);

  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> y[i];
  }
  long long res = 0;

  for (int i = 0; i < n - 1; ++i) {
    for (int j = i + 1; j < n; ++j) {
      res = max(
        res,
        (long long) (pow(x[i] - x[j], 2) + pow(y[i] - y[j], 2))
      );
    }
  }

  cout << res;
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); cout.tie(NULL);
  solve();
  return 0;
}