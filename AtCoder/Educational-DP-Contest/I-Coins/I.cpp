#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define all(a) a.begin(),a.end()
#define mod(num, n) (num % n + n) % n
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test int t;cin>>t;while(t--)
#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,x,n) for(int i=x;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define rem(mp, el) if(mp[el]==0)mp.erase(el)
#define ln "\n"
#define vi vector<int>
#define vl vector<ll>
int MOD=1000000007;

void solve() {
  int n; cin >> n;

  vector<double> p(n); for(int i = 0; i < n; ++i) cin >> p[i];

  int heads = (n / 2) + 1;
  int k = n - heads; // tails
  // cout << k;

  vector<vector<double>> dp(n, vector<double>(k + 1));

  dp[0][0] = p[0];
  dp[0][1] = 1.0 - p[0];
  //for (int i = 1; i <= k; ++i) dp[0][i] = 1.0 - p[0];
  for (int i = 1; i < n; ++i) dp[i][0] = dp[i-1][0] * p[i];

  // we find all probabilities of having exactly k tails
  for (int i = 1; i < n; ++i) {
    for (int j = 1 ; j <= k ; ++j ) {
      dp[i][j] = dp[i-1][j-1] * (1.0 - p[i]) + dp[i-1][j] * p[i];
    }
  }

  double res = 0.0;

  for (int i = 0; i <= k; ++i) res += dp[n-1][i];
  cout << fixed << setprecision(10) << res;
  // for (int i = 0; i < n; ++i) {
  //   for (int j = 0; j <= k; ++j) {
  //     cout << dp[i][j] << " ";
  //   } cout << ln;
  // }
}

int main() {
  flash;
  solve();
  return 0;
}

