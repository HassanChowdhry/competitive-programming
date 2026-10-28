#include <bits/stdc++.h>
using namespace std;


void LSH() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}


struct pos {
	int ai;
	int aj;
	int bi;
	int bj;
	int sch;
};

int n, m;
char g[11][11];
int vis[11][11][11][11][32];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int sch_ok(int i, int j, int sch) {
    int ok = 1;
    for (char c = 'A'; c <= 'D'; ++c) {
        if (g[i][j] != c) continue;
		if ((sch & (1 << (c-'A'))) == 0) ok = 0;
    }

    for (char c = 'a'; c <= 'd'; ++c) {
		if (g[i][j] != c) continue;
 		if ((sch & (1 << (c-'a'))) != 0) ok = 0;
    }

    return ok;
}

int valid(int i, int j) {
    return !(
        i <= 0 || j <= 0 || i > n || j > m || g[i][j] == '*'
    );
}

void solve() {
    cin >> n >> m;
    char c;
    queue<pos> q;
	int ai=-1, aj=-1;
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> c;
            g[i][j] = c;
            if (c == 'S') {
                if (ai == -1 && aj == -1) {
                    ai = i, aj = j;
                } else {
                    q.push({ai, aj, i, j, 0});
					vis[ai][aj][i][j][0] = 1;
                }
            }
        }
    }
// 
	// int ok = sch_ok(1, 1, 4);
	// cout << ok << "\n\n";

    // int ok = 0;
    long long sec = 0;
    while (!q.empty()) {
        int len = q.size();
        while (len--) {
			pos curr = q.front(); q.pop();

			auto [ai, aj, bi, bj, sch] = curr;

			// cout << ai << " " << aj << "\n";
			// cout << bi << " " << bj << "\n";
			// cout << sch << "\n\n";
			
			// cout << sch_ok(1, 1, 4);
            if (g[ai][aj] == 'E' && g[bi][bj] == 'E') {
				cout << sec; 
                return;
            }
			
            for (int i = 0 ; i <= 3; ++i) {
				int nai = ai + dx[i];
                int naj = aj + dy[i];
				int nbi = bi + dx[i];
				int nbj = bj + dy[i];
				int nxt_sch = sch;
				
                if (!valid(nai, naj) || !valid(nbi, nbj)) {
					continue;
                }

				if (g[nai][naj] >= '1' && g[nai][naj] <= '4') {
					nxt_sch = (nxt_sch ^ (1 << (g[nai][naj] - '1')));
				}
				
				if (g[nbi][nbj] >= '1' && g[nbi][nbj] <= '4') {
					nxt_sch = (nxt_sch ^ (1 << (g[nbi][nbj] - '1')));
				}
				
                if (g[nai][naj] == '#' || !sch_ok(nai, naj, sch)) {
					nai = ai; naj = aj;
                }
                
				if (g[nbi][nbj] == '#' || !sch_ok(nbi, nbj, sch)) {
					nbi = bi; nbj = bj;
                }
				
				if ((nai == nbi) && (naj == nbj)) {
					continue;
				}

				if (!sch_ok(nai, naj, nxt_sch) || !sch_ok(nbi, nbj, nxt_sch)) {
					continue;
				}

				// sch = nxt_sch;
				if (vis[nai][naj][nbi][nbj][nxt_sch]) continue;
				vis[nai][naj][nbi][nbj][nxt_sch] = 1;
                
                q.push({nai, naj, nbi, nbj, nxt_sch});
            }
        }
        ++sec;
    }
}

int main() {
    LSH();
    solve();
}