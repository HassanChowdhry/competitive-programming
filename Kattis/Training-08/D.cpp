#include <bits/stdc++.h>
using namespace std;
#define ll long long
void LSH() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

vector<int> nums;
int n, k; 
ll dp[19][51][51][51];

ll rec(int c, int i, int p1, int p2) {
    if (dp[c][i][p1][p2] != 0) return dp[c][i][p1][p2];
    if (k == c) return 1;
    if (i >= n) return 0;
    ll x = 0;

    for (int j = i + 1; j < n; ++j) {
        if (nums[p1] + nums[p2] < nums[j]) break;
        x += rec(c + 1, j, j, p1);
    }
    dp[c][i][p1][p2] = x;
    return x;
}

void solve() {
    cin >> n >> k;
    nums.resize(n); for (int i = 0; i < n; ++i) cin >> nums[i];
    sort(nums.begin(), nums.end());

    ll x = 0;
    for (int i = 0; i <= n - k; ++i) {
        for (int j = i + 1; j < n; ++j) {
            x += rec(2, j, j, i);
        }
    }

    cout << x;
}

int main() {
    LSH();
    solve();
}