#include <bits/stdc++.h>
using namespace std;
#define ln "\n"

void solve() {
    int s, m, n; cin >> s >> m >> n;
    string str;
    for (int i =0; i < n; ++i) {
        cin >> str;
        if (str == "DRIP") {
            int x, y; cin >> x >> y;
            int shares = (x * s) / y;
            int money = (x * s) - (y * shares);
            s += shares;
            m += money;
        } else {
            int x; cin >> x;
            int shares = m / x;
            int money = m - (x * shares);
            m = money;
            s += shares;
        }
    }
    cout << s << "\n" << m;
}
int main() {
    solve();
    return 0;
}