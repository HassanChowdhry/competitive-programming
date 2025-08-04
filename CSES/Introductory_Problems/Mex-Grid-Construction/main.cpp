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
  int n; cin >> n;
  vector<vi> grid(n, vi(n, -1));
  multiset<int> seen;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      // seen.clear();
      for (int z = j-1; z >= 0; --z) seen.insert(grid[i][z]);
      for (int z = i-1; z >= 0; --z) seen.insert(grid[z][j]);
      int end = *seen.end();
      // cout << end << " ";
      for (int k = 0 ; k <= end; ++k) {
        if (!seen.count(k)) { grid[i][j] = k; break; }
      }
      seen.clear();
    }
    // cout << ln;
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