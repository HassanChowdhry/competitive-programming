#include <bits/stdc++.h>
using namespace std;

#define ii pair<int, int>
int n;
char opp;
const int maxN = 1e6;
int F[maxN], T[maxN], leaf[maxN];
vector<int> adj[maxN];

// op = 0 — AND, op = 1 — OR
// state = 0 — T-F, 1 - F-T

int dfs1(int u, int op) {
  if (leaf[u]) {
    if (F[u]) return 0;
    return 1;
  }

  int ans = 1-op;

  for (int v: adj[u]) {
    if (op == 0) {
      ans &= dfs1(v, 1-op);
    } else {
      ans |= dfs1(v, 1-op);
    }
  }

  return ans;
}

int dfs(int u, int op, int state) {
  // cout << u << "\n";
  if (leaf[u]) {
    if (state == 0) return T[u];
    return F[u];
  }
  int ans;
  if (op == state) {
    ans = maxN;
  } else {
    ans = 0;
  }

  for (int v: adj[u]) {
    if (op == state) {
      ans = min(ans, dfs(v, 1 - op, state));
    } else {
      ans += dfs(v, 1 - op, state);
    }
  }

  return ans;
}


void solve() {
  // find the current state
  // if T to F
  //  AND: min(child)
  //  OR: SUM(child)
  // if F to T
  //  AND: SUM(child)
  //  OR:  MIN(child)

  cin >> n >> opp;
  int u = 1;
  int curr = 1;
  string v; cin >> v;

  queue<ii> q; q.push({u, stoi(v)});
  ++u;
  for (int i = 1; i <= n; ++i) {
    int len = q.size();
    for (int j = 1; j <= len; ++j) {
      auto pi = q.front(); q.pop();
      int p = pi.first;
      int p_cnt = pi.second;
      // cout << "\n" <<  p_cnt << " : \n";
      // cout << p_cnt << "\n";
      int z = 1;
      while (z <= p_cnt && cin >> v) {
        // if 
        // cout << v << " ";
        if (v == "F" || v == "T") {
          if (v == "F") ++F[u];
          if (v == "T") ++T[u];
          leaf[u] = 1;
        } else {
          q.push({u, stoi(v)});
        }

        // cout << p << " " << u << "\n";
        adj[p].push_back(u);
        ++u; ++z;
      }
      // cout << "\n";
    }
    // cout << "\n";
  }


  int state = dfs1(1, opp!='A');
  // cout << state << " ";
  int res = dfs(1, opp!='A', 1-state);
  cout << res;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}
