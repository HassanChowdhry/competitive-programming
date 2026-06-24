#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 1;
int n, m, k;
int vis[maxN], vis_1[maxN], vis_2[maxN], shop[maxN], res1[maxN], res2[maxN];
vector<int> adj[maxN];
queue<pair<pair<int, int>, int>> q; // curr_node, step, source

void solve() {
  cin >> n >> m >> k;
  int c, a, b;
  for (int i = 1; i <= k; ++i) {
    cin >> c; 
    q.push({ {c, 1}, c });
    shop[c] = 1;
    vis[c] = 1;
    res1[c] = -1;
  }   

  for (int i = 1; i <= m; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }

  // I need to find the min dist from x to an anime shop
  // this is an easy BFS, from each anime shop we can go to whatever the next is
  // the problem is that x cannot be the answer for x
  // so it has to come from y. fortunately the we still just need 2 possible answers.
  // what information do I need? -> curr_node, step, source

  while (!q.empty()) {
    auto top = q.front(); q.pop();
    int u = top.first.first, s = top.first.second, o = top.second;

    for (int v: adj[u]) {
      if (vis[v] == 2 || vis_1[v] == o) continue;
      
      if (v == o) continue;
      
      if (vis[v] == 1) {
        vis_2[v] = o;
        res2[v] = s;
      } else if (vis[v] == 0) {
        vis_1[v] = o;
        res1[v] = s;
      }
      
      ++vis[v];
      q.push({ {v, s + 1} , o });
    }
  }


  for (int i = 1; i <= n; ++i) {
    if (shop[i]) {
      if (res2[i]) cout << res2[i] << " ";
      else cout << -1 << " ";
      continue;
    }
     
    if (res1[i]) cout << res1[i] << " ";
    else cout << -1 << " ";
  }
  
}


int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}