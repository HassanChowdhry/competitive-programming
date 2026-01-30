#include <bits/stdc++.h>
using namespace std;

#define fs first
#define sc second
#define ln "\n"

void LSH() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

int grid[55][55];
int vis[55][55][4];
int dirx[] = {1, 0, -1, 0}; // left -> +1, right -> -1
int diry[] = {0, -1, 0, 1}; // left -> +1, right -> -1
int dir = 0;

void solve() {
    int sr, scc, er, ec, r, c; 
    cin >> r >> c >> sr >> scc >> er >> ec;

    for (int i = 1; i <= r; ++i) {
        string in; cin >> in;
        for (int j = 1; j <= c; ++j) {
            grid[i][j] = in[j-1] - '0';
        }
    }

    
    pair<int, int> pos = {sr, scc};

    bool ok = true;
    while (ok) {
        int i = pos.fs, j = pos.sc;
        // cout << i << " " << j << " " << dir<< ln;
        
        if (i == er && j == ec) {
            cout << 1 << ln; ok = false; return;
        }
        if (vis[i][j][dir]) { 
            cout << 0 << ln; ok = false; return; 
        }
        vis[i][j][dir] = 1;
        int next = (dir + 1) % 4;
        int prev = (dir - 1 + 4) % 4;

        int pi = i + diry[next];
        int pj = j + dirx[next];

        if (pi > 0 && pj > 0 && pi <= r && pj <= c && grid[pi][pj] == 0 ) {
            dir = next;
            pos = { pi, pj }; 
            continue;
        } 

        pi = i + diry[dir];
        pj = j + dirx[dir];
        if (pi > 0 && pj > 0 && pi <= r && pj <= c && grid[pi][pj] == 0) {
            pos = { pi, pj }; 
            continue;
        }
        dir = prev;
    }
    cout << 0 << ln;
}

int main() {
    LSH();
    int t; cin >> t;
    while (t--) {
        memset(grid, 0, sizeof(grid));
        memset(vis, 0, sizeof(vis));
        dir = 0;
        solve();
    }
}
