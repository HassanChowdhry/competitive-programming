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
int MOD=1000000007;

int ans = 0;

void dfs(int node, int parent, vector<bool>& visit, vector<vector<int>>& adj) {
  for (int edge: adj[node]) {
    if (edge == parent) continue;
    dfs(edge, node, visit, adj);
    if (!visit[node] && !visit[edge]) {
      visit[node] = visit[edge] = true; ++ans;
    }
  }
}

void solve() {
  int n; cin >> n;
  vector<vector<int>> adj(n+1);
  vector<bool> visit(200005, false);

  int a, b;
  rep(i, n-1) {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  dfs(1, -1, visit, adj);

  cout << ans;

}

int main() {
  flash;
  solve();
  return 0;
}