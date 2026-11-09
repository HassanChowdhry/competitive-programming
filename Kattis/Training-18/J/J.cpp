#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>
#define fi first
#define se second
int n, m, x, y, t, k, ans;
char d;
map<int, set<ii>> X, Y;
vector<int> spy;
ii T[500000];
int D[500000];

void hit(set<ii>& ost, int dir, int pos, int t) {
    spy.clear();
    ans = 0;

    auto it = ost.find({pos, t});

    if (dir == -1) {
        // cout << dir << " " << "\n";
        while (it != ost.begin()) {
            ii p = *ost.begin();
            if (D[p.se] == 0) {
                spy.push_back(p.se);
                D[p.se] = 1;
                ++ans;
            }
            ost.erase(p);
        }
    } else {
        auto end_pt = ost.end();
        --end_pt;
        while (it != end_pt) {
            ii p = *ost.rbegin();
            if (D[p.se] == 0) {
                spy.push_back(p.se);
                D[p.se] = 1;
                ++ans;
            }
            ost.erase(p);
            end_pt = ost.end(); end_pt--;
        }
    } 

    cout << ans << " ";
    for (int i = ans - 1; i >= 0; --i) cout << spy[i] << " ";
    cout << "\n";

}

void solve() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> x >> y;
        T[i] = {x, y};
        X[x].insert({y, i});
        Y[y].insert({x, i});
    }

    for (int i = 1; i <= m; ++i) {
        cin >> t >> d;
        if (D[t]) {
            cout << "ignore\n"; continue;
        } 
        auto [x, y] = T[t];
        
        if (d == 'E' || d == 'W') {
            // cout << x << " " << y << "\n";
            hit(Y[y], (d == 'E' ? 1 : -1), x, t);
        } else {
            hit(X[x], (d == 'N' ? 1 : -1), y, t);
        }
    }


}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}