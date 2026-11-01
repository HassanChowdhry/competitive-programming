#include <bits/stdc++.h>
using namespace std;
// dp[i][a][b][c][L]?
// is it that how many a b c I can place at i ? 
// what is the last position I can place a or b or c at?
// int oo = 1e9 + 7;
long long dp[55][55][55][55][5]; // i, a, b, c, Last Placed
long long pd[55][55][55][55][5]; // i, a, b, c, Last Placed
int w, d;
int A = 1, B = 2, C = 3, BB = 4;

void solve() {
  cin >> w >> d;

  dp[1][1][0][0][1] = 1; dp[1][0][1][0][2] = 1; dp[1][0][0][1][3] = 1;

  for (int i = 2; i <= w; ++i) {
    for (int a = 0; a <= i; ++a) {
      for (int b = 0; b <= i; ++b) {
        if (a + b > i) break;
        int c = i - a - b;
        
        if ( a != 0 )
          dp[i][a][b][c][A] = (dp[i-1][a-1][b][c][B] + dp[i-1][a-1][b][c][C] + dp[i-1][a-1][b][c][BB]);
        
        if ( c > 0 )
          dp[i][a][b][c][C] = (dp[i-1][a][b][c-1][A] + dp[i-1][a][b][c-1][B] + dp[i-1][a][b][c-1][BB]);
        
        if ( b != 0 ) {
          dp[i][a][b][c][B] = (dp[i-1][a][b-1][c][A] + dp[i-1][a][b-1][c][C]);
          dp[i][a][b][c][BB] = dp[i-1][a][b-1][c][B];
        }
      }
    }
  }
  long long ans = 0;
  for (int a = 0; a <= w; ++a) {
    for (int b = 0; b <= w; ++b) {
      int c = w - a - b;
      if (a + b + c > w || c < 0) continue;;
      if (max({a, b, c}) - min({a, b, c}) > d) continue;
      for (int L = 1; L <= 4; ++L) {
        ans = (ans + dp[w][a][b][c][L]);
      }
    }
  }

  
  int w2 = (w+1) / 2;
  int d2;
  long long ans2 =0;

  for (int ctr = (w % 2 ? A : 0); ctr <= (w % 2 ? C : 0); ++ctr) {

    for (int i = 1; i <= w2; ++i) {
      for (int a = 0; a <= i; ++a) {
        for (int b = 0; a + b <= i; ++b) {
          for (int L = 1; L <= 4; ++L) {
            pd[i][a][b][i-a-b][L] = 0;
          }
        }
      }
    }

    if ( ctr==A ) {
      pd[1][1][0][0][A] = 1;
    } else if ( ctr==C ) {
      pd[1][0][0][1][C] = 1;
    } else {
      pd[1][0][1][0][BB] = 1;
    }

    for (int i = 2; i <= w2; ++i) {
      for (int a = 0; a <= i; ++a) {
        for (int b = 0; b <= i; ++b) {
          if (a + b > i) break;
          int c = i - a - b;
          if ( a != 0 )
            pd[i][a][b][c][A] = (pd[i-1][a-1][b][c][B] + pd[i-1][a-1][b][c][C] + pd[i-1][a-1][b][c][BB]);
          
          if ( c > 0 )
            pd[i][a][b][c][C] = (pd[i-1][a][b][c-1][A] + pd[i-1][a][b][c-1][B] + pd[i-1][a][b][c-1][BB]);
          
          if ( b != 0 ) {
            pd[i][a][b][c][B] = (pd[i-1][a][b-1][c][A] + pd[i-1][a][b-1][c][C]);
            pd[i][a][b][c][BB] = pd[i-1][a][b-1][c][B];
          }
        }
      }
    }

    for (int a = 0; a <= w2; ++a) {
      for (int b = 0; b <= w2; ++b) {
        int c = w2 - a - b;
        if (a + b + c > w2 || c < 0) continue;
        int aa = 2*a - (ctr == A);
        int bb = 2*b - (ctr == B);
        int cc = 2*c - (ctr == C);
        if (max({aa, bb, cc}) - min({aa, bb, cc}) > d) continue;
        for (int L = 1; L <= 4; ++L) {
          ans2 = (ans2 + pd[w2][a][b][c][L]);
        }
      }
    }
  }

  // cout << ans <<"\n";
  // cout << ans2 <<"\n";
  ans -= ans2;
  cout << ans;
  // cout << ans << " " << ans2 <<"\n";


}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}