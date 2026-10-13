#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int tree[4 * (N+1)];

void update(int node_id, int left, int right, int idx, int val) {
	// if ( idx < left || right < idx ) return ;
	if (left == right) {
		tree[node_id] = val;
		return;
	}

	int mid = (left + right) / 2;
	// cout << mid << "\n";
	if (mid < idx) update(2*node_id+1, mid+1, right, idx, val);
	else update(2*node_id, left, mid, idx, val);

	tree[node_id] = tree[2*node_id+1] + tree[2*node_id];
}

int query(int node_id, int left, int right, int ql, int qr) {
	if (ql > right || qr < left) return 0;
	if (ql <= left && right <= qr) return tree[node_id];
	int mid = (left + right) / 2;
	int l = query(2*node_id, left, mid, ql, qr);
	int r = query(2*node_id+1, mid+1, right, ql, qr);
	return l + r;
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  // int t; cin >> t;
  // while(t--)

	int n, q;
	cin >> n >> q;

	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		update(1, 1, n, i, x);
		// for (int j=1; j<=n; j++) {
		// 	cout << query(1, 1, n, j, j) << " ";
		// }
		// cout << "\n";
	}

	
	
	for (int i=0; i<q; i++) {
		int type;
		cin >> type;
		if (type == 1) {
			int k, u;
			cin >> k >> u;
			update(1, 1, n, k, u);
		} else if (type == 2) {
			int a, b;
			cin >> a >> b;
			cout << query(1, 1, n, a, b) << endl;
		}
	}

  return 0;
}