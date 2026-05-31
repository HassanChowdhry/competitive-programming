
#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
    private:
    vector<int> tree;
    int n;

    public:
    SegmentTree(int m) {
        n = m; tree.resize(4 * m);
    }

    void update(int node, int l, int r, int pos,  int val) {
        if (l == r) { tree[node] = val; return; }

        int m = (l + r) / 2;
        if (pos <= m) update(2*node, l, m, pos, val);
        else if (pos > m) update(2*node+1, m+1, r, pos, val);

        tree[node] = tree[2*node] + tree[2*node+1];
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) return 0;
        if (ql<=l && qr>=r) return tree[node];
        int m = (l + r) / 2;

        int res = query(2*node, l, m, ql, qr) + query(2*node+1, m+1, r, ql, qr);

        return res;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vector<int> a(n + 1), s_a(n + 1);
    vector<pair<pair<int, int>, int>> qry(q + 1);
    vector<int> vis(n + 5);
    map<int, int> mp1;
    vector<int> mp(n + 5); 
    vector<int> occ(n + 1);
    SegmentTree st(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        s_a[i] = a[i];
    }

    sort(s_a.begin(), s_a.end());

    for (int i = 1, j = 1; i <= n; ++i) {
        if (!mp1[s_a[i]]) {
            mp1[s_a[i]] = j;
            ++j;
        }
    }

    for (int i = 1; i <= n; ++i) {
        a[i] = mp1[a[i]];

        // cout << a[i] << " ";
        if (vis[a[i]]) continue;

        st.update(1, 1, n, i, 1);
        vis[a[i]] = 1;
    }

    for (int i = 1; i <= q; ++i) {
        int l, r; cin >> l >> r;
        qry[i] = {{l, r}, i};
    }
    
    for (int i = n; i >= 1; --i) {
        if (mp[a[i]]) {
            occ[i] = mp[a[i]];
        }
        mp[a[i]] = i;
    }

    sort(qry.begin(), qry.end());
    vector<int> ans(q + 1);
    int z = 1;
    for (int i = 1; i <= q; ++i) {
        int l = qry[i].first.first;
        int r = qry[i].first.second;
        int j = qry[i].second; 

        while (z < l) {
            if (occ[z]) {
                st.update(1, 1, n, occ[z], 1);
            }
            ++z;
        }
        
        int res = st.query(1, 1, n, l, r);
        ans[j] = res;
    }


    for (int i = 1; i <= q; ++i) {
        cout << ans[i] << "\n";
    }


}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}

// 3 4 3 2 1