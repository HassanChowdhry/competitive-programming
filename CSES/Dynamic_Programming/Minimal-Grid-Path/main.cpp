#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define all(a) a.begin(),a.end()
#define mod(num, n) (num % n + n) % n
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define test int t;cin>>t;while(t--)
#define rep(i,n) for(int i=0;i<n;++i)
#define repx(i,x,n) for(int i=x;i<n;++i)
#define per(i,n) for(int i=n-1;i>=0;--i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define rem(mp, el) if(mp[el]==0)mp.erase(el)
#define ln "\n"
int MOD=1000000007;

void solve() {
  int n; cin >> n;
  vector<vector<int>> grid(n, vector(n, 0)), dp(n, vector(n, 0));
  vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(n, {0, 0}));
  char temp;
  rep(i, n) {
    rep(j, n) {
      cin >> temp; grid[i][j] = (temp - 'A');
    }
  }

  dp[0][0] = grid[0][0];
  parent[0][0] = { -1, -1 };

  repx(i, 1, n) {
    parent[i][0] = { i-1, 0 };
    parent[0][i] = { 0, i-1 };
    dp[i][0] = grid[i][0] + dp[i-1][0];
    dp[0][i] = grid[0][i] + dp[0][i-1];
  }

  repx(i, 1, n) {
    repx(j, 1, n) {
      if (dp[i-1][j] < dp[i][j-1]) {
        dp[i][j] = grid[i][j] + dp[i-1][j];
        parent[i][j] = {i-1, j};
      } else {
        dp[i][j] = grid[i][j] + dp[i][j-1];
        parent[i][j] = {i, j-1};
      }

    }
  }

  int r = n-1, c = n-1;
  string res = "";
  while ( r >= 0 && c >= 0 ) {
    res += (grid[r][c] + 'A');
    int ti = parent[r][c].fs;
    int tj = parent[r][c].sc;
    r = ti;
    c = tj;
  }
  reverse(res.begin(), res.end());
  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}