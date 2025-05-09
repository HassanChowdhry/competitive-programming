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

// floyd warshall, then just query the matrix
void solve() {
  int n, m, q; cin >> n >> m >> q;
  vector<vector<ll>> dist(n+1, vector<ll>(n+1, LLONG_MAX));
  ll a, b, c;
  rep(i, n+1) dist[i][i] = 0; 
  rep(_, m) {
    cin >> a >> b >> c;
    if (c < dist[a][b]) {
      dist[a][b] = c;
      dist[b][a] = c;
    };
  }

  for (ll k = 1; k <= n; k++) {
    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if(dist[i][k] < LLONG_MAX && dist[k][j] < LLONG_MAX)
              dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }
  }

  rep(_, q) {
    cin >> a >> b;
    if (dist[a][b] >= LLONG_MAX) { cout << -1 << ln; continue; }
    cout << dist[a][b] << ln;
  }
}

int main() {
  flash;
  solve();
  return 0;
}