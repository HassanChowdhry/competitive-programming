#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
int n, m, k, mask;

void euler(int u) {
    while (!adj[u].empty()) {
        int v = adj[u].back();
        adj[u].pop_back();

        cout << (v & 1);
        euler(v);
    }

} 

void solve() {
    cin >> n; m = n - 1, k = 1 << (n - 1);

    if (n == 1) {
        cout << "01";
        return;
    }

    adj.resize(k);

    for (int u = 0; u < k; ++u) {
        int v = (u << 1) % k;
        adj[u].push_back(v);
        adj[u].push_back(v | 1);

        // cout << " u: " << u << " v0: " << v << " v1: " << (v|1) << "\n";
    }

    for (int i = 1; i < n; ++i) cout << "0";
    euler(0);

}


int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}