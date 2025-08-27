#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define all(a) a.begin(),a.end()
#define mod(num, n) (num % n + n) % n
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test int t;cin>>t;while(t--)
#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,x,n) for(int i=x;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define rem(mp, el) if(mp[el]==0)mp.erase(el)
#define ln "\n"
#define vi vector<int>
#define vl vector<ll>
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
    if (l == r) { tree[node] = max(tree[node], val); return; }

    ll m = (l + r) / 2;
    if (pos <= m) update(2*node, pos, l, m, val);
    else if (pos > m) update(2*node+1, pos, m+1, r, val);
    
    tree[node] = max(tree[2 * node], tree[2 * node + 1]); 
  }

  // target is the current height
  ll query(ll node, ll l, ll r, ll ql, ll qr) {
    if (qr < l || ql > r) return 0;
    if (ql<=l && qr>=r) return tree[node];
    ll m = (l + r) / 2;

    ll res = max(
      query(2*node, l, m, ql, qr),
      query(2*node+1, m+1, r, ql, qr)
    );
    
    //ll res = 
    //query(2*node, l, m, ql, qr)
    //query(2*node+1, m+1, r, ql, qr);
    
    return res;
  }
};

// I am querying the max beauty at a valid segment, how do I get this valid segment? any segment less is valid.
// at tree[node] = max at this ?

void solve() {
  ll n; cin >> n;
  vector<ll> h(n+1), a(n+1);
  for (int i=1; i <= n; ++i) cin >> h[i]; for (int i=1; i <= n; ++i) cin >> a[i];

  // st
  SegmentTree st(n+1);
  ll res = LLONG_MIN;
  for(int i = 1; i <= n; ++i) {
    // cout << h[i] << " " << a[i] << " ";
    ll val = st.query(1, 1, n, 1, h[i]-1) + a[i];
    res = max(val, res);
    st.update(1, h[i], 1, n, val);
  }

  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}