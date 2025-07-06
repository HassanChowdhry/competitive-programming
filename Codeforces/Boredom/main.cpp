#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define all(a) a.begin(),a.end()
#define mod(num, n) (num % n + n) % n
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(ll i=0;i<n;++i)
#define repx(i,x,n) for(ll i=x;i<n;++i)
#define ln "\n"
#define vi vector<int>
#define vl vector<ll>
int MOD=1000000007;

void solve() {
  ll n, num, mx = 0; cin >> n;
  vl nums(n, 0); rep(i, n) { cin >> num; mx = max(mx, num); nums[i] = num; }
  ll m = mx + 1;
  vl frq(m, 0), dp(m, 0); rep(i, n) ++frq[nums[i]];
  dp[1] = frq[1];
  repx(i, 2, m) {
    dp[i] = max(dp[i-1], i * frq[i] + dp[i - 2]);
  }
  cout << dp[m-1];
}

int main() {
  flash;
  solve();
  return 0;
}