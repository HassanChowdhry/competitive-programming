
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct tn {
	ll ans;
	vector<ll> h;
};

const ll maxN = 1e5 + 1;
ll h[maxN];
tn tree[4 * maxN];

class SegmentTree {
    private:
    int n;

    public:
    SegmentTree(ll a[], int n) {
        this->n = n; 
		build(a, 1, 1, n);
    }

	void build(ll a[], int node, int l, int r) {
		if (l == r) {
			tn curr{1LL, {a[l]}};
			tree[node] = curr;
			return;
		}

		int m = (l + r) / 2;
		build(a, node * 2, l, m);
		build(a, node * 2 + 1, m + 1, r);
		
		// merge
		
		ll lmax = tree[node * 2].h.back();
		auto it = upper_bound(tree[node * 2 + 1].h.begin(), tree[node * 2 + 1].h.end(), lmax);
		
		// cout << "START NODE " << l << " TO " << r << "\n";
		// for (int u: tree[node * 2].h) cout << u << " ";
		// cout << "\n";
		// for (int u: tree[node * 2 + 1].h) cout << u << " ";
		// cout << "\n";
		// cout << "ANS: " << tree[node].ans << "\n";
		// cout << "END NODE " << l << " TO " << r << "\n\n";
		
		
		tree[node].h = tree[node * 2].h;
		tree[node].h.insert(
			tree[node].h.end(), 
			it, 
			tree[node * 2 + 1].h.end()
		);

		tree[node].ans = tree[node].h.size();
	}

	// ans, largest
    pair<ll, ll> query(int node, int l, int r, int ql, int qr, ll x) {
        if (qr < l || ql > r) {
			return {0LL, x};
		}

        if (ql<=l && qr>=r) {
			if (x == -1) return { tree[node].ans, tree[node].h.back() };
			
			auto it = upper_bound(tree[node].h.begin(), tree[node].h.end(), x);
			ll ans = tree[node].h.end() - it;
    		return { ans, ans > 0 ? tree[node].h.back() : x };
		}

        int m = (l + r) / 2;

        pair<ll, ll> left = query(2*node, l, m, ql, qr, x);
		pair<ll, ll> right = query(2*node + 1, m + 1, r, ql, qr, max(x, left.second));

		return {
			left.first + right.first,
			max(x, max(left.second, right.second))
		};
    }
};

void solve() {
    int n, q; cin >> n >> q;

	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
	}

    SegmentTree st(h, n);
	int l, r;
	for (int i = 1; i <= q; ++i) {
		cin >> l >> r;

		pair<int, int> ans = st.query(1, 1, n, l, r, -1LL);
		cout << ans.first << "\n";
		// cout << "ANS: " << ans.first << " LRG: " << ans.second << "\n";
	}
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}

// 3 4 3 2 1