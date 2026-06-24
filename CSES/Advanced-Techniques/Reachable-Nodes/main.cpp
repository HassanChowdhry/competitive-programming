#include <bits/stdc++.h>
using namespace std;

const int maxN = 5e4 + 1;
int n, m, a, b;
int dp[maxN];
vector<int> adj[maxN];

int dfs(int u) {
  dp[u] = 1;

  for (int v: adj[u]) {
    dp[u] += dfs(v);
  }

  return dp[u];
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> a >> b;
    adj[a].push_back(b);
  }

  for (int i = 1; i <= n; ++i) {
    if (dp[i]) continue;
    dfs(i);
  }

  for (int i = 1; i <= n; ++i) {
    cout << dp[i] << " ";
  }
}


int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}