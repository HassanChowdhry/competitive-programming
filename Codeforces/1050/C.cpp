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
  ll n, m, a, b; cin >> n >>m;
  ll res = 0;
  ll pa = 0, pbb = 0;
  rep(i, n) {
    cin >> a >> b;
    if ((a - pa) % 2 == ((b - pbb + 2) % 2)) {
      res += (a - pa);
    } else {
      res += (a - pa - 1);
    }
    pa = a, pbb = b;
  }

  res += (m - pa);
  cout << res << ln;
}

int main() {
  flash;
  int t; cin >> t;
  rep(i, t) 
  solve();
  return 0;
}