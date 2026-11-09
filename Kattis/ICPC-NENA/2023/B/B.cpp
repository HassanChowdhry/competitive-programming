#include <bits/stdc++.h>
using namespace std;
int m, n, k, s;
double a[2001], dp[2001][101], cost[2001][2001], prex[2001], pre[2001], pre2[2001];

// dp[i][k] = the first i transmitters covered by k transmitters
void solve () {
    cin >> m >> n >> k >> s;

    for (int i = 1; i <= m; ++i) {
        cin >> a[i];
    }

    for (int i = m+1; i <= m+n; ++i) {
        cin >> a[i];
    }

    n = m + n;
    sort(a+1, a+n+1);
    for (int i = 0; i <= 2000; ++i) {
        for (int j = 0; j <= 100; ++j) {
            dp[i][j] = DBL_MAX;
        }
    }

    dp[0][0] = 0;

    // they are all y = (s/2) away no ?
    // x value wise, maybe take avg ? of i
    // need min sum of squared distances
    // dp[i][k] = min(dp[i][k], dp[j][k-1] + cost(j+1))
    // cost = SUM ( AVG - xj )^2 + (s/2)^2
    double ss = s/2.0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= n; ++j) {
            prex[j] = prex[j-1] + a[j];
            pre[j] = pre[j-1] + (a[j] * a[j]);
            pre2[j] = pre2[j-1] + (ss * ss);
        }

        for (int j = i; j <= n; ++j) {
            double x = pre[j] - ((prex[j] * prex[j]) / (j - i + 1.0));
            // cout << x << " ";
            double y = pre2[j];
            cost[i][j] = x + y;
            prex[j] = 0; pre[j] = 0; pre2[j] = 0;
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= k; ++j) {
            for (int z = 0; z < i; ++z) {
                dp[i][j] = min(dp[i][j], dp[z][j-1] + cost[z+1][i]);
            }
        }
    }

    cout << fixed << setprecision(6) << dp[n][k];
}

int main() {
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
    solve();
    return 0;
}