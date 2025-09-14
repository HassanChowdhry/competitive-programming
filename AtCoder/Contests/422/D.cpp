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

vector<ll> get(ll n, ll k) {
  if (n == 0) return {k};

  ll l = k / 2;
  ll r = ceil(k/2.0);

  vector<ll> left = get(n-1, l);
  vector<ll> right = get(n-1, r);
  vector<ll> res;
  for(ll c: left) res.pb(c);
  for(ll c: right) res.pb(c);
  return res;

}
void solve() {
  ll n, k; cin >> n >> k;
  ll len = (1LL << n);
  ll u = (k % len == 0 ? 0: 1);

  cout << u << ln;
  
  vector<ll> res = get(n, k);

  for (ll c:res) cout << c << " ";
}

int main() {
  flash;
  solve();
  return 0;
}