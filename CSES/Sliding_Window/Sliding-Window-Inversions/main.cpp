#include <bits/stdc++.h>
# define ll long long
using namespace std;

class SegmentTree {
    private:
    vector<ll> tree;
    ll n;

    public:
    SegmentTree(ll n) {
        this->n = n; tree.resize(4 * n);
    }

    void update(ll node, ll l, ll r, ll pos,  ll val) {
        if (l == r) { tree[node] = val; return; }

        ll m = (l + r) >> 1;
        if (pos <= m) update(node << 1, l, m, pos, val);
        else if (pos > m) update(node << 1 | 1, m+1, r, pos, val);

        tree[node] = tree[node << 1] + tree[node << 1 | 1];
    }

    ll query(ll node, ll l, ll r, ll ql, ll qr) {
        if (qr < l || ql > r) return 0;
        if (ql<=l && qr>=r) return tree[node];
        ll m = (l + r) >> 1;
		
		return query(node << 1, l, m, ql, qr) + query(node << 1 | 1, m+1, r, ql, qr);
    }
};

void solve() {
	int n, k; cin >> n >> k;
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
    const int maxN = b.back();
    int r = 1, l = 1;
    for (r = 1; r < k; ++r) {        
        ans += st.query(1, 1, n, a[r] + 1, maxN);
        st.update(
            1, 1, n, a[r], st.query(1, 1, n, a[r], a[r]) + 1
        );
    }

    for (; r <= n;) {
        ans += st.query(1, 1, n, a[r] + 1, maxN);
        st.update(
            1, 1, n, a[r], st.query(1, 1, n, a[r], a[r]) + 1
        );
        ++r;

        cout << ans << " ";

        ans -= st.query(1, 1, n, 1, a[l] - 1);
        st.update(
            1, 1, n, a[l], st.query(1, 1, n, a[l], a[l]) - 1
        );
        ++l;
    }  
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  	solve();
	return 0;
}