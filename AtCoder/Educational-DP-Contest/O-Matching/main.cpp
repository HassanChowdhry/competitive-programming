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

// // int can[21][21];
// ll dp[21][1<<21];
// // int n;

// ll rec(int i, int mask) {
//   // cout << i << ' ' << j << ln;
//   if ( i == n ) { return 1; }
//   if (dp[i][mask] != -1) return dp[i][mask];

//   ll res = 0;
//   for (int j = 0; j < n; ++j) {
//     if (!(mask & (1 << j)) && can[i][j]) {
//       res += rec(i + 1, mask | (1 << j)) % MOD;
//       res %= MOD;
//     }
//   }

//   dp[i][mask] = res;
//   return res;
// }

// void solve1() {
//   // DP WITH BIT MASKING
//   cin >> n;
//   rep(i, n) rep(j, n) cin >> can[i][j];
//   for (int i =0; i < n; ++i) {
//     for (int j = 0; j < (1 << n); ++j) {
//       dp[i][j] = -1;
//     }
//   }
//   ll res = rec(0, 0)%MOD;
//   cout << res;
// }

void solve() {
  // DP WITH BIT MASKING
  int n; cin >> n;
  vector<ll> dp( 1 << n );
  int can[21][21];

  dp[0] = 1;
  rep(i, n) rep(j, n) cin >> can[i][j];

  for (int mask = 0; mask < (1 << n); ++mask) {
    // instead of going over the rows, ( the 1's in the mask encodes which row we are at )
    int i = __builtin_popcount(mask);

    for (int j = 0; j < n; ++j) {
      // I am at a state, where can I push out the correct values from my state
      // if (!(mask & ( 1<< j )) && can[i][j]) {
        // push dp -> from this state, fill in the next state
        // int next_mask = mask | ( 1 << j );
        // dp[next_mask] += dp[mask] % MOD; 
        // dp[next_mask] %= MOD;
      // }


      // pull transition, get from previous possible state, if I am at a correct state.
      // where could I can come from a previous state i-1, for all j
      if (mask & ( 1<< j ) && can[i-1][j]) {
        int prev_mask = mask ^ ( 1 << j );
        dp[mask] += dp[prev_mask] % MOD;
        dp[mask] %= MOD;
      }
    }
  }

  
  cout << dp[( 1<< n )-1] %MOD;
}

int main() {
  flash;
  solve();
  // solve1();
  return 0;
}