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
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

void solve() {
  int n, k; cin >> n >> k; 

  if (k == 0) {
    cout << 1; return;
  }
  vector<ll> nums(n);
  rep(i, n) cin >> nums[i];

  vector<vl> dp(n+1, vl(k+1, 0));
  for (int i = 1; i <= n; ++i) dp[i][0] = 1;
  for (int i = 1; i <= k; ++i) {
    if (i > nums[0]) break;
    dp[1][i] = 1;
  }

  for (int i = 2; i <= n; ++i) {
    vector<ll> prefix(k + 2, 0);
    prefix[0] = dp[i-1][0] % MOD;
    for (int j = 1; j <= k; ++j) {
      prefix[j] += (prefix[j-1] % MOD + dp[i-1][j] % MOD) % MOD;
    } 
    for (int j = 1; j <= k; ++j) {
      int left = max(j - nums[i-1] - 1, -1LL);
      if (left < 0) dp[i][j] = prefix[j] % MOD;
      // if the prefix overflows at j but not at left then we have a problem? 
      else {
        int x = prefix[j] % MOD;
        int y = prefix[left] % MOD;
        if (x < y) x += MOD; // wrap around, this is to handle the overflow problem
        dp[i][j] = (x - y) % MOD;
      }
    }
  }

  // for (int i =0; i <= n; ++i) {
  //   for (int j = 0; j <= k; ++j) {
  //     cout << dp[i][j] << " ";
  //   }
  //   cout << ln;
  // }

  cout << dp[n][k] % MOD;
  // cout << ln;
  // for (int i =0 ; i < 100; ++i) {
  //   cout << 100000 << " ";
  // }
}

int main() {
  flash;
  solve();
  return 0;
}