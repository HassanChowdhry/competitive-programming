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
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

void solve() {
  int n, m; cin >> n >> m;
  char in; 
  vector<vector<int>> pref(n+1, vector<int>(n+1, 0));
  rep(i, n) {
    rep(j, n) {
      cin >> in;
      pref[i+1][j+1] = pref[i+1][j];
      if (in == '*') ++pref[i+1][j+1];
    }
  }

  int y1, x1, y2, x2;
  rep(_, m) {
    cin >> y1 >> x1 >> y2 >> x2;
    int total = 0;
    for (int y = y1; y <= y2; ++y) total += pref[y][x2] - pref[y][x1-1];
    cout << total << ln;
  }
}

int main() {
  flash;
  solve();
  return 0;
}