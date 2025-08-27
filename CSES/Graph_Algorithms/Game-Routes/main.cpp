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

ll dfs(int node, int n, vector<ll>& ways, vector<vi>& adj) {
  if (node == n) return 1LL;
  if (ways[node] >= 0) return ways[node];
  ll res = 0;
  for (int child: adj[node]) {
    res += dfs(child, n, ways, adj) % MOD;
  }
  ways[node] = res % MOD;
  return ways[node];
}
void solve() {
  int n, k; cin >> n >> k;
  vector<vi> adj(n + 1), radj(n + 1);
  vector<ll> ways(n + 1, -1);
  rep(i,k) {
    int u, v; cin >> u >> v;
    adj[u].pb(v);
    radj[v].pb(u);
  }

  ll res = dfs(1, n, ways, adj);
  // ll res2 = dfs(n, 1, ways, radj);
  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}