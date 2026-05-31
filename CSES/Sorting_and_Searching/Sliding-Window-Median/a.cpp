#include <bits/stdc++.h>
using namespace std;

#define ln "\n";

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

    int get_median(int node, int l, int r, int h) {
        if (l >= r || h == 0) return l;
        
        int m = (l + r) / 2;
        int ml = tree[node * 2];
        int mr = tree[node * 2 + 1];

        if (h <= ml) {
            return get_median(node * 2, l, m, h);
        }

        return get_median(node * 2 + 1, m + 1, r, h - ml);
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<int> nums(n + 1), sort_nums(n + 1), a(n + 1);
    map<int, int> mp, r_mp;
    SegmentTree st(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> nums[i];
        sort_nums[i] = nums[i];
    }

    sort(sort_nums.begin(), sort_nums.end());

    for (int i = 1, j = 1; i <= n; ++i) {
        if (!mp[sort_nums[i]]) {
            mp[sort_nums[i]] = j;
            r_mp[j] = sort_nums[i];
            ++j;
        }
    }

    for (int i = 1; i <= n; ++i) {
        a[i] = mp[nums[i]];
    }
    // int p = st.query(1, 1, n, a[i], a[i]);
    // st.update(1, 1, n, a[i], p + 1);
    
    // int p = st.query(1, 1, n, a[i], a[i]);
    // st.update(1, 1, n, a[i], p - 1);
    int r = 1, l = 1;
    for (r = 1; r < k; ++r) {        
        int p = st.query(1, 1, n, a[r], a[r]);
        st.update(1, 1, n, a[r], p + 1);
    }
    
    int h = (k + 1) / 2;
    int p;
    for (; r <= n;) {
        p = st.query(1, 1, n, a[r], a[r]);
        st.update(1, 1, n, a[r], p + 1);
        ++r;

        int res = st.get_median(1, 1, n, h);
        int ans = r_mp[res];
        cout << ans << " ";

        p = st.query(1, 1, n, a[l], a[l]);
        st.update(1, 1, n, a[l], p - 1);
        ++l;
    }   
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}

// 3 4 3 2 1