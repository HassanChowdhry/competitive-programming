#include <bits/stdc++.h>
using namespace std;
#define ii pair<char, char>
#define fi first
#define se second

int l, c, p, cas;
char r, s;
ii cards[55];

void remove(int adj, int& p) {
    if (!adj) {
        cards[p-3] = cards[p-2];
        cards[p-2] = cards[p-1];
        cards[p] = {};
        cards[p-1] = {};
        p -= 2;
        return;
    }

    for (int i = 0; i <= 3; ++i) {
        cards[p-i] = {};
    }

    p -= 4;
    return;
}

int cascade(int p) {
    int adj = 0;
    for (int i = p; i >= 4; --i) {
        if (cards[i].fi == cards[i-3].fi) {
            return i;
        } else if (cards[i].se == cards[i-3].se && !adj) {
            adj = i;
        }
    }
    
    return adj;
}

int cascade_remove(int adj, int i, int m) {
    if (!adj) {
        // cout << "HERE\n";
        cards[i-3] = cards[i-2];
        cards[i-2] = cards[i-1];

        for (int j = i-1; j <= m-1; ++j) {
            cards[j] = cards[j+2];
        }

        for (int j = 0; j <= 1; ++j) {
            cards[m-j] = {};
        }

        m -= 2;
        return m;
    }

    for (int j = i + 1; j <= m; ++j) {
        cards[j-4] = cards[j];
    }

    for (int j = 0; j <= 3; ++j) {
        cards[m-j] = {};
    }

    m -= 4;
    return m;
}

void solve() {
    l = 4, c = 13;
    p = 1;

    for (int i = 1; i <= l; ++i) {
        for (int j = 1; j <= c; ++j) {
            cin >> r >> s;
            cards[p] = {r, s};
            if (p <= 3) { ++p; continue; }
            cas = 0;
            
            if (cards[p].fi == cards[p-3].fi || cards[p].se == cards[p-3].se) {
                if (p <= 3) break;
                int ok = cards[p].fi == cards[p-3].fi;                
                if (ok) remove(1, p);
                else remove(0, p);
                int k;
                 while ((k = cascade(p))) {
                    ok = cards[k].fi == cards[k-3].fi;
                    if (ok) p = cascade_remove(1, k, p);
                    else p = cascade_remove(0, k, p);
                }
            }
            ++p;
        }
    }

    --p;
    cout << p << " ";
    for (int i = 1; i <= p; ++i) {
        cout << cards[i].fi << cards[i].se << " ";
    }
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}