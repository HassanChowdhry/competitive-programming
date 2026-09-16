#include <bits/stdc++.h>
using namespace std;
int n, q, a, b;

const int maxN = 2e5;
typedef long long ll;
struct tn {
	ll ans;
  ll max;
	vector<ll> x;
  vector<ll> pre;
};
tn tree[4 * maxN];
ll x[maxN+5];

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
			tn curr{0, a[l], {a[l]}, {a[l]}};
			tree[node] = curr;
			return;
		}

		int m = (l + r) / 2;
		build(a, node * 2, l, m);
		build(a, node * 2 + 1, m + 1, r);
	
    ll cost = 0;
    ll max_ = 0;
    ll p = 0;
		for (ll num : tree[node * 2].x) {
      max_ = max(num, max_);
      cost += max(0LL, max_ - num);
      p += max_;
      tree[node].x.push_back(max_);
      tree[node].pre.push_back(p);
    }

		for (ll num : tree[node * 2 + 1].x) {
      max_ = max(num, max_);
      cost += max(0LL, max_ - num);
      p += max_;
      tree[node].x.push_back(max_);
      tree[node].pre.push_back(p);
    }

    tree[node].ans = cost + tree[node*2].ans + tree[node*2+1].ans;
    tree[node].max = max_;
	}

	// ans, largest
  pair<ll, ll> query(int node, int l, int r, int ql, int qr, ll max_) {
    if (qr < l || ql > r) {
      return {0, 0};
    }

    if (l >= ql && r <= qr) {
      // in query
      int j = upper_bound(tree[node].x.begin(), tree[node].x.end(), max_) - tree[node].x.begin();

      // I have the relative position in l.. l + j
      // 
      ll ans = 0LL;

      // M = 5
      // 0 4 4 6 6
      // l = 1, j = 1
      if (j > 0)
        ans = (max_ * j) - (tree[node].pre[j-1]);

      return {
        tree[node].ans + ans,
        max(max_, tree[node].max)
      };
    }

    int m = (l + r) / 2;

    pair<ll, ll> left = query(2*node, l, m, ql, qr, max_);
    max_ = max(left.second, max_);
    pair<ll, ll> right = query(2*node + 1, m + 1, r, ql, qr, max_);
    max_ = max(right.second, max_);

    return {left.first + right.first, max_};
  }
};

void solve() {
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i];
  }

  SegmentTree st(x, n);
  for (int i = 1; i <= q; ++i) {
    cin >> a >> b;

    pair<ll, ll> res = st.query(1, 1, n, a, b, 0LL);
    cout << res.first << "\n";
    // cout << res.second << "\n\n";
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  // int t; cin >> t;
  // while(t--)
  solve();
  return 0;
}