#include <bits/stdc++.h>
using namespace std;
#define ii pair<string, string>
#define fi first
#define se second
int n, m;
string w[1505];
ii wp[1505][1505];
int use[1505][1505][25];
map<ii, map<int, map<int, int>>> mp;

void solve() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> w[i];
    }


    for (int i = 1; i <= n; ++i) {
        m = w[i].size();
        
        for (int j = 0; j < m - 1; ++j) {
            string check = "";
            string hint = "";
            hint += w[i][j];
            hint += w[i][j + 1];

            for (int k = 0; k < m; ++k) {
                if (j == k || j + 1 == k) continue;
                check += w[i][k];
            }

            wp[i][j] = {hint, check};
        }
    }

    for (int i = 1; i <= n; ++i) {
        m = w[i].size();
        
        for (int j = 0; j < m - 1; ++j) {
            string hint1 = wp[i][j].fi;
            string blank1 = wp[i][j].se;
            
            for (int k = i + 1; k <= n; ++k) {
                if (k == i) continue;
                if (w[i].size() != w[k].size()) continue;
                string hint2 = wp[k][j].fi;
                string blank2 = wp[k][j].se;
                if (hint1[0] == hint2[0] || hint1[1] == hint2[1]) continue;
                
                if (blank1 == blank2) {
                    int x = blank1.size();
                    int ok = 0;
                    if (hint1 > hint2) { ok = 1; swap(hint1, hint2); }
                    ii key = {hint1, hint2};
                    ++mp[key][j][x];
                    if (ok) swap(hint1, hint2);
                }
            }
        }

    }
    
    int res = 0;
    for (const auto& [key, inner] : mp) {
        for (const auto& [pos, sizes] : inner) {
            for (const auto& [size, cnt] : sizes) {
                if (cnt == 1) res += 1;
            }
        }
    }
    cout << res << "\n";

}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}