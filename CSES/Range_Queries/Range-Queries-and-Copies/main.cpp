
#include <bits/stdc++.h>
using namespace std;

struct Node {
  Node *l, *r;
  long long s;

  Node(long long val) : l(nullptr), r(nullptr), s(val) {}
  Node(Node *l, Node *r): l(l), r(r), s(0) {
    if (l) s += l->s;
    if (r) s += r->s;
  }
};

int n, q; 
const int maxN = 2e5 + 1;
int a[maxN];

Node* build(int l, int r) {
	if (l == r) {
		return new Node(a[l]);
	}

	int m = (l + r) / 2;
	return new Node(
		build(l, m),
		build(m + 1, r)
	);
}

Node* update(Node *node, int l, int r, int pos,  int val) {
	if (l == r) { return new Node(val); }

	int m = (l + r) / 2;
	if (pos <= m) 
		return new Node(update(node->l, l, m, pos, val), node->r);
	else if (pos > m) 
		return new Node(node->l, update(node->r, m+1, r, pos, val));

	return new Node(0);
}

long long query(Node *node, int l, int r, int ql, int qr) {
	if (qr < l || ql > r) return 0LL;
	if (ql<=l && qr>=r) return node->s;
	
	int m = (l + r) / 2;
	long long res = query(node->l, l, m, ql, qr) + query(node->r, m+1, r, ql, qr);

	return res;
}

void solve() {
    cin >> n >> q;

	for (int i = 1; i <= n; ++i) cin >> a[i];
	
	int cnt = 1;
    vector<Node*> trees = { new Node(0), build(1, n) };

	int f, k, a, b, x;
	while (q--) {
		cin >> f;

		if (f == 1) {
			cin >> k >> a >> x;
			trees[k] = update(trees[k], 1, n, a, x);
		} else if (f == 2) {
			cin >> k >> a >> b;
			long long res = query(trees[k], 1, n, a, b);
			cout << res << "\n";
		} else if (f == 3) {
			cin >> k;	
			Node* u = trees[k];
			trees.push_back(
				new Node(u->l, u->r)
			);
			++cnt;
		}
	}
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}

// 3 4 3 2 1