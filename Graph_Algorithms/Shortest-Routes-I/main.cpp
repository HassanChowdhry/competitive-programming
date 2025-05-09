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
  int n, k; cin >> n >> k;
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
  map<ll, map<ll, ll>> adj; set<ll> visit;
  map<ll, ll> res;
  ll a, b, c;
  rep(_, k) {
    cin >> a >> b >> c;
    adj[a][b] = min(c, adj[a][b] ? adj[a][b] : MOD);
  }

  pq.push({ 0, 1 }); // cost, city
  while (!pq.empty()) {
    auto [cost, city] = pq.top(); pq.pop();
    if (visit.count(city))
      continue; 
    res[city] = cost;
    visit.insert(city);
    
    for (const auto entry : adj[city]) {
      ll city2 = entry.fs, cost2 = entry.sc;
      if (visit.count(city2)) continue;
      pq.push({ cost2 + cost, city2 });
    }
  }

  for (const auto e: res) {
    cout << e.sc << " ";
  }
}

int main() {
  flash;
  solve();
  return 0;
}