#include <bits/stdc++.h>
# define ll long long
# define pb push_back
# define all(a) a.begin(),a.end()
# define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
# define test int t;cin>>t;while(t--)
# define loop(n) for(int i=0;i<n;++i)
# define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i];
# define nline "\n"
using namespace std;
int MOD=1000000007;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

void bfs(int start, int end, unordered_map<int, vector<int>>& adj, vector<int>& parent) {
  queue<int> q; q.push(start);
  unordered_set<int> visit;
  int node;
  while (!q.empty()) {
    node = q.front(); q.pop();

    // if (visit.count(node)) { continue; }
    if (node == end) { return; }
    // cout << node << nline;

    visit.insert(node);

    for (int children : adj[node]) {
      if (visit.count(children)) { continue; }
      visit.insert(children);
      q.push(children);
      parent[children] = node;
    }
  }
}

void solve() {
  int n, m; cin >> n >> m;
  unordered_map<int, vector<int>> adj; 
  vector<int> parent(n+1); loop(n+1) { parent[i] = i; adj[i] = vector<int>(); }
  int e1, e2;
  loop(m) { cin >> e1 >> e2; adj[e1].pb(e2); adj[e2].pb(e1); }
  bfs(1, n, adj, parent);
  
  // loop(n+1) { cout << i << " "; } cout << nline;
  // loop(n+1) { cout << parent[i] << " "; }

  int size = 0, curr = n; string output = "";
  while (curr != parent[curr]) {
    ++size;
    output = to_string(curr) + " " + output;
    curr = parent[curr];
  }
  ++size;
  output = to_string(curr) + " " + output;
  
  if (curr == 1) 
    { cout << size << nline << output; } 
  else 
    { cout << "IMPOSSIBLE"; }
}

int main() {
  flash
  solve();
  return 0;
}