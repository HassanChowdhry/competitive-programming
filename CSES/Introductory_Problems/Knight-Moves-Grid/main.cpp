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
#define vi vector<int>
#define vl vector<ll>
int MOD=1000000007;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

void solve() {
  int n, moves = 0; cin >> n;
  vector<vi> grid(n, vi(n, -1));
  vector<vector<bool>> vis(n, vector<bool>(n, false));

  queue<pair<int, int>> q; // moves, i, j
  q.push({ 0, 0 });

  while (!q.empty()) {
    int m = q.size();
    rep(_, m) {
      auto [i, j] = q.front(); q.pop();
      if (grid[i][j] >= 0) continue;
      grid[i][j] = moves;
      // vis[i][j] = true;
      // if (vis.count({i, j})) continue;

      if (i - 2 >= 0) {
        if (j-1 >= 0 && !vis[i-2][j-1]) { vis[i-2][j-1] = true; q.push({ i-2, j-1 }); }
        if (j+1 < n && !vis[i-2][j+1]) { vis[i-2][j+1] = true; q.push({ i-2, j+1 }); }
      }
      if (i + 2 < n) {
        if (j-1 >= 0 && !vis[i+2][j-1]) { vis[i+2][j-1] = true; q.push({ i+2, j-1 }); }
        if (j+1 < n && !vis[i+2][j+1]) { vis[i+2][j+1] = true; q.push({ i+2, j+1 }); }
      }
      if (i - 1 >= 0) {
        if (j-2 >= 0 && !vis[i-1][j-2]) { vis[i-1][j-2] = true; q.push({ i-1, j-2 }); }
        if (j+2 < n && !vis[i-1][j+2]) { vis[i-1][j+2] = true; q.push({ i-1, j+2 }); }
      }
      if (i + 1 < n) {
        if (j-2 >= 0 && !vis[i+1][j-2]) { vis[i+1][j-2] = true; q.push({ i+1, j-2 }); }
        if (j+2 < n && !vis[i+1][j+2]) { vis[i+1][j+2] = true; q.push({ i+1, j+2 }); }
      }
      // i-1, j+2
    }
    ++moves;
  }

  rep(i, n) {
    rep(j, n) {
      cout << grid[i][j] << " ";
    } cout << ln;
  }
  
}

int main() {
  flash;
  solve();
  return 0;
}