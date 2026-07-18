
#include <bits/stdc++.h>
using namespace std;

#define ll long long

struct Node {
	ll a;
	ll d;
};

// one keeps the first value of lazy and the second value is the sum
class SegmentTree {
    private:
    vector<ll> tree;
	vector<Node> lazy;

	ll gauss(int node, ll n) {
		return (n) * (2LL * lazy[node].a + (n - 1LL) * lazy[node].d) / 2LL;
	}
	
	void push(int node, int l, int r, int m) {
		if (lazy[node].d) {
			tree[node] += gauss(node, r - l + 1LL);
		   if (l != r) {
			   lazy[node * 2].a += lazy[node].a;
			   lazy[node * 2 + 1].a += lazy[node].a + (m - l + 1) * 1LL * lazy[node].d;
   
			   lazy[node * 2].d += lazy[node].d;
			   lazy[node * 2 + 1].d += lazy[node].d;
		   }
   
		   lazy[node] = {0, 0};
		}
    }

	void pull(int node) {
		tree[node] = tree[node * 2] + tree[node * 2 + 1];
	}

	public:
	SegmentTree(int m) {
        tree.resize(4 * m);
		lazy.resize(4 * m);
    }

	void update_range(int node, int l, int r, int ql, int qr) {
		int m = (l + r) / 2;
		push(node, l, r, m);
		
		if (l > r || l > qr || r < ql) return;
		
		
		if (l >= ql && r <= qr) {
			lazy[node].a += l - ql + 1;
			++lazy[node].d;
			push(node, l, r, m);
			return;
		} 
		


		update_range(node * 2, l, m, ql, qr);
		update_range(node * 2 + 1, m + 1, r, ql, qr);

		pull(node);
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

		pull(node);
    }

	ll query(int node, int l, int r, int ql, int qr) {
		int m = (l + r) / 2;
		push(node, l, r, m);
		
		if (qr < l || ql > r) {
			return 0LL;
		}

		
		if (ql <= l && r <= qr) {
			return tree[node];
		}		
		

		
		ll lsum = query(node * 2, l, m, ql, qr);
		ll rsum = query(node * 2 + 1, m + 1, r, ql, qr);
		
		return lsum + rsum;
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

	int f, a, b;
	for (int i = 1; i <= q; ++i) {
		cin >> f;

		if (f == 1) {
			cin >> a >> b;
			st.update_range(1, 1, n, a, b);
		} else if (f == 2) {
			cin >> a >> b ;
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
