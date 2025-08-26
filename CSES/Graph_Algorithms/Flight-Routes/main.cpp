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
const ll INF = 1e18L+5;
int MOD=1000000007;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

// you could also just cnt the number of times you arrived at node, cz first k times is the quickest always
void solve() {
  int n, m, k, curr = 0; cin >> n >> m >> k;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq; // cost, node
  vector<priority_queue<ll>> costs(n + 1);
  pq.push({ 0, 1 });
  // vector<int> costs(n + 1, INF);
  vector<vector<pair<int, ll>>> adj(n + 1);
  
  
  rep(i, m) {
    int u, v, c; cin >> u >> v >> c;
    adj[u].pb({ v, c });
  } 

  while (!pq.empty()) {
    auto [cost, next] = pq.top(); pq.pop();
    // cout << cost << " " << next << ln;
    if (costs[next].size() < k) { costs[next].push(cost); }
    else { 
      if (costs[next].top() > cost) { costs[next].pop(); costs[next].push(cost); }
      else continue;
    }
    if (next == n) { ++curr; cout << cost << " "; if (curr == k) return; }

    // if (costs[next] < cost) continue;
    // costs[next] = cost;
    for (auto [to, c] : adj[next]) {
      if (costs[to].size() == k && costs[to].top() <= cost + c) { continue; }
      pq.push({ c + cost, to });
    }
  }
}

int main() {
  flash;
  solve();
  return 0;
}