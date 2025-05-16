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

void solve() {
  int n, k; cin >> n >> k;
  vector<ll> dist(n+1, LLONG_MIN);
  vector<vector<ll>> edges(k, vector<ll>(3, 0)); // start, end, cost
  int u, v, c;
  rep(i, k) {
    cin >> u >> v >> c;
    edges[i][0] = u;
    edges[i][1] = v;
    edges[i][2] = -c;
  }

  bool improv = true;
  for (int i = 0; i < n && improv; ++i) {
    improv = true;
    for (vector<ll> edge: edges) {
      u = edge[0], v = edge[1], c = edge[2];

      if (dist[u] + c < dist[v]) {
        dist[v] = dist[u] + c;
        improv = true;

        if (i == n-1) {
          cout << -1; return;
        }
      }
    }
  }

  cout << dist[n];

}

int main() {
  flash;
  solve();
  return 0;
}