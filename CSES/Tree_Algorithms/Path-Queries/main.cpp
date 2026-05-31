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

  void update(ll node, ll l, ll r, ll pos, ll val) {
    if (l == r) { tree[node] = val; return; }

    ll m = (l + r) / 2;
    if (pos <= m) update(2*node, l, m, pos, val);
    else if (pos > m) update(2*node+1, m+1, r, pos, val);
    
    // min, max
    // tree[node] = max(tree[2 * node], tree[2 * node + 1]); 

    // sum
    tree[node] = tree[2*node] + tree[2*node+1];
  }

  ll query(ll node, ll l, ll r, ll ql, ll qr) {
    if (qr < l || ql > r) return 0LL;
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
  vector<vector<int>> adj(n + 1);
  vector<ll> a(n+1), s(n + 1), e(n + 1);

  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < n - 1; ++i) {
    int a, b; cin >> a >> b;
    adj[a].push_back(b);
    adj[b].push_back(a);
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
  SegmentTree st(n + 2);

  for (int i = 1; i <= n; ++i) {
    ll p1 = st.query(1, 1, n + 1, s[i], s[i]);
    ll p2 = st.query(1, 1, n + 1, e[i] + 1, e[i] + 1);

    st.update(1, 1, n + 1, s[i],  p1 + a[i]);
    st.update(1, 1, n + 1, e[i] + 1, p2 - a[i]);
  }

  for (int i = 0; i < q; ++i) {
    int f; cin >> f;

    if (f == 1) {
      ll p, v; cin >> p >> v;
      ll p1 = st.query(1, 1, n + 1, s[p], s[p]);
      ll p2 = st.query(1, 1, n + 1, e[p] + 1, e[p] + 1);

      st.update(1, 1, n + 1, s[p], p1 - a[p] +  v);
      st.update(1, 1, n + 1, e[p] + 1,  p2 - v + a[p]);

      a[p] = v;
    } else {
      int x; cin >> x;
      ll res = st.query(1, 1, n + 1, s[1], s[x]);
      cout << res << "\n";
    }
  }

}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0); cout.tie(0);
  solve();
  return 0;
}