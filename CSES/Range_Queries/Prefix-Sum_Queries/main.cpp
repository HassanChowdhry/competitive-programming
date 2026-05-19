#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct node {
  ll sum, pre, suf, ans;
};

node mg(node l, node r) {
  node res;

  res.sum = l.sum + r.sum;
  res.pre = max(l.pre, l.sum + r.pre);
  res.suf = max(r.suf, r.sum + l.suf);
  res.ans = max(max(l.ans, r.ans), l.suf + r.pre);

  return res;
}

class SegmentTree {
  private:

  vector<node> tree;
  int n;

  public:
  SegmentTree(int m) {
    n = m; tree.resize(4 * m);
  }

  void build(vector<ll>& a, int curr, int l, int r) {
    if (l == r) {
      node res; 
      ll val = a[l];
      res.sum = val;
      res.pre = res.suf = res.ans = max(0LL, val);
      tree[curr] = res;
    } else {
      int m = (l + r) / 2;
      build(a, curr * 2, l, m); 
      build(a, curr * 2 + 1, m + 1, r);
      tree[curr] = mg(tree[curr * 2], tree[curr * 2 + 1]);
    }
  }

  void update(int curr, int pos, int l, int r, ll val) {
    if (l == r) {
      node res;
      res.sum = val;
      res.pre = res.suf = res.ans = max(0LL, val);
      tree[curr] = res;
      return;
    }

    int m = (l + r) / 2;
    if (pos <= m) update(2*curr, pos, l, m, val);
    else if (pos > m) update(2*curr+1, pos, m+1, r, val);
    
    // min, max
    tree[curr] = mg(tree[2 * curr], tree[2 * curr + 1]); 
  }

  node query(int curr, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) {
      node res;
      res.ans = res.sum = res.pre = res.suf = 0LL;
      return res;
    }
    if (ql<=l && qr>=r) return tree[curr];
    int m = (l + r) / 2;

    // min, max
    node res = mg(
      query(2*curr, l, m, ql, qr),
      query(2*curr+1, m+1, r, ql, qr)
    );

    return res;
  }
};

void solve() {
  int n, q; cin >> n >> q;
  vector<long long> a(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  SegmentTree st(n + 1);
  st.build(a, 1, 1, n);

  for (int i = 0; i < q; ++i) {
    int f, l, r; cin >> f >> l >> r;

    if (f == 1) {
      st.update(1, l, 1, n, r);
    } else {
      node res = st.query(1, 1, n, l, r);
      cout << res.ans << "\n";
    }
  }

  // cout << st.query(1, 1, n, 1, 1);
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}