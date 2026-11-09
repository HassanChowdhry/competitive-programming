#include <bits/stdc++.h>
using namespace std;

double r, s, h, t, td, d, d1, n1, n2, n3, err, cer, rem, ld, cd;
int o1, o2, o3;
void solve() {
    cin >> r >> s >> h;
    t = (2.0 * r * M_PI) / s;
    td = t / h;
    d = (int)td;
    o1 = -1, o2 = -1, o3 = -1;
    err = td;
    d = round(td);
    int ok = 1;
    if (d > td) {
        ok = 0;
    }

    // cout << (int)n1 << " " << (int)n2 << " " << (int)n3;

    for (int n1 = 2; n1 <= 1000; ++n1) {
        for (int n2 = n1 + n1; n2 <= 1000; n2 += n1) {
            for (int n3 = n2 + n2; n3 <= 1000; n3 += n2) {
                if (ok) {
                    cd = d + (1.0/n1) - (1.0/n2) + (1.0/n3);
                    cer = abs(cd - td);

                    // cout << cd << " " << td << "\n";

                    if (cer < err) {
                        o1 = n1; o2 = n2; o3 = n3;
                        err = cer;
                    }
                } else {
                    cd = d - (1.0/n1) + (1.0/n2) - (1.0/n3);
                    cer = abs(cd - td);

                    if (cer < err) {
                        o1 = n1; o2 = n2; o3 = n3;
                        err = cer;
                    }
                }
                
            }
        }
    }

    

    cout << o1 << " " << o2 << " " << o3 << "\n";   
    // cout << d << " " << o1 << " " << o2 << " " << o3 << "\n";   
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}