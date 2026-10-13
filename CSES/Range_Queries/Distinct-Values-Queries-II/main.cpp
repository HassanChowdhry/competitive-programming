#include <bits/stdc++.h>
using namespace std;
int n, q, f, a, b;

const int maxN = 2e5;
typedef long long ll;
struct tn {
	ll L;
  ll R;
};

tn tree[4 * maxN];
ll X[maxN+5], PO[maxN+5], NO[maxN+5];

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
			tn curr{PO[l], NO[l]};
			tree[node] = curr;
			return;
		}

		int m = (l + r) / 2;
		build(a, node * 2, l, m);
		build(a, node * 2 + 1, m + 1, r);

    // merge
	}

  void update(int node, int l, int r, int i, ll PO_v, ll NO_v, ll v) {
    if (l == r) {
      tn curr{{PO_v}, {NO_v}};
      tree[node] = curr;
			return;
		}

    int m = (l + r) / 2;
    if (i <= m) update(a, node * 2, l, m, i, PO_v, NO_v, v);
		else update(a, node * 2 + 1, m + 1, r, i, PO_v, NO_v, v);

    // remove from L and R

  }

	// ans, largest
  int query(int node, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) {
      return 1;
    }

    if (l >= ql && r <= qr) {
      // if the edge of either L or R is inside the ql, qr then return 0 otherwise 1
      int cl = tree[node].L
      int cr = tree[node].R

      return cl < ql && cr > qr;
    }

    int m = (l + r) / 2;

    int left = query(2*node, l, m, ql, qr);
    int right = query(2*node + 1, m + 1, r, ql, qr);

    return left && right;
  }
};

void solve() {
  cin >> n >> q;

  for (int i = 1; i <= n; ++i) cin >> X[i];
  SegmentTree st(X, n);

  // compute PO/NO
  // occurrence table

  for (int i = 1; i <= q; ++i) {
    cin >> f >> a >> b;

    if (f == 1) {
      // update PO/NO/tree
    } else if (f == 2) {
      int ok = st.query(1, 1, n, a, b);
      if (ok) cout << "YES";
      else cout << "NO";
    }
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  // int t; cin >> t;
  // while(t--)
  solve();
  return 0;
}