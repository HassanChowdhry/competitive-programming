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
int MOD=1000000007;

class SegmentTree {
  private:
    vector<ll> tree, lazy;
    int n;
    void apply_lazy(int node, int start, int end) {
      if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) 
          { lazy[node * 2 + 1] += lazy[node]; lazy[node * 2 + 2] += lazy[node]; }
        lazy[node] = 0;
      }
    }
    void update_range(int node, int start, int end, int l, int r, ll value) {
      apply_lazy(node, start, end);
      if (start > end || start > r || end < l) return;
      
      if (start >= l && end <= r) {
        tree[node] += (end - start + 1) * value;
        if (start != end) 
          { lazy[node * 2 + 1] += value; lazy[node * 2 + 2] += value; }
        return;
      }
      int mid = (start + end) / 2;
      update_range(node * 2 + 1, start, mid, l, r, value);
      update_range(node * 2 + 2, mid + 1, end, l, r, value);
      tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }
    ll query(int node, int start, int end, int idx) {
      apply_lazy(node, start, end);
      if (start > end || idx < start || idx > end) return 0;
      if (start == end) return tree[node];
      int mid = (start + end) / 2;
      if (idx <= mid) return query(node * 2 + 1, start, mid, idx);
      return query(node * 2 + 2, mid + 1, end, idx);
    }
  public:
    SegmentTree(int size) {
      n = size; tree.resize(4 * n, 0); lazy.resize(4 * n, 0);
    }
    void update_range(int l, int r, ll value) {
      update_range(0, 0, n - 1, l, r, value);
    }
    ll query(int idx) {
      return query(0, 0, n - 1, idx);
    }
};

void solve() {
  int n, k, num; cin >> n >> k;
  SegmentTree st = SegmentTree(n);
  rep(i, n) {
    cin >> num; st.update_range(i, i, num);
  }

  int t, a, b, x;
  rep(_, k) {
    cin >> t;

    if (t == 1) {
      cin >> a >> b >> x;
      st.update_range(a-1, b-1, x);
    } else {
      cin >> a;
      cout << st.query(a-1) << ln; 
    }
  }
}

int main() {
  flash;
  solve();
  return 0;
}