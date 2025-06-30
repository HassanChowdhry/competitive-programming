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
  ll k, a, b, x, y; cin >> k >> a >> b >> x >> y;

  if (x > y) { swap(x, y); swap(a, b); }

  // cout << a << " " << b << ln;
  // cout << x << " " << y << ln;
  // what is the max a * x.
  ll l = 0, r = k + 1, res = 0;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (k - (mid * x) >= a) {
      l = mid + 1;
      res = max(res, mid);
    } else {
      r = mid - 1;
    }
  }
  if (k - (res * x) >= a) res += 1;
  k -= (res * x);

  l = 0, r = k + 1;
  ll p = 0;
  while (l <= r) {
    ll mid = (l + r) / 2;
    if (k - (mid * y) >= b) {
      l = mid + 1;
      p = max(p, mid);
    } else {
      r = mid - 1;
    }
  }

  if (k - (p * y) >= b) p += 1;

  cout << res + p << ln;
}

int main() {
  flash;
  int t; cin >> t;
  rep(i, t)
    solve();
  return 0;
}