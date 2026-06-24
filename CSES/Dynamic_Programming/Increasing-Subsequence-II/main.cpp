#include <bits/stdc++.h>
# define ll long long
using namespace std;

const int oo = 1e9 + 7;

class SegmentTree {
    private:
    vector<ll> tree;
    ll n;

    public:
    SegmentTree(ll m) {
        n = m; tree.resize(4 * m);
    }

    void update(ll node, ll l, ll r, ll pos,  ll val) {
        if (l == r) { tree[node] = (val % oo); return; }

        ll m = (l + r) / 2;
        if (pos <= m) update(2*node, l, m, pos, val);
        else if (pos > m) update(2*node+1, m+1, r, pos, val);

        tree[node] = ((tree[2*node] % oo) + (tree[2*node+1] % oo) % oo);
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        if (qr < l || ql > r) return 0;
        if (ql<=l && qr>=r) return tree[node];
        ll m = (l + r) / 2;
		
		ll al = query(2*node, l, m, ql, qr) % oo;
		ll ar = query(2*node+1, m+1, r, ql, qr) % oo;
        ll res = (al + ar) % oo;

		// ll res = query(2*node, l, m, ql, qr) + query(2*node+1, m+1, r, ql, qr);

        return res;
    }
};

void solve() {
	int n; cin >> n;
	SegmentTree st(n + 1);
  
	vector<ll> a(n + 1), b(n + 1);
	unordered_map<ll, ll> mp;

	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		b[i] = a[i];
	}

	sort(b.begin(), b.end());

	for (int i = 1, j = 1; i <= n; ++i) {
        if (!mp[b[i]]) {
            mp[b[i]] = j;
            ++j;
        }
    }

	for (int i = 1; i <= n; ++i) {
		a[i] = mp[a[i]];
	}

	long long ans = 0;

	for (int i = 1; i <= n; ++i) {

		long long curr = st.query(1, 1, n, 1, a[i] - 1);
		ans = (ans + curr + 1LL) % oo;

		long long ai = st.query(1, 1, n, a[i], a[i]);
		ai = (ai + curr + 1) % oo; 
		st.update(1, 1, n, a[i], ai);
	}

	cout << ans;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  	solve();
	return 0;
}