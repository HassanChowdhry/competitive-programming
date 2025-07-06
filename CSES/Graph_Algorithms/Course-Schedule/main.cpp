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
#define vvi vector<vi>
#define vl vector<ll>
int MOD=1000000007;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

bool cycleCheck(int node, vi& vis, vvi& adj) {
  if (vis[node] == 2) return true;

  vis[node] = 1;

  for (int child: adj[node]) {
    if (vis[child] == 1) {
      return false;
    }
    else if (vis[child] == 0) {
      if (!cycleCheck(child, vis, adj)) return false;
    }
  }
  vis[node] = 2;
  return true;
}

void topoSort(int node, vi& vis2, vvi& adj) {
  if (vis2[node] == 1) return; 
  for (int child: adj[node]) { 
    if (vis2[node] == 1) continue;
    topoSort(child, vis2, adj);
  }

  vis2[node] = 1;
  cout << node << " ";
}

void solve() {
  int n, k; cin >> n >> k;
  vvi adj(n + 1);
  vi vis(n + 1, 0); // 0: unvisited, 1: visiting, 2: visited
  vi vis2(n + 1, 0); // 0: unvisited, 1: visiting, 2: visited

  int a, b;
  repx(i, 1, k + 1) {
    cin >> a >> b;
    adj[b].pb(a);
  }

  bool cycle = false;
  repx(i, 1, n + 1) cycle |= (!cycleCheck(i, vis, adj));
  if (cycle) { cout << "IMPOSSIBLE"; return; }
  repx(i, 1, n+1) topoSort(i, vis2, adj);
}

int main() {
  flash;
  solve();
  return 0;
}