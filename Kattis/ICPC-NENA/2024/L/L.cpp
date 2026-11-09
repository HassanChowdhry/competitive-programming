#include <bits/stdc++.h>
using namespace std;

int n, m, c, l;
int prv[500005], occur[500005]; 
long long tree[2000005];
long long res;

void update(int node, int l, int r, int pos,  int val) {
    if (l == r) { tree[node] = val; return; }

    int m = (l + r) / 2;
    if (pos <= m) update(2*node, l, m, pos, val);
    else if (pos > m) update(2*node+1, m+1, r, pos, val);

    tree[node] = tree[2*node] + tree[2*node+1];
}

long long query(int node, int l, int r, int ql, int qr) {
    if (qr < l || ql > r) return 0LL;
    if (ql<=l && qr>=r) return tree[node];
    int m = (l + r) / 2;

    long long res = query(2*node, l, m, ql, qr) + query(2*node+1, m+1, r, ql, qr);

    return res;
}

void solve() {
    cin >> n;
    m = n + n;
    res = 0;

    for (int i = 1; i <= m; ++i) {
        cin >> c >> l;

        if (prv[l]) {
            res += query(1, 1, m, 1, prv[l]);
        }

        prv[l] = i;

        if (!occur[c]) {
            update(1, 1, m, i, 1LL);
            occur[c] = i;
        } else {
            update(1, 1, m, occur[c], 0LL);
            occur[c] = 0;
        }
    }

    cout << res << "\n"; 
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}