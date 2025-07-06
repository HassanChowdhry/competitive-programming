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
  int r, c; cin >> r >> c; ++r; ++c;
  vector<vi> dp(r, vi(c, INT32_MAX));

  repx(i, 1, r) {
    repx(j, 1, c) {
      if (i == j) dp[i][j] = 0;
      repx(x, 1, i) dp[i][j] = min( dp[i][j], dp[x][j] + dp[i - x][j] + 1 );
      repx(y, 1, j) dp[i][j] = min( dp[i][j], dp[i][y] + dp[i][j - y] + 1 );
    }
  }

  cout << dp[r-1][c-1];
}

int main() {
  flash;
  solve();
  return 0;
}