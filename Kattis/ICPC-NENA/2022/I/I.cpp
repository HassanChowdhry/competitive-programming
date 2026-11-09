#include <bits/stdc++.h>
using namespace std;

int n;
long long d[5005], r[5005];
long long dp[5005];

void solve() {
    cin >> n;

    for (int i = 1; i <= n; ++i) {
        cin >> d[i] >> r[i];
    }
    for (int i = 0; i <= n; ++i) dp[i] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i - 1; ++j) {
            int ok1 = !(d[i] - r[i] <= d[j] && d[j] <= d[i] + r[i]);
            int ok2 = !(d[j] - r[j] <= d[i] && d[i] <= d[j] + r[j]);
            if (ok1 && ok2) {
                dp[i] = max(dp[i], dp[j] + 1);
            } else {
                dp[i] = max(dp[i], dp[j]);
            }
        }
    }

    long long res = n - dp[n];

    cout << res;

}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}