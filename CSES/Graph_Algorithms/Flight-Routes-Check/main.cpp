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


void dfs(int node, vector<vi>& edges, vi& vis) {
  if (vis[node]) return;
  // cout << node << ' ';
  vis[node]=1;
  for (int child: edges[node]) {
    if (vis[child]) continue;
    dfs(child, edges, vis);
  }
}

void solve() {
  int n, k, u, v; cin >> n >> k;
  vector<vi> edges(n + 1);
  vector<vi> redges(n + 1);
  vi vis(n + 1,0);
  vi vis2(n + 1);

  for (int i = 0; i < k; ++i) {
    cin >> u >> v;
    edges[u].pb(v);
    redges[v].pb(u);
  }
  // u, v is a directed edge
  dfs(1, edges, vis);
  // cout << vis[1] << " " << vis[2];
  for (int i=2; i <= n; ++i) {
    if (!vis[i]) { cout << "NO" << ln << 1 << " " << i; return; }
  }

  // cout << ln;
  dfs(1, redges, vis2);
  // cout << vis[1] << " " << vis2[2];
  for (int i=2; i <= n; ++i) {
    if (!vis2[i]) { cout << "NO" << ln << i << " " << 1; return; }
  }

  cout << "YES";
}

int main() {
  flash;
  solve();
  return 0;
}