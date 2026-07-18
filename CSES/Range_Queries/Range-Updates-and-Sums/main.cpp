
#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree {
    private:
    vector<ll> tree, mark, lazy;
	
	void push(int node, int l, int r, int m) {
		if (mark[node]) {
			tree[node * 2] = mark[node] * (m - l + 1);
			tree[node * 2 + 1] = mark[node] * (r - m);

			mark[node * 2] = mark[node * 2 + 1] = mark[node];
			lazy[node * 2] = lazy[node * 2 + 1] = 0;
			mark[node] = 0;
		}

		if (lazy[node]) {
			tree[node * 2] += lazy[node] * (m - l + 1);
			lazy[node * 2] += lazy[node];
		
			tree[node * 2 + 1] += lazy[node] * (r - m);
			lazy[node * 2 + 1] += lazy[node];
			
			lazy[node] = 0;
		}

    }

	public:
	SegmentTree(int m) {
        tree.resize(4 * m, 1LL); mark.resize(4 * m, 0LL), lazy.resize(4 * m, 0LL);
    }

	void set_range(int node, int l, int r, int ql, int qr, ll v) {
		if (l > r || l > qr || r < ql) return;

		if (l >= ql && r <= qr) {
			tree[node] = v * (r - l + 1);
			mark[node] = v;
			lazy[node] = 0;
			return;
		} 

		
		int m = (l + r) / 2;
		push(node, l, r, m);
		set_range(node * 2, l, m, ql, qr, v);
		set_range(node * 2 + 1, m + 1, r, ql, qr, v);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

	void update_range(int node, int l, int r, int ql, int qr, ll v) {
		if (l > r || l > qr || r < ql) return;

		if (l >= ql && r <= qr) {
			tree[node] += v * (r - l + 1);
			lazy[node] += v;
			return;
		} 

		int m = (l + r) / 2;
		push(node, l, r, m);
		update_range(node * 2, l, m, ql, qr, v);
		update_range(node * 2 + 1, m + 1, r, ql, qr, v);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];

    }

	void update_point(int node, int l, int r, int p, ll v) {
		if (l > r) {
			return ;
		}
		
		if (l == r) {
			tree[node] = v; return;
		}

		int m = (l + r) / 2;
		if (p <= m) update_point(node * 2, l, m, p, v);
		else update_point(node * 2 + 1, m + 1, r, p, v);

		tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }

	ll query(int node, int l, int r, int ql, int qr) {
		if (qr < l || ql > r) {
			return 0LL;
		}
		
		
		if (ql <= l && r <= qr) {
			return tree[node];
		}
		
		int m = (l + r) / 2;
		push(node, l, r, m);
		ll res = query(node * 2, l, m, ql, qr) + query(node * 2 + 1, m + 1, r, ql, qr);
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
		return res;
    }
};

const int maxN = 2e5 + 1;
int n, q;
ll t[maxN];

void solve() {
	cin >> n >> q;
	SegmentTree st(n + 1);

	for (int i = 1; i <= n; ++i) {
		cin >> t[i];
		st.update_point(1, 1, n, i, t[i]);
	}

	int f, a, b, x;
	for (int i = 1; i <= q; ++i) {
		cin >> f;

		if (f == 1) {
			cin >> a >> b >> x;
			st.update_range(1, 1, n, a, b, x);
		} else if (f == 2) {
			cin >> a >> b >> x;
			st.set_range(1, 1, n, a, b, x);
		} else if (f == 3) {
			cin >> a >> b;
			ll res = st.query(1, 1, n, a, b);
			cout << res << "\n";
		}
	}
	
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
