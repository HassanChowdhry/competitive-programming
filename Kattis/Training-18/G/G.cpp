#include <bits/stdc++.h>
using namespace std;

void LSH() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

long long W,K,C,dp[505][505];
void solve() {
    cin >> W >> K >> C;
    memset(dp,0,sizeof(dp));
    dp[K][W] = 1;
    for ( int i = K ; i >= 1 ; --i ) {
        for ( int j = W ; j >= 1 ; --j ) {
            for ( int z = 1 ; z <= i - C ; ++z ) {
                if ( j < i || j < z ) {
                    continue;
                }
                dp[z][j - (i-1)] |= dp[i][j];
            }
        }
    }
    for ( int i = 1 ; i <= K ; ++i ) {
        if ( dp[i][i] == 1 ) {
            cout<<"yes";
            return ;
        }
    }
    cout<<"no";
}

int main() {
    LSH();
    solve();
}