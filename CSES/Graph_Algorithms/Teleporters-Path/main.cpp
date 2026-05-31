#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> res;

void dfs(int u) {
    while (!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();
        dfs(v);
    }

    res.push_back(u);
}

void solve() {
    int n, m; cin >> n >> m;
    adj.resize(n + 1);
    vector<int> deg(n + 1);

    for (int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;

        adj[u].push_back(v);
        ++deg[u];
        --deg[v];
    }

    
    if (deg[1] != 1 || deg[n] != -1) {
        cout << "IMPOSSIBLE";
        return;
    }

    for (int i = 2; i < n; ++i) {
        if (deg[i] != 0) {
            cout << "IMPOSSIBLE";
            return; 
        }
    }

    adj[n].push_back(1);

    dfs(1);

    if (res.size() != m + 2) {
        cout << "IMPOSSIBLE";
        return;
    }

    // for (int i : res) {
    //     cout << i << " ";
    // } cout << "\n";

    vector<int> res2;
    for (int i = 0; i <= m; ++i) {
        if (res[i] == 1 && res[i + 1] == n) {
            for (int j = i + 1; j <= m+1; ++j) {
                res2.push_back(res[j]);
            }
            for (int j = 1; j <= i; ++j) {
                res2.push_back(res[j]);
            }
            break;
        }
    }

    reverse(res2.begin(), res2.end());
    for (int i: res2) {
        cout << i << " ";
    }
}

int main() {
    solve();
    return 0;
}