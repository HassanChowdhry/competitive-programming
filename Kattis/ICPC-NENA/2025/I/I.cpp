#include <bits/stdc++.h>
#define ios() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
using namespace std;

int g[105][105];
void solve(){
    int n; cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cin >> g[i][j];
        }
    }
    int ok = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (g[i][j] == 100) continue;
            
            if (i-1 > 0 && j-1 > 0) {
                if (g[i-1][j-1] != 100 && g[i][j-1] != 100) {
                if (g[i-1][j-1] != g[i][j] + g[i][j-1]) {
                    ok = 0;
                }
                }
                
            }
            if (i-1 > 0 && j+1 <= i) {
                if (g[i-1][j] != 100 && g[i][j+1] != 100) {
                    if (g[i-1][j] != g[i][j] + g[i][j+1]) {
                    ok = 0;
                }
                }
                
            }
            if (i+1 <= n && j+1 <= i) {
                if (g[i+1][j] != 100 && g[i+1][j+1] != 100) {
                 if (g[i][j] != g[i+1][j] + g[i+1][j+1]) {
                    ok = 0;
                }                   
                }
            }
        }
    }

    if (!ok) {
        cout << "no solution"; return;
    }

    for (int k = 1; k <= 1000; ++k) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            // cout << i << " " << j << " = " << g[i][j] << "\n";
            if (i-1 > 0 && j-1 > 0) {
                if (g[i-1][j-1] != 100 && g[i][j-1] != 100) {
                    int value = g[i-1][j-1] - g[i][j-1];

                    if (value >= 100 || value < -99 ||
                        (g[i][j] != 100 && g[i][j] != value)) {
                        cout << "no solution";
                        return;
                    }
                    
                    g[i][j] = value;
                }
            }
            if (i-1 > 0 && j+1 <= i) {
                if (g[i-1][j] != 100 && g[i][j+1] != 100) {
                    int value = g[i-1][j] - g[i][j+1];

                    if (value >= 100 || value < -99 ||
                        (g[i][j] != 100 && g[i][j] != value)) {
                        cout << "no solution";
                        return;
                    }
                    
                    g[i][j] = value;
                }
            }
            if (i+1 <= n && j+1 <= i+1) {
                if (g[i+1][j] != 100 && g[i+1][j+1] != 100) {
                    int value = g[i+1][j] + g[i+1][j+1];

                    if (value >= 100 || value < -99 ||
                        (g[i][j] != 100 && g[i][j] != value)) {
                        cout << "no solution";
                        return;
                    }
                    
                    g[i][j] = value;
                }
            }
            // cout << i << " " << j << " = " << g[i][j] << "\n";

            if (g[i][j] > 100 || g[i][j] < -99) {
                cout << "no solution";
                return;
            }
        }
    }}
    

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            if (g[i][j] == 100) {
                cout << "ambiguous";
                return;
            }
            if (g[i][j] >= 100) {
                cout << "no solution";
                return;
            }
        }
    }
    cout << "solvable" << "\n";
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << g[i][j] << " ";
        } cout << "\n";
    }

}


int main(){
    ios();
    solve();
    return 0;
}