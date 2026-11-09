#include <bits/stdc++.h>
using namespace std;

string n, m, res;
int f['9'+5];

string nxt(string s) {
    for (char a = '0'; a <= '9'; ++a) f[a] = 0;
    
    for (char c : s) {
        ++f[c];
    }

    res = "";
    for (char a = '0'; a <= '9'; ++a) {
        if (f[a]) {
            res += to_string(f[a]);
            res += a;
        }
    }

    return res;
}

void solve() {

    cin >> n >> m;
    int time = 1;

    string prev = "";
    while (time <= 100) {
        if (n == m) {
            cout << time << "\n";
            return;
        }
        n = nxt(n);
        if (prev == nxt(n)) {
            cout << "Does not appear";
            return;
        }
        prev = n;
        ++time;
    }

    if (time >= 100) {
        cout << "I'm bored";
        return;
    }

    cout << "Does not appear";
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}