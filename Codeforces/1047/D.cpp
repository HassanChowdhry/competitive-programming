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
  ll n; cin >> n;
  vector<ll> b(n); rep(i, n) cin >> b[i];
  vector<ll> buckets(n + 1);
  vector<vl> mp(n+1);
  for (int i = 0; i < n; ++i) {
    ++buckets[b[i]];
    mp[b[i]].pb(i);
  }

  for (int val = 1; val <= n; ++val) {
    ll rem = buckets[val] % val;
    if (rem != 0) { cout << -1 << ln; return; }
  }

  vector<ll> a(n);
  ll ai = 1;
  for (int i = 1; i <= n; ++i) {
    vector<ll> tmp = mp[i];
    for (int j = 0; j < tmp.size(); j += i) {
      for (int k = j; k < j + i; ++k) {
        a[tmp[k]] = ai;
      }
      ++ai;
    }
  }

  rep(i, n) {
    if (i) cout << " ";
    cout << a[i];
  }
  cout << ln;
  

}

int main() {
  flash;
  int t; cin >> t;
  rep(i, t) 
    solve();
  return 0;
}