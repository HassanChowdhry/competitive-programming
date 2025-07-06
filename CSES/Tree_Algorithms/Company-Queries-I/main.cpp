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
#define vll vector<vl>
int MOD=1000000007;

void getdepth(int node, int d, vl& depth, vll& adj) {
  depth[node] = d;
  for (int child: adj[node]) getdepth(child, d + 1, depth, adj);
}

void solve() {
  int n, q; cin >> n >> q;
  int LOG = 20;
  vector<ll> parent(n + 1, 0);
  repx(i, 2, n + 1) cin >> parent[i];
  vll dp(n + 1, vl(LOG, 0));
  vll adj(n + 1); vl depth(n + 1);

  repx(i, 2, n + 1) adj[parent[i]].pb(i);
  getdepth(1, 0, depth, adj);

  repx(i, 1, n + 1) dp[i][0] = parent[i];
  repx(p, 1, LOG) {
    repx(i, 1, n + 1) dp[i][p] = dp[ dp[i][p-1] ][p-1];
  }
  
  int node, k;
  rep(_, q) {
    cin >> node >> k;
    if (depth[node] < k) { cout << -1 << ln; continue; }
    rep(i, LOG) {
      if (k & ( 1 << i )) node = dp[node][i];
    }
    cout << node << ln;
  }
}

int main() {
  flash;
  solve();
  return 0;
}