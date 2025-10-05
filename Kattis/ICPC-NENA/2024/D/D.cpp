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

int n, x, y, d;
ll dp[35][105][105]; 

ll rec(int day, int b1, int b2) {
  if (day >= d) return 0;
  if (dp[day][b1][b2] != -1) return dp[day][b1][b2];

  ll cnt = 0;
  for (int nd1: {-1, 1}) {
    for (int nd2: {-1, 1}) {
      int nb1 = b1 + nd1;
      int nb2 = b2 + nd2;

      if (nb1 < 1) nb1 = 1;
      if (nb2 < 1) nb2 = 1;
      if (nb1 > n) nb1 = n;
      if (nb2 > n) nb2 = n;

      int m = nb1 == nb2;
      ll daysleft = max(0, d - day - 1);
      ll c = pow(4, daysleft);
      if (m) cnt += c;
      else {
        cnt += rec(day + 1, nb1, nb2);
      }
    }
  }

  return dp[day][b1][b2] = cnt;
}

void solve() {
  cin >> n >> x >> y >> d;

  rep(i, 35) rep(j, 105) rep(k, 105) dp[i][j][k] = -1;
  ll leaves = pow(4, d);
  ll res = rec(0, x, y);

  ll gcd = __gcd(res, leaves);
  res /= gcd;
  leaves /= gcd;

  cout << res << "/" << leaves;
}

int main() {
  flash;
  // int t; cin >> t;
  // rep(i, t) 
  solve();
  return 0;
}