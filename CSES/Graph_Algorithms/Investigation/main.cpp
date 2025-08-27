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

ll dfs(int node, ll curr, int n, vector<ll>& cost, vector<ll>& ways, vector<vector<pair<int, int>>>& adj) {
  if (curr > cost[node]) return 0;
  if (node == n) return 1LL;
  if (ways[node] >= 0) return ways[node];
  ll res = 0;
  for (auto [child, ncost]: adj[node]) {
    if (ncost + curr > cost[child]) continue;
    res += dfs(child, curr + ncost, n, cost, ways, adj) % MOD;
  }
  ways[node] = res % MOD;
  return ways[node];
}

void solve() {
  ll n, k; cin >> n >> k;
  vector<vector<pair<ll, ll>>> adj(n + 1);
  for (ll i=0; i < k; ++i) {
    ll u, v, c; cin >> u >> v >> c;
    adj[u].pb({v, c});
  }

  // djikstra(1, n, adj);
  vector<ll> costs(n + 1, LLONG_MAX), ways(n + 1, 0);
  vector<ll> mn(n + 1, LLONG_MAX), mx(n + 1, LLONG_MIN);
  costs[1] = 0; ways[1] = 1; mn[1] = 0; mx[1] = 0;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q; // costs, idx
  q.push({ 0, 1 });

  while (!q.empty()) {
    auto [cost, node] = q.top(); q.pop();
    if (cost > costs[node]) continue;

    for (auto [next, ncost] : adj[node]) {
      if (ncost + cost < costs[next]) {
        costs[next] = ncost + cost;
        ways[next] = ways[node] % MOD;
        mn[next] = mn[node] + 1;
        mx[next] = mx[node] + 1;
        q.push({ ncost + cost, next });
      } else if (ncost + cost == costs[next]) {
        ways[next] += ways[node] % MOD;
        ways[next] %= MOD;
        mn[next] = min(mn[next], mn[node] + 1);
        mx[next] = max(mx[next], mx[node] + 1);
      }
    }
  }
  
  cout << costs[n] << " " << ways[n] << " " << mn[n] << " " << mx[n];

  // ways?
  // ll way = dfs(1, 0, n, cost, ways, adj);

  // cout << way;
  // cout << cost[n] << " " << way << " " << minn << " " << maxx;
}

int main() {
  flash;
  solve();
  return 0;
}