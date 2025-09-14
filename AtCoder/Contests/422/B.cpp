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
  int n, m; cin >> n >> m;
  vector<vector<char>> grid(n, vector<char>(m));
  for(int i=0; i < n; ++i) for (int j =0; j < m; ++j) cin >> grid[i][j];

  for (int i =0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (grid[i][j] == '.') continue;
      int cnt = 0;

      if (i > 0) cnt += (grid[i-1][j] == '#');
      if (i < n-1) cnt += (grid[i+1][j] == '#');
      if (j > 0) cnt += (grid[i][j-1] == '#');
      if (j < m-1) cnt += (grid[i][j+1] == '#');
      // cout << i << " " << j << " " << cnt << " " << (cnt == 2) << " " << ln;
      if (cnt != 2 && cnt != 4) { cout << "No"; return; }
    }
  }

  cout << "Yes";
}

int main() {
  flash;
  solve();
  return 0;
}