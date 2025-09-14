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
ll MOD=1e9 + 7;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

void solve() {
  string k; ll d, n; cin >> k >> d;
  // digit dp? dp[i][j] = with i digits how many ways I can make a sum J. if tight is on then we can only choose certain number
  // one thing I cannot account for is if k is not a power of ten, then how do I get rid of the excess
  n = k.length();
  // cout << d << ln;
  k = " " + k;
  // cout << k << ln;
  // cout << n << ln;
  vector<vl> dp(n + 1, vl(d, 0));

  for (ll i=0; i <= 9; ++i) ++dp[1][i%d];
  dp[0][0] = 1;

  for (ll digit = 2; digit <= n; ++digit) {
    for (ll sum = 0; sum < d; ++sum) {
      for (ll next_digit = 0; next_digit <= 9; ++next_digit) {
        dp[digit][sum] += (dp[digit-1][(sum - next_digit + 10*d)%d])%MOD;
        dp[digit][sum] %= MOD;
      }
    }
  }

  ll sum = 0, res = 0;

  for (ll digit = 1; digit <= n; ++digit) {
    for (ll curr = 0; curr < k[digit] - '0'; ++curr) {
      ll rem = (d - (sum + curr)%d + 10*d) % d;
      res += (dp[n-digit][rem]) % MOD; // free fill for all digits < Ki
      res %= MOD;
    }
    sum += k[digit]-'0';
    sum %= d;
  }

  res = (res + (sum == 0))%MOD;
  res = (res - 1 + MOD) % MOD;
  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}