#include <bits/stdc++.h>
using namespace std;

long long V[100005];
int P[100005];
map<int, long long> frq;
map<int, map<int, long long>> same_frq;
vector<int> adj[100005];
int nei[100005];
int mark[100005];
int vis[100005];
int cycle[100005];

void dfs(int u, int p, int pp) {
  if (vis[u]) return;
  vis[u] = 1;
  P[u] = pp;
  for (int v: adj[u]) {
    if (v != p && !vis[v] && !cycle[v]) dfs(v, u, pp);
  }
}
// int 
void solve() {
  int n, k; cin >> n >> k;

  for (int i = 1; i <= n; ++i) cin >> V[i];

  int u, v;
  for (int i = 1; i <= n; ++i) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    ++nei[u]; ++nei[v];
  }

  queue<int> q;

  for (int i = 1; i <= n; ++i) {
    if (nei[i] == 1) {
      q.push(i);
      mark[i] = 1;
    }
  }

  while (!q.empty()) {
    u = q.front(); q.pop();
    for (int v: adj[u]) {
      if (mark[v]) continue;
      --nei[v];
      if (nei[v] == 1) {
        mark[v] = 1;
        q.push(v);
      }
    }
  }

  for (int i = 1; i <= n; ++i) {
    // cout << mark[i] << " ";
    if (!mark[i]) cycle[i] = 1;
  }

  for (int i = 1; i <= n; ++i) {
    if (cycle[i]) {
      P[i] = i; dfs(i, -1, i);
      // cout << i << " ";
    }
  }
  
  // cout << "\n";
  // for (int i = 1; i <= n; ++i) {
  //   cout << " i : " << i << "  Parent " << P[i] << " \n";
  // }

  // V[i] +- k ? how many ? 
  // ++ how do I know different groups?
  long long total = 0, same_total = 0;
  for (int i = 1; i <= n; ++i) {
    // sure this will give me the pairs for vd ? 
    // however I also want the tree of where each is
    // they can be in any one of the node

    // V[i] - k
    // V[i] + k
    total += frq[V[i]-k];
    total += frq[V[i]+k];
    ++frq[V[i]];
    

    same_total += same_frq[P[i]][V[i]-k];
    same_total += same_frq[P[i]][V[i]+k];
    ++same_frq[P[i]][V[i]];
  }

  // cout << total << " " << same_total;
  long long diff = total - same_total;

  // diff * 2 + same_total

  long long ans = diff * 2 + same_total;

  if (k > 0) {
    cout << ans;
  } else {
    // cout << ans;
    cout << ans + n;
  }
}

int main() {
  solve();
}