#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 1;
int h[maxN];
vector<int> tree[4 * maxN];
vector<int> L_ptr[4 * maxN]; // fractional cascading
vector<int> R_ptr[4 * maxN]; // fractional cascading

class SegmentTree {
    private:
    int n;
	
    public:
    SegmentTree(int n) {
        this->n = n; 
		build(1, 1, n);
    }

	void build(int node, int l, int r) {
		if (l == r) {
			tree[node].push_back(h[l]);
			return;
		}

		int m = (l + r) / 2;
		build(node * 2, l, m);
		build(node * 2 + 1, m + 1, r);
		
		int sz1 = tree[node * 2].size();
        int sz2 = tree[node * 2 + 1].size();
        
        tree[node].resize(sz1 + sz2);
        L_ptr[node].resize(sz1 + sz2 + 1);
        R_ptr[node].resize(sz1 + sz2 + 1);
		
        int i = 0, j = 0, k = 0;
        while (i < sz1 && j < sz2) {
            L_ptr[node][k] = i;
            R_ptr[node][k] = j;
            if (tree[node * 2][i] <= tree[node * 2 + 1][j]) {
                tree[node][k++] = tree[node * 2][i++];
            } else {
                tree[node][k++] = tree[node * 2 + 1][j++];
            }
        }
        while (i < sz1) {
            L_ptr[node][k] = i;
            R_ptr[node][k] = j;
            tree[node][k++] = tree[node * 2][i++];
        }
        while (j < sz2) {
            L_ptr[node][k] = i;
            R_ptr[node][k] = j;
            tree[node][k++] = tree[node * 2 + 1][j++];
        }
        
        L_ptr[node][sz1 + sz2] = sz1;
        R_ptr[node][sz1 + sz2] = sz2;
	}

	// ans, largest
    int query(int node, int l, int r, int ql, int qr, int a, int b) {
        if (qr < l || ql > r || a==b) {
			return 0;
		}

        if (ql<=l && qr>=r) {
			return b - a;
		}

        int m = (l + r) / 2;
		int res = 0;

		if (ql <= m) {
			res += query(2 * node, l, m, ql, qr, L_ptr[node][a], L_ptr[node][b]);
		}

		if (qr > m) {
			res += query(2 * node + 1, m + 1, r, ql, qr, R_ptr[node][a], R_ptr[node][b]);
		}

		return res;
    }
};

void solve() {
	int n, q; cin >> n >> q;

	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}

	SegmentTree st(n);
	int l, r, a, b;
	for (int i = 1; i <= q; ++i) {
		cin >> l >> r >> a >> b;
		
		int aa = lower_bound(tree[1].begin(), tree[1].end(), a) - tree[1].begin();
        int bb = upper_bound(tree[1].begin(), tree[1].end(), b) - tree[1].begin();
		int ans = st.query(1, 1, n, l, r, aa, bb);
		cout << ans << "\n";
	}
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}

// 3 4 3 2 1