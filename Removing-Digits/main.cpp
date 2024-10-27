#include <bits/stdc++.h>
#define MOD 1000000007
#define inf 1000000007
#define ll long long
using namespace std;

int main() {
  ll n; cin >> n;
  vector<ll> dp(n+1, inf);
  dp[n] = 0;
  string num; ll curr;

  for (ll i = n; i > 0; --i) {
    if (dp[i] >= inf)
      { continue; }
    num = to_string(i);

    for (ll j = 0; j < num.size(); ++j) {
      curr = num[j] - '0';
      // curr = j;
      if ((i - curr) >= 0)
        { dp[i-curr] = min(dp[i-curr], 1 + dp[i]); } 
      // cout << i << " " << curr << " " << dp[i] << " " << "\n" ;
    }
  }

  cout << dp[0];
}
