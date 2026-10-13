#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+2;
int n, d, p;
int dist[maxN];
int ans[maxN];
vector<int> tree[maxN];
vector<pair<int, int>> c[maxN];

// 3 cases
// case 1: 2 complex trees with dist d1, d2. if its a complex tree then 2d1 >= d
// so this case will never d1 + d2 < d
// case 2: 1 complex and 1 unique dist tree, d1, d2. in this case if (d1 + d2 < d) 
// then d2 < d1 guarantee due to the property of complex tree, take most marked with tie breaker as furthest marked
// case 1: 2 unique dist tree, if (d1 + d2 >= d) then take both, else take most marked and the dist + 1.
// if we want to take u then we have to drop any < d
void dfs(int u) {
  if (tree[u].empty()) {
    ans[u] = 1; dist[u] = 0;
    return;
  }

  for (int v : tree[u]) {
    dfs(v);
    c[u].push_back({dist[v]+1, ans[v]});
  }
  // cout << "\n";

  sort(c[u].begin(), c[u].end());
  int a1=0, a2=1;

  // if (i, i + 1) >= d
  for (auto [dv, da] : c[u]) {
    if (dv >= d) a2 += da;
  }

  int m = c[u].size();
  for (int i = 0; i < m; ++i) {
    if (i == m - 1) {
      dist[u] = min(dist[u], c[u][i].first);
      a1 += c[u][i].second;
      continue;
    }

    if (c[u][i].first + c[u][i+1].first >= d) {
      dist[u] = min(dist[u], c[u][i].first);
      a1 += c[u][i].second;
    }
    
    if (c[u][i].first + c[u][i+1].first < d) {
      if (c[u][i].second - 1 != 0) {
        dist[u] = min(dist[u], d);
        a1 += c[u][i].second - 1;
      }
    }
  }

  // cout << u << " : \n";
  // for (auto[dv, da] : c[u]) {
  //   cout << " dist:  " << dv << " marked: " << da << " \n";
  // }
  // cout << "\n\n\n";
  
  if (a2 > a1) {
    dist[u] = 0;
    ans[u] = a2;
  } else {
    ans[u] = a1;
  }
}


void solve() {
  cin >> n >> d;
  fill(dist, dist+maxN, maxN);
  for (int i = 2; i <= n; ++i) {
    cin >> p;
    tree[++p].push_back(i);
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << i << " : ";
  //   for (int v: tree[i]) {
  //     cout << v << " ";
  //   }
  //   cout << "\n";
  // }

  dfs(1);

  cout << ans[1];
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}