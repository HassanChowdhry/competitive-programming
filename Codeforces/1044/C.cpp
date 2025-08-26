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

// ? x k s1 s2 ... sk -> query
// ! k v1 v2 ... vk -> done
// and flush after every query.
// -1 -> exit
ll ask(ll x, vl& S) {
  cout << "? " << x << " " << S.size();
  for (ll n: S) cout << " " << n; cout << endl;
  
  ll res;
  if (!(cin >> res)) exit(0);
  if (res == -1LL) exit(0);
  return res;
}

void solve() {

  ll n; cin >> n; if (n == -1) return;

  vl nums(n), dp(n+1, 1); rep(i, n) nums[i] = i+1;

  // longest starting from all n
  for (ll x = 1; x <= n; ++x) dp[x] = ask(x, nums);

  ll mx = 0;
  for (ll x = 1; x <= n; ++x) mx = max(mx, dp[x]);

  // VALUE -> STARTING MAPPING
  vector<vl> mp(mx+1);
  ll start = 0;
  for (ll x = 1; x <= n; ++x) { 
    mp[dp[x]].pb(x);
    if (dp[x] == mx) start = x;
  }

  vl path; path.pb(start);

  vl res;
  vi vis(n + 1); 

  for (int x = dp[start]; x >= 2; --x) {
    ll u = path.back();

    ll next = -1;
    for (ll val: mp[x - 1]) {
      if (vis[val]) continue;
      vis[val] = 1;

      // vis[val] = 1;
      // res.pb(val);
      vl S; S.pb(u);
      for (ll v : res) if (v != u) S.pb(v);
      if (val != u) S.pb(val);
      ll longest = ask(u, S);
      if (longest == 2) {
        next = val; break;
      } else {
        res.pb(val);
      }
    }
    path.pb(next);
  }

  cout << "! " << path.size();
  for (ll v: path) cout << " " << v;
  cout << endl;

}

int main() {
  flash;
  int t; cin >> t;
  rep(_,t)
    solve();
  return 0;
}