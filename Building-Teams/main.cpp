#include <bits/stdc++.h>
# define ll long long
# define pb push_back
# define all(a) a.begin(),a.end()
# define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
# define test int t;cin>>t;while(t--)
# define loop(n) for(int i=0;i<n;++i)
# define loopx(x, n) for(int i=x;i<n;++i)
# define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i];
# define nline "\n"
using namespace std;
int MOD=1000000007;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

bool cycleCheck(int node, int parent, vector<int>& visit, vector<int>& team, unordered_map<int, vector<int>>& adj) {
  visit[node] = true;
  bool found = false;
  
  for (int f : adj[node]) {
    if (f != parent) {
      if (!visit[f]) {
        team[f] = !team[node];
        found = cycleCheck(f, node, visit, team, adj);
      } else if (team[f] == team[node]) { 
          return true; 
      }
    }
  }
  
  return found;
} 

void solve() {
  int n, m; cin >> n >> m;
  vector<int> visit(n+1, false), team(n+1, 1);
  unordered_map<int, vector<int>> adj; loopx(1, n+1) { adj[i] = vector<int>(); }
  int e1, e2;

  loop(m) {
    cin >> e1 >> e2;
    adj[e1].pb(e2);
    adj[e2].pb(e1);
  }

  bool hasCycle = false;

  loopx(1, n+1) {
    if (!visit[i] && cycleCheck(i, -1, visit, team, adj))
      { hasCycle = true; break; }
  }
  
  if (hasCycle) { cout << "IMPOSSIBLE"; return; }
  loopx(1, n+1) 
    { cout << (team[i] ? team[i] : 2) << " "; } 
}

int main() {
  flash
  solve();
  return 0;
}