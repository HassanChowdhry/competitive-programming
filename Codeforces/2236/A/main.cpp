#include <bits/stdc++.h>
using namespace std;

int n;
const int maxN = 6;
int h[maxN];

void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> h[i];

  int M = 1;

  for (int i = 1; i <= n; ++i) {
    for (int j = i + 1; j <= n; ++j) {
      M = max(M, abs(h[i] - h[j]) + 1);
    }
  }

  cout << M << "\n";
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  int t; cin >> t;
  while(t--)
  solve();
  return 0;
}
