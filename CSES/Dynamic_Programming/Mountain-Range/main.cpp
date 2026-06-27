
#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree {
    private:
    vector<ll> tree, mark;
    int n;

	void apply_lazy(int node) {
		if (mark[node]) {
			tree[node * 2] = tree[node * 2 + 1] = tree[node];
			mark[node * 2] = mark[node * 2 + 1] = 1;
			mark[node] = 0;
		}
    }

	void update_range(int node, int l, int r, int ql, int qr, ll val) {
		if (l > r || l > qr || r < ql) return;

		if (l >= ql && r <= qr) {
			tree[node] = val;
			mark[node] = 1;
			return;
		} 

		apply_lazy(node);

		int mid = (l + r) / 2;
		update_range(node * 2, l, mid, ql, qr, val);
		update_range(node * 2 + 1, mid + 1, r, ql, qr, val);
    }

	ll query(int node, int l, int r, int i) {
		
		if (l > r || i < l || i > r) {
			return 0LL;
		}
		
		if (l == r) {
			return tree[node];
		}
		
		apply_lazy(node);
		int mid = (l + r) / 2;
		if (i <= mid) return query(node * 2, l, mid, i);
		return query(node * 2 + 1, mid + 1, r, i);
    }

    public:
    SegmentTree(int m) {
        n = m; tree.resize(4 * m, 1LL); mark.resize(4 * m, 0LL);
    }

	void update_range(int l, int r, ll val) {
    	update_range(1, 1, n, l, r, val);
    }

    ll query(int i) {
    	return query(1, 1, n, i);
    }
};

const int maxN = 2e5 + 1;
int n;
ll h[maxN], R[maxN], L[maxN];
vector<pair<ll, int>> hs;
ll ans;

void solve() {
	cin >> n;
	SegmentTree st(n + 1);
	for (int i = 1; i <= n; ++i) {
		cin >> h[i];
		hs.push_back({ h[i], i });
	}
	
	sort(hs.rbegin(), hs.rend());
	fill(R+1, R+n+1, n);
	fill(L+1, L+n+1, 1);

	stack<int> s;
	for (int i = 1; i <= n; ++i) {
		while (!s.empty() && h[s.top()] <= h[i]) {
			int j = s.top(); R[j] = i - 1;
			s.pop();
		}
		
		s.push(i);
	}

	s = {};
	for (int i = n; i >= 1; --i) {
		while (!s.empty() && h[s.top()] <= h[i]) {
			int j = s.top(); L[j] = i + 1;
			s.pop();
		}

		s.push(i);
	}

	for (auto [v, i] : hs) {
		int l = L[i], r = R[i];
		ll curr = st.query(i);
		if (l <= i - 1) {
			st.update_range(l, i - 1, curr + 1LL);
		}
		if (r >= i + 1) {
			st.update_range(i + 1, r, curr + 1LL);
		}
		// cout << h[L[i]] << " " << h[i] << " " << h[R[i]] << "\n";
	}

	
	ans = 1LL;
	for (int i = 1; i <= n; ++i) {
		ll curr = st.query(i);
		ans = max(ans, curr);
	}

	cout << ans;
    
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
