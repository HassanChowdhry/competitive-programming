#include <bits/stdc++.h>
using namespace std;

#define ll long long

class SegmentTree {
  private:
  vector<ll> tree;
  ll n;

  public:
  SegmentTree(ll m) {
    n = m; tree.resize(4 * m);
  }

  void update(ll node, ll pos, ll l, ll r, ll val) {
    if (l == r) { tree[node] = val; return; }

    ll m = (l + r) / 2;
    if (pos <= m) update(2*node, pos, l, m, val);
    else if (pos > m) update(2*node+1, pos, m+1, r, val);
    
    // min, max
    // tree[node] = max(tree[2 * node], tree[2 * node + 1]); 

    // sum
    tree[node] = tree[2*node] + tree[2*node+1];
  }

  ll query(ll node, ll l, ll r, ll ql, ll qr) {
    if (qr < l || ql > r) return 0;
    if (ql<=l && qr>=r) return tree[node];
    ll m = (l + r) / 2;

    // min, max
    // ll res = max(
    //   query(2*node, l, m, ql, qr),
    //   query(2*node+1, m+1, r, ql, qr)
    // );

    // sum
    ll res = query(2*node, l, m, ql, qr) + query(2*node+1, m+1, r, ql, qr);

    return res;
  }
};

void solve() {
  int n, q; cin >> n >> q;

  vector<int> a(n + 1), s(n + 1), e(n + 1);
  vector<vector<int>> adj(n + 1); 
  for (int i = 1; i <= n; ++i) cin >> a[i];

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  auto dfs = [&](int u, int p, int id, auto&& dfs) -> int {
    int end_id = id;
    s[u] = id;
    for (int v: adj[u]) {
      if (v == p) continue;
      int next = dfs(v, u, end_id + 1, dfs);
      end_id = max(end_id, next);
    }
    return e[u] = end_id;
  };

  dfs(1, 0, 1, dfs);
  vector<int> v(n + 1);
  SegmentTree st(n + 1);
  for (int i = 1; i <= n; ++i) {
    v[s[i]] = a[i];
    st.update(1, s[i], 1, n, a[i]);
    // cout << "for " << i << ", s : " << s[i] << " end: " << e[i] << "\n";
    // cout << " val " << st.query(1, 1, n, s[i], s[i]) << "\n";
  }

  // cout << " 1 to 5" << " " << st.query(1, 1, n, 1, 6) << " \n ";

  while (q--) {
    int m; cin >> m;
    if (m == 1) {
      int y, x; cin >> y >> x;
      st.update(1, s[y], 1, n, x);
    } else {
      int x; cin >> x;
      long long res = st.query(1, 1, n, s[x], e[x]);
      cout << res << "\n";
    }
  }
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0); cout.tie(0);
  solve();
  return 0;
}