#include <bits/stdc++.h>
#define ll long long
using namespace std;

int MOD=1000000007;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

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

    // sum
    // tree[node] = tree[2*node] + tree[2*node+1];
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

    // sum
    //ll res = query(2*node, l, m, ql, qr) + query(2*node+1, m+1, r, ql, qr);

    return res;
  }
};