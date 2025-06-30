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

// can I place sheets such that they do not overlap and cover the w x h
void solve() {
  // w, h -> roof
  // a, b -> sheets
  ll w, h, a, b; cin >> w >> h >> a >> b;
  // placed sheets
  ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;

  ll x = (x2 - x1) % a == 0;
  ll y = (y2 - y1) % b == 0;

  bool res = (x && abs(x1 - x2) >= a) || (y && abs(y1-y2) >= b) || (x && y);
  if (res) cout << "YES" << ln;
  else cout << "NO" << ln;
}

int main() {
  flash;
  int t; cin >> t;
  rep(i, t)
    solve();
  return 0;
}