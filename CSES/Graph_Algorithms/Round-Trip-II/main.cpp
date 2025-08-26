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

bool cycleCheck(int node, map<int, int>& vis, deque<int>& q, vector<vi>& adj) {
  if (vis[node] == 1) return true;
  if (vis[node] == 2) return false;
  vis[node] = 1;

  q.pb(node);

  for (int child: adj[node]) {
    if (vis[child] == 0) {
      bool check = cycleCheck(child, vis, q, adj);
      if (check) return check;
    } else if (vis[child] == 1) {
      q.pb(child);
      return true;
    }
  }

  q.pop_back();
  vis[node] = 2;
  return false;
}
void solve() {
  int n, m; cin >> n >> m;
  vector<vi> adj(n+1);
  int u, v;
  rep(i, m) { cin >> u >> v; adj[u].pb(v); }
  deque<int> q;
  map<int, int> vis;

  bool cycle = false;
  for (int i = 1; i <= n; ++i) {
    if (cycleCheck(i, vis, q, adj)) { cycle = true; break; }
  }

  while (!q.empty() && q.front() != q.back()) q.pop_front();
  if (!cycle) { cout << "IMPOSSIBLE"; return; }

  cout << q.size() << ln;
  while (!q.empty()) {
    cout << q.front() << " ";
    q.pop_front();
  }
 
}

int main() {
  flash;
  solve();
  return 0;
}