#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; cin >> n;
    
    long long ans = n * (n+1) / 2;
    long long ans2 = 0;
    
    for (int i = 1; i <= n; ++i) {
        ans2 += (i * (i + 1) / 2);
    }
    
    cout << ans << "\n" << ans2;
}

int main() {
    solve();
    return 0;
}
