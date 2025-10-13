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
ll powMod(ll a,ll n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

const int MAXN = 100, MAXK = 10;
vector<vl> dp(MAXN+1, vl(MAXK + 1));
ll fact[MAXN + 1], invfact[MAXN + 1];

ll modpow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % MOD;
        n >>= 1;
    }
    return res;
}
 
void init_fact() {
  fact[0] = 1;
  for (int i = 1; i <= MAXN; ++i) fact[i] = (fact[i-1] * i) % MOD;

  invfact[MAXN] = modpow(fact[MAXN], MOD - 2);

  for (int i = MAXN-1; i >= 0; --i) invfact[i] = (invfact[i+1] * (i + 1)) % MOD;
}

// combinations code
ll nCr(int n, int r) {
  if (r < 0 || r > n) return 0;
  return (((fact[n] * invfact[r] ) % MOD) * invfact[n - r] % MOD);
}

void solve() {
  int n, k; cin >> n >> k;

  init_fact();
  // dp[i][j] = comb(i, j) ∑ dp[i - j][x]
  
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= min(k, i); ++j) {
      if (i == j) { dp[i][j] = 1; continue; }
      
      ll ways = 0;
      for (int x = 1; x <= min(k, i - j); ++x) {
        ways += dp[i-x][x] % MOD;
        ways %= MOD;
      }

      dp[i][j] = (ways * nCr(i, j)) % MOD;
    }
  }
  
  ll res = 0;
  for (int i = 0; i <= k; ++i) {
    res += dp[n][i] % MOD;
    res %= MOD;
  }
  cout << res;

}

int main() {
  flash;
  // int t; cin >> t;
  // rep(i, t) 
  solve();
  return 0;
}