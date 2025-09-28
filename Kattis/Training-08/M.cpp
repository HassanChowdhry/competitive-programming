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
  int m = pow(2, n);
  vector<vi> M(m, vi(m));
  for (int i = 0; i < m; ++i) for (int j = 0; j < m; ++j) cin >> M[i][j];
  ll color = (pow(4, n) - 1) / 3;
  vector<int> colors(color + 1);
  
  // cout << m << ln;
  for (int i = 0 ; i < m; ++i) {
    for (int j = 0; j < m; ++j) {
      if (M[i][j] == 0) continue;

      if (i + 1 < m && j + 1 < m && M[i][j] == M[i+1][j] && M[i+1][j] == M[i][j+1]) {
        colors[M[i][j]] += 1;
      } 
      if (j - 1 >= 0 && i + 1 < m && M[i][j] == M[i+1][j] && M[i+1][j] == M[i][j-1]) {
        colors[M[i][j]] += 1;
      }
      if (j - 1 >= 0 && i - 1 >= 0 && M[i][j] == M[i-1][j] && M[i-1][j] == M[i][j-1]) {
        colors[M[i][j]] += 1;
      }
      if (j + 1 >= 0 && i - 1 >= 0 && M[i][j] == M[i-1][j] && M[i-1][j] == M[i][j+1]) {
        colors[M[i][j]] += 1;
      }
    }
  }

  bool check = true;
  for (int i = 1; i <= color; ++i) {
    if (colors[i] != 1) check = false;
  }

  if (check) cout << 1;
  else cout << 0;
}

int main() {
  flash;
  // int t; cin >> t;
  // rep(i, t) 
  solve();
  return 0;
}