#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    long long ans = 0;

    for (int i = 2; i <= n; ++i) {
      if (i % 2) ans = ans * 2 + 1;
    }

    cout << ans;
}

int main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}