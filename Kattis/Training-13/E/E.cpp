#include <bits/stdc++.h>
using namespace std;

const int maxN = 3e5+5;
vector<int> adj[maxN];
int color[maxN];
int s[maxN], e[maxN];
int timer=0, n, q, k, x;

bitset<101> tree[maxN*4];

void euler(int u, int p) {
  s[u] = ++timer;

  for (int v: adj[u]) {
    if (v != p) euler(v, u);
  }

  e[u] = timer;
}

class SegmentTree {
  public:
  void update(int node, int l, int r, int pos, bitset<101> val) {
    if (l == r) {
      tree[node] = val; return; 
    }

    int m = (l + r) / 2;
    if (pos <= m) update(2*node, l, m, pos, val);
    else if (pos > m) update(2*node+1, m+1, r, pos, val);

    tree[node] = tree[node*2] ^ tree[node*2+1];
  }

  bitset<101> query(int node, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) return bitset<101>(0);
    if (ql<=l && qr>=r) return tree[node];
    
    int m = (l + r) / 2;
    // tn left = query(2*node, l, m, ql, qr);
    // tn right = query(2*node+1, m+1, r, ql, qr);

    bitset<101> res = query(2*node, l, m, ql, qr) ^ query(2*node+1, m+1, r, ql, qr);

    return res;
  }
};

void solve() {
  int n, q; cin >> n >> q;
  
  SegmentTree st;
  for (int i = 1; i <= n; ++i) {
    cin >> color[i];
  }

  for (int i = 2; i <= n; ++i) {
    int p; cin >> p;
    adj[p].push_back(i);
  }

  // for (int i = 1; i <= n; ++i) {
  //   cout << i << " : ";
  //   for (int v: adj[i]) cout << v << " ";
  //   cout << "\n";
  // }
  // timer=0;
  euler(1, 0);
  for (int i = 1; i <= n; ++i) {
    bitset<101> c(0); c.flip(color[i]);
    // cout << color[i] << "\n";
    st.update(1, 1, n, s[i], c);
    // cout << s[i] << " " << e[i] << "\n";
  }

  for (int i = 1; i <= q; ++i) {
    cin >> k >> x;
    if (k == 0) {
      bitset<101> cnt = st.query(1, 1, n, s[x], e[x]);
      int res = cnt.count();
      cout << res << "\n";
    } else {
      bitset<101> kc(0); kc.flip(k);
      st.update(1, 1, n, s[x], kc);
      color[x] = k;
    }
  }
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}