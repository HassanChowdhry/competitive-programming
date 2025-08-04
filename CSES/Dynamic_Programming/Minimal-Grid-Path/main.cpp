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
  vector<vector<char>> grid(n, vector<char>(n));
  vector<vector<int>> vis(n, vector<int>(n, 0));
  queue<pair<int, int>> q; q.push({0,0});
  rep(i, n) rep(j, n) cin >> grid[i][j];
  string res = "";
  while (!q.empty()) {    
    int len = q.size();
    char min_char = 'z';
    queue<pair<int, int>> q2(q);
    rep(_, len) {
      auto[x, y] = q2.front(); q2.pop();
      min_char = min(min_char, grid[x][y]);
    }
    
    res += min_char;
    rep(_, len) {
      auto[x, y] = q.front(); q.pop();
      
      if (grid[x][y] == min_char) {
        if (x+1 < n && !vis[x + 1][y]) {
          vis[x+1][y] = 1;
          q.push({x+1,y});
        }
        if (y+1 < n && !vis[x][y+1]) {
          vis[x][y+1] = 1;
          q.push({x,y+1});
        }
      }
    } 
    
  }

  cout << res;
}

int main() {
  flash;
  solve();
  return 0;
}