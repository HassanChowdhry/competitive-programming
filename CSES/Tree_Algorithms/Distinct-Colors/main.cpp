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
  int n; cin >> n;

  vector<int> a(n + 1), s(n + 1), e(n + 1);
  map<int, int> mp; vector<int> occ(n + 1);
  set<int> seen;
  vector<vector<int>> adj(n + 1); 
  for (int i = 1; i <= n; ++i) cin >> a[i];

  for (int i = 1; i < n; ++i) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  int id = 0;
  auto dfs = [&](int u, int p, auto&& dfs) -> void {
    s[u] = ++id;
    for (int v: adj[u]) {
      if (v == p) continue;
      dfs(v, u, dfs);
    }
    e[u] = id;
  };

  dfs(1, 0, dfs);
  SegmentTree st(n + 1);
  vector<int> c(n+1); // mapping from node_id to old node val
  vector<int> v(n+1);
  for (int i = 1; i <= n; ++i) {
    c[s[i]] = i;
  }
  
  for (int i = 1; i <= n; ++i) {
    v[i] = a[c[i]];
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << "i : " << i << " c[i]: " << c[i] << " v[i]: " << v[i] << "\n";
  // }

  for (int i = n; i >= 1; --i) {
    if (mp[v[i]]) {
      occ[i] = mp[v[i]];
    }
    mp[v[i]] = i;
  }
  
  for (int i = 1; i <= n; ++i) {
    int f = 1;
    if (seen.count(v[i])) {
      f = 0;
    } else {
      seen.insert(v[i]);
    }
    // cout << s[i] << " " << f << "\n";
    st.update(1, 1, n, i, f);
    // cout << x << "\n";
  }

  // for (int i = 1; i <= n; ++i) {
  //   int v = st.query(1, 1, n, s[i], s[i]);
  //   // cout << v << " ";
  // }
  vector<int> res(n + 1);
  for (int i = 1; i <= n; ++i) {
    ll ans = st.query(1, 1, n, s[c[i]], e[c[i]]);
    res[c[i]] = ans;

    if (occ[i]) {
      st.update(1, 1, n, occ[i], 1);
    }
  }

  for (int i = 1; i <= n; ++i) {
    cout << res[i] << " ";
  }
}

int main() {
  cin.tie(0); ios_base::sync_with_stdio(0); cout.tie(0);
  solve();
  return 0;
}