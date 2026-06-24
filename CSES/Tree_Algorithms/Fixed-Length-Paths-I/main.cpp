#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxN = 2e5 + 1;
int n, k, deepest;
ll ans = 0;

int sz[maxN], cnt[maxN], vis[maxN];
vector<int> tree[maxN];

int dfs_size(int u, int p) {
  sz[u] = 1;
  for (int v: tree[u]) {
    if (v == p || vis[v]) continue;
    sz[u] += dfs_size(v, u);
  }
  return sz[u];
};

int find_centroid(int u, int p, int len) {
  for (int v: tree[u]) {
    if (v != p && !vis[v] && sz[v] > len / 2) 
      return find_centroid(v, u, len);
  }

  return u;
};

void dfs_cnt(int u, int p, int t, int d = 1) {
  if (d > k) return;

  deepest = max(deepest, d);
  if (t) {
    ++cnt[d];
  } else {
    ans += cnt[k - d];
  }

  for (int v: tree[u]) {
    if (v != p && !vis[v]) dfs_cnt(v, u, t, d + 1);
  }
}

void dfs(int u) {
  int subtree_size = dfs_size(u, 0);
  int centroid = find_centroid(u, 0, subtree_size);
  vis[centroid] = 1;
  deepest = 0;

  for (int v: tree[centroid]) {
    if (!vis[v]) {
      dfs_cnt(v, centroid, 0);
      dfs_cnt(v, centroid, 1);
    }
  }

  for (int i = 1; i <= deepest; ++i) {
    cnt[i] = 0;
  }

  for (int v: tree[centroid]) {
    if (!vis[v]) dfs(v);
  }
}

void solve() {
  cin >> n >> k;

  int u, v;
  for (int i = 1; i < n; ++i) {
    cin >> u >> v;
    tree[u].push_back(v);
    tree[v].push_back(u);
  }

  cnt[0] = 1;
  dfs(1);

  cout << ans;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}