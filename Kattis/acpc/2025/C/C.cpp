#include <bits/stdc++.h>
using namespace std;
#define ln "\n"
char grid[15][15];

int dirx[] = {0, 0, 1, -1, 1, -1, 1, -1};
int diry[] = {-1, 1, 0, 0, 1, -1, -1, 1};

int res = -1, ri = -1, rj = -1;

int calc(int i, int j) {
	int pi, pj;
	int res = 0;
	for (int z = 0; z < 8; ++z) {
		int curr = 0;
		pi = i + dirx[z], pj = j + diry[z];
		while (pi >= 0 && pj >= 0 && pi < 8 && pj < 8 && grid[pi][pj] == 'W') {
			++curr;
			pi += dirx[z], pj += diry[z];
		}
		if (pi >= 0 && pj >= 0 && pi < 8 && pj < 8 && grid[pi][pj] == 'B') {
			res += curr;
		}
	}

	return res;
}

void solve() {
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			cin >> grid[i][j];
		}
	}
	
	for (int i = 0; i < 8; ++i) {
		for (int j = 0; j < 8; ++j) {
			if (grid[i][j] != '.') continue;
			
			int check = calc(i, j);
			// cout << i << " " << j << " " << check << ln;
			if (check > res) {
				res = check;
				ri = i, rj = j;
			}
		}
	}

	cout << ri << " " << rj;
}

int main() {
  solve();
  return 0;
}