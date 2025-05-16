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
int MOD=1000000007;

ll getans(ll num, vector<ll>& dp) {
  if (num < 1) return num == 0 ? 1: 0;
  ll res = 0;
  string numString = to_string(num);
  rep(i, numString.size()) {
    res += dp[i];
  }

  ll prev = 0;
  rep(i, numString.size()) {
    ll digit = numString[i] - '0';
    ll diff = numString.size() - i - 1;
    ll below = prev < digit ? digit - 1: digit;
    res += (digit == 0) ? 0: below * dp[diff];
    if (digit == prev) return res;
    prev = digit;
  }

  return res+1;
}

void solve() {
  ll a, b; cin >> a >> b;
  ll n = 19;
  vector<ll> dp(n, 0);
  dp[0] = 1;
  repx(i, 1, n)
    dp[i] = (dp[i-1] * 9);
  
  cout << getans(b, dp) - getans(a-1, dp);
}

int main() {
  flash;
  solve();
  return 0;
}