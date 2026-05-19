#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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
    tree[node] = max(tree[2 * node], tree[2 * node + 1]); 
  }

  ll query(ll node, ll l, ll r, ll ql, ll qr) {
    if (qr < l || ql > r) return 0;
    if (ql<=l && qr>=r) return tree[node];
    ll m = (l + r) / 2;

    // min, max
    ll res = max(
      query(2*node, l, m, ql, qr),
      query(2*node+1, m+1, r, ql, qr)
    );

    return res;
  }

  // ll getLeft(ll node, ll l, ll r, ll val) {
  //   if (tree[node] < val) return 0;
  //   if (l == r) return l;

  //   ll m = (l + r) / 2;
  //   ll ml = query(2*node, l, m, l, m);
  //   ll mr = query(2*node+1, m + 1, r, m + 1, r);

  //   if (ml >= val) {
  //     return getLeft(2 * node, l, m, val);
  //   } 
    
  //   if (mr >= val) {
  //     return getLeft(2 * node + 1, m + 1, r, val);
  //   }
    
  //   return 0;
  // }
  ll getLeft(ll node, ll l, ll r, ll val) {
    if (tree[node] < val) return 0;
    if (l == r) return l;

    ll m = (l + r) / 2;
    ll ml = tree[node * 2];
    ll mr = tree[node * 2 + 1];

    if (ml >= val) {
      return getLeft(2 * node, l, m, val);
    } 
    
    if (mr >= val) {
      return getLeft(2 * node + 1, m + 1, r, val);
    }
    
    return 0;
  }
};

void solve() {
  int n, m; cin >> n >> m;
  vector<int> hotels(n + 1);
  SegmentTree st(n + 1);
  for (int i = 1; i <= n; ++i) {
    cin >> hotels[i];
    st.update(1, i, 1, n, hotels[i]);
  }

  for (int i = 0; i < m; ++i) {
    int x; cin >> x;
    // cout << x << "\n";
    int idx = st.getLeft(1, 1, n, x);
    cout << idx << " ";
    if (idx > 0) {
      hotels[idx] -= x;
      st.update(1, idx, 1, n, hotels[idx]);
    }
  }


  // cout << st.query(1, 1, n, 1, 1);
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}