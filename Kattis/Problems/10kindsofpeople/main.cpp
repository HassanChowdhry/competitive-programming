#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

int r, c, n;
char grid[1005][1005];
int scc[1005][1005];
int dirx[] = {1, -1, 0, 0};
int diry[] = {0, 0, -1, 1};

void dfs(int i, int j, int comp) {
	scc[i][j] = comp;
    for (int z = 0; z < 4; ++z) {
        int pi = i + dirx[z];
        int pj = j + diry[z];
        
        if (pi <= 0 || pj <= 0 || pi > r || pj > c || scc[pi][pj] || grid[i][j] != grid[pi][pj]) continue;
        dfs(pi, pj, comp);
    }
}
void solve() {
    cin >> r >> c;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> grid[i][j];
        }
    }
    cin >> n;
    
    int res = 1;
    for (int i = 1; i <= r; ++i) {
        for (int j = 1; j <= c; ++j) {
            if (scc[i][j]) continue;
            dfs(i, j, res);
            ++res;
        }
    }

    int r1, r2, c1, c2;
    for (int i = 0; i < n; ++i) {
        cin >> r1 >> c1 >> r2 >> c2;
        if (scc[r1][c1] == scc[r2][c2]) {
            if (grid[r1][c1] == '1') cout << "decimal" << ln;
            if (grid[r1][c1] == '0') cout << "binary" << ln;
        } else cout << "neither" << ln;
    }
}

int main() {
    solve();
    return 0;
}