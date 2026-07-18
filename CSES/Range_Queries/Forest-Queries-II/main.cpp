
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1001;
int M[maxN][maxN];

class SegmentTree {
    private:
    vector<vector<int>> tree;
	int n, m;
    public:
    SegmentTree(int n, int m) {
		this->n=n, this->m=m;
		tree.resize(4 * n, vector<int>(4 * m));
    }

	void build_y(int node_x, int lx, int rx, int node_y, int ly, int ry) {
		if (ly == ry) {
			if (lx == rx) tree[node_x][node_y] = M[lx][ly];
			else tree[node_x][node_y] = tree[2*node_x][node_y] + tree[2*node_x+1][node_y];
			return;
		}

		int my = (ly + ry) / 2;
		build_y(node_x, lx, rx, 2*node_y, ly, my);
		build_y(node_x, lx, rx, 2*node_y+1, my+1, ry);

		tree[node_x][node_y] = tree[node_x][2*node_y] + tree[node_x][2*node_y+1];
	}

	void build_x(int node_x, int lx, int rx) {
		if (lx != rx) {
			int mx = (lx + rx) / 2;
			build_x(2*node_x, lx, mx);
			build_x(2*node_x+1, mx+1, rx);
		}

		build_y(node_x, lx, rx, 1, 1, this->m);
	}

	void update_y(int node_x, int lx, int rx, int node_y, int ly, int ry, int px, int py, int val) {
		if (ly == ry) {
			if (lx == rx) tree[node_x][node_y] = val;
			else tree[node_x][node_y] = tree[2*node_x][node_y] + tree[2*node_x+1][node_y];
			return;
		}

		int my = (ly + ry) / 2;
		if (py <= my) update_y(node_x, lx, rx, 2*node_y, ly, my, px, py, val);
		else update_y(node_x, lx, rx, 2*node_y+1, my+1, ry, px, py, val);

		tree[node_x][node_y] = tree[node_x][2*node_y] + tree[node_x][2*node_y+1];
	}

    void update_x(int node_x, int lx, int rx, int px, int py, int val) {
		if (lx != rx) {
			int mx = (lx + rx) / 2;
			if (px <= mx) update_x(2*node_x, lx, mx, px, py, val);
			else update_x(2*node_x+1, mx + 1, rx, px, py, val);        
		}
		
		update_y(node_x, lx, rx, 1, 1, this->m, px, py, val);
	}

	int query_y(int node_x, int node_y, int ly, int ry, int qly, int qry) {
		if (qry < ly || qly > ry) return 0;
		if (qly<=ly && qry>=ry) {
			return tree[node_x][node_y];
		}

		int my = (ly + ry) / 2;
		int res = query_y(node_x, 2*node_y, ly, my, qly, qry) + query_y(node_x, 2*node_y+1, my+1, ry, qly, qry);
		return res;
	}

    int query_x(int node_x, int lx, int rx, int qlx, int qrx, int qly, int qry) {
        if (qrx < lx || qlx > rx) return 0;
        if (qlx<=lx && qrx>=rx) {
			return query_y(node_x, 1, 1, this->m, qly, qry);
		}
        int mx = (lx + rx) / 2;
        int res = query_x(2*node_x, lx, mx, qlx, qrx, qly, qry) + query_x(2*node_x+1, mx+1, rx, qlx, qrx, qly, qry);
        return res;
    }
};

void solve() {
	int n, q; cin >> n >> q;
	char in; 
	SegmentTree st(n + 1, n + 1);
	for (int r = 1; r <= n; ++r) {
		for (int c = 1; c <= n; ++c) {
			cin >> in;
			int ok = in == '*';
			M[r][c] = ok;
		}
	}

	st.build_x(1, 1, n);

	int r1, r2, c1, c2, row, col;
	while (q--) {
		int f; cin >> f;
		if (f == 1) {
			cin >> row >> col;
			M[row][col] = !M[row][col];
			st.update_x(1, 1, n, row, col, M[row][col]);
		} else {
			cin >> r1 >> c1 >> r2 >> c2;
			int res = st.query_x(1, 1, n, r1, r2, c1, c2);
			cout << res << "\n";
		}
	}

}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}

// 3 4 3 2 1