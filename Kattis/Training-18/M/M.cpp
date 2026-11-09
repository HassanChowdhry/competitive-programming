#include <bits/stdc++.h>
using namespace std;

long long n, m, l, x, s, mid, d;
long long step[200005][15];
long long X[15];
long long pos[200005];
int out[200005];
vector<int> ans1;

void solve() {
    cin >> n >> m >> l;
    mid = l/2;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= 11; ++j) {
            cin >> step[i][j];
        }
    }

    s = 0;
    for (int o = 1; o <= m; ++o) {
        cin >> x;
        if (x == 12) {
            int ok = 0, fox = -1;
            ans1.clear();
            for (int i = n; i >= 1; --i) {
                if (out[i]) continue;
                for (int j = 1; j <= 11; ++j) {
                    if (!X[j]) continue;
                    pos[i] += (step[i][j] * X[j] * j);
                }
                // cout << pos[i] << " ";
            } 
            // cout << "\n";
            
            for (int i = n; i >= 1; --i) {
                if (out[i]) continue;
                if (pos[i] >= mid) {
                    d = l - pos[i];
                    // cout << d << " d: \n";
                    if (l < (4 * d)) {
                        fox = i;
                        ok = 1;
                    }
                    ans1.push_back(i);
                    out[i] = 1;
                } 
            }

            for (int i = n; i >= 1; --i) {
                if (out[i]) continue;
                if (pos[i] < mid) {
                    if (ok) continue;
                    d = pos[i];
                    if (l < (4 * d)) {
                        fox = i;
                    }
                }
            }
            
            for (int i = n; i >= 1; --i) pos[i] = 0;
            
            // cout << fox << " fox \n";
            // decide which one to catch, right side ans1 -> right, ans2 caught
            if (ans1.size() == 0 || (ans1.size() == 1 && ok)) {
                cout << "None\n";
            } else { 
                sort(ans1.begin(), ans1.end());
                for (int a : ans1) {
                    if (a == fox) continue;
                    cout << a << " ";
                }
                cout << "\n";
            }

            if (fox == -1) {
                cout << "None\n";
            } else { 
                cout << fox << "\n";
                out[fox] = 1;
            }
            // cout << "cooked\n\n";
            for (int j = 1; j <= 11; ++j) X[j] = 0;
        } else {
            ++X[x];
        }

    }
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}