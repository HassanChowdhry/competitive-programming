#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T; 
    if (!(cin >> T)) return 0;
    while (T--) {
        int n; cin >> n;
        vector<vector<int>> a(n);
        int L = 0;
        for (int i = 0; i < n; ++i) {
            int k; cin >> k;
            a[i].resize(k);
            for (int j = 0; j < k; ++j) cin >> a[i][j];
            L = max(L, k);
        }

        // Sort with "+inf padding": longer row comes first when prefix equal
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        auto cmp = [&](int x, int y) {
            const auto &A = a[x], &B = a[y];
            int m = min(A.size(), B.size());
            for (int i = 0; i < m; ++i) {
                if (A[i] != B[i]) return A[i] < B[i];
            }
            if (A.size() != B.size()) return A.size() > B.size(); // longer first
            return false; // equal
        };
        sort(idx.begin(), idx.end(), cmp);

        vector<int> ans(L, -1);
        for (int id : idx) {
            const auto &row = a[id];
            for (int j = 0; j < (int)row.size(); ++j) {
                if (ans[j] == -1) ans[j] = row[j];
            }
        }

        for (int j = 0; j < L; ++j) {
            if (j) cout << ' ';
            cout << ans[j];
        }
        cout << "\n";
    }
    return 0;
}
