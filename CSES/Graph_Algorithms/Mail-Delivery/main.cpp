#include <bits/stdc++.h>
using namespace std;

vector<vector<pair<int, int>>> adj;
vector<int> seen;
vector<int> res;

void dfs(int u) {
    while (!adj[u].empty()) {
        pair<int, int> x = adj[u].back();
        int v = x.first, i = x.second;
        adj[u].pop_back();

        if (seen[i]) continue;
        seen[i] = 1;

        dfs(v);
    }

    res.push_back(u);
}

void solve() {
    int n, m; cin >> n >> m;

    vector<int> deg(n + 1);
	adj.resize(n + 1);
	seen.resize(m + 1);

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        adj[u].push_back({v, i});
        adj[v].push_back({u, i});
        ++deg[u];
        ++deg[v];
    }

    for (int i = 1; i <= n; ++i) {
        if (deg[i] % 2) {
            cout << "IMPOSSIBLE";
            return;
        }
    } 
    
    dfs(1);

    if (res.size() != m + 1) {
        cout << "IMPOSSIBLE"; 
        return;
    }

    for (int i: res) {
        cout << i << " ";
    }
}


int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}