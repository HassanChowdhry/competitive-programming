#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define ln "\n"
void LSH() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int LOG = 32;

void getdepth(int node, ll d, vector<ll>& depth, vector<vector<ll>>& adj) {
  depth[node] = d;
  for (int child: adj[node]) getdepth(child, d + 1LL, depth, adj);
}

void dfs(int node, int p, vector<ll>& parent, vector<vector<ll>>& ad) {
    parent[node] = p;
    for (int c: ad[node]) {
        if (c != p) dfs(c, node, parent, ad);
    }
}
void solve() {
    int n, q; cin >> n >> q;
    vector<ll> parent(n + 1, 0);
    vector<vector<ll>> ad(n + 1);
    for (int i = 0; i <= n; ++i) parent[i]=i;
    for (int i = 0; i < n-1; ++i) { 
        int p, c; cin >> p >> c;
        ad[p].pb(c);
        ad[c].pb(p);
    }

    dfs(1, 1, parent, ad);

    int root = 0;
    for (int i = 0; i <= n; ++i) if (parent[i] == i) root = i;

    // cout << "root: " << root << ln;
    vector<vector<ll>> dp(n + 1, vector<ll>(LOG));
    vector<ll> depth(n + 1);
    vector<vector<ll>> adj(n + 1);

    for (int i = 1; i <= n; ++i) {
        if (parent[i] == i) continue;
        adj[parent[i]].pb(i);
    }

    getdepth(root, 0, depth, adj);

    for (int i = 1; i <= n; ++i) dp[i][0] = parent[i];
    for (int p = 1; p < LOG; ++p) {
        for (int i = 1; i <= n; ++i) dp[i][p] = dp[ dp[i][p-1] ][p-1];
    }
    
    for (int i=1; i <= q; ++i) {
        int a, b; cin >> a >> b;
        ll da = depth[a], db = depth[b];
        if (depth[a] > depth[b]) swap(a, b);
        ll k = depth[b] - depth[a];

        for (int i = 0; i < LOG; ++i) {
            if (k & ( 1 << i )) b = dp[b][i];
        }
        
        //LCA
        if (a == b) { 
            // cout << "LCA: " << a << ln; 
            // cout << "a: " << da << " b: " << db << " LCA: " << depth[a] << ln;
            ll res = abs(da - depth[a]) + abs(db - depth[a]);
            cout << res << ln;
            continue; 
        }

        for (int log = 31; log >= 0; --log) {
        if (log >= depth[a]) continue;
        if (dp[a][log] != dp[b][log])
            { a = dp[a][log]; b = dp[b][log]; }
        }
        // LCA
        // cout << "LCA: " << dp[a][0] << ln;
        ll lca = dp[a][0];
        ll res = abs(da - depth[lca]) + abs(db - depth[lca]);
        // cout << "a: " << da << " b: " << db << " LCA: " << depth[dp[a][0]] << ln;
        cout << res << ln;
        // if (res > 3) yes = 0;
    }
    // cout << yes << ln;
}

int main() {
    LSH();
    // int t; cin >> t;
    // for(int i = 0; i < t; ++i)
    solve();
}