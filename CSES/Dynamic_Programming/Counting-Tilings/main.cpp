#include <bits/stdc++.h>
using namespace std;

#define ll long long
int dp[(1<<11)][1001];

const int oo = 1e9 + 7;
int n, m; 

void fill_col(int col, int i, int mask, int next_mask) {
  if (i == n) {
    dp[next_mask][col + 1] = (dp[mask][col] + dp[next_mask][col+1]) % oo;
    return;
  }

  if (mask & (1 << i)) {
    fill_col(col, i + 1, mask, next_mask);
  } else {
    fill_col(col, i + 1, mask, (next_mask | (1 << i))); // horizontal block

    if (i + 1 < n && (!(mask & ( 1 << (i+1) )))) {
      fill_col(col, i + 2, mask, next_mask); // horizontal block
    }
  }
}

void solve() {
  cin >> n >> m;

  dp[0][0] = 1;

  for (int i = 0; i < m; ++i) {
    for (int mask = 0; mask < (1 << n); ++mask) {
      if (dp[mask][i] > 0) {
        fill_col(i, 0, mask, 0);
      }
    }
  }
  
  cout << dp[0][m];
  
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}