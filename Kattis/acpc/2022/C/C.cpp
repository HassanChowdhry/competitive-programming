#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ln "\n"

// vector<vector<ll>> dp(8, vector<ll>(10000005, -1));
// ll n, s;
// vector<ll> digs;
// ll poww[10][24];

// ll rec(ll d, ll num) {
//   if (dp[d][num] != -1) return dp[d][num];
//   if (d == s && num == n) return 1;
//   if (d == s || num > n) return 0;

//   ll res = 0;
//   for (ll p = 0; p <= 23; ++p) {
//     ll pp = poww[digs[d]][p];
//     if (pp > n) break;

//     ll next = num + pp;
//     if (next > n) break;

//     res += rec(d + 1, next);
//   }

//   dp[d][num] = res;
//   return dp[d][num];
// }

// void solve() {
//   cin >> n;
//   string d = to_string(n);
//   s = d.size();
//   for (char c: d) digs.push_back(c-'0');
//   for (int i = 2; i < 10; ++i) {
//     for (int j = 0; j < 24; ++j) {
//       poww[i][j] = pow(i, j);
//     }
//   }
//   ll ways = rec(0, 0);
//   cout << ways;
// }


ll dp[8][10000005];
ll n, s;
vector<ll> digs;
ll poww[10][24];

void solve2() {
  cin >> n;
  string digits = to_string(n);
  s = digits.size();
  for (char c: digits) digs.push_back(c-'0');
  for (int i = 2; i < 10; ++i) {
    for (int j = 0; j < 24; ++j) {
      poww[i][j] = pow(i, j);
    }
  }

  dp[0][0] = 1;
  for (int d = 0; d < s; ++d) {
    for (int num = 0; num <= n; ++num) {
      if (dp[d][num] == 0) continue;
      for (int p = 0; p <= 23; ++p) {
        ll pp = poww[digs[d]][p];
        if (pp > n) break;
        ll next = pp + num;
        if (next > n) break;
        dp[d + 1][next] += dp[d][num];
      }
    }
  }

  cout << dp[s][n];
}



int main() {
  // solve1();
  solve2();
  return 0;
}