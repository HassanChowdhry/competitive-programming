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
    
    // sum
    tree[node] = tree[2*node] | tree[2*node+1];
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
    ll res = query(2*node, l, m, ql, qr) | query(2*node+1, m+1, r, ql, qr);

    return res;
  }
};

void generator(ll x, ll a, ll b, ll c, ll n, vector<ll>& nums) {
  nums[1] = x;
  for (int i = 2; i <= n; ++i) nums[i] = (a * nums[i-1] + b) % c;
}

void solve() {
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    
    vector<ll> v(n + 1); generator(x, a, b, c, n, v);
    SegmentTree st(n + 1);

    for (int i = 1; i <= n; ++i) {
        st.update(1, i, 1, n, v[i]);
    }

    ll ans = 0;

    for (int i = k; i <= n; ++i) {
        ll res = st.query(1, 1, n, i - k + 1, i);
        ans ^= res;
    }

    cout << ans;
}


int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}