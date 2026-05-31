#include <bits/stdc++.h>
using namespace std;
const int oo = 1e9 + 7;

void solve() {
    int n, m; cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 1; i <= m; ++i) {
        int u,v; cin >> u >> v;
        adj[u-1].push_back(v-1);
    }

    vector<vector<long long>> dp(n, vector<long long>(1 << 20));

    queue<pair<int, int>> q; q.push({0, 1}); // node, mask
    vector<vector<int>> vis(n, vector<int>(1 << 20));
    dp[0][1] = 1;
    vis[0][1] = 1;
    while (!q.empty()) {
        int u = q.front().first;
        int mask = q.front().second;
        q.pop();

        if (u == n-1) continue;

        for (int v: adj[u]) {
            int next_mask = mask | (1 << v);
            
            if (mask & (1 << v)) continue;
            dp[v][next_mask] = ((dp[v][next_mask] % oo) + (dp[u][mask] % oo)) % oo;
            
            if (vis[v][next_mask]) continue;
            q.push({v, next_mask});
            vis[v][next_mask] = 1;
        }
    }

    // cout << (1 << n) << "\n";
    cout << dp[n-1][(1<<n)-1] % oo;
} 

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    
    solve();
    return 0;
}