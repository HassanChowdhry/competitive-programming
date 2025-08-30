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

int parent[200005];
int rankk[200005];

// find parent
int find(int x) {
  if (parent[x] != x) parent[x] = find(parent[x]);
  return parent[x];
}

bool onion(int x, int y) {
  int px = find(x), py = find(y);
  // cout << x << " " << px << ln;
  // cout << y << " " << py << ln << ln;
  if (px == py) return false;

  if (rankk[py] > rankk[px]) swap(px, py);

  rankk[px] += rankk[py];
  parent[py] = px;
  return true;
}

void solve() {
  int n, k, u, v, c; cin >> n >> k;
  vector<vi> edges;
  rep(i, k) { cin >> u >> v >> c; edges.pb({ u, v, c }); }
  for(int i = 0; i < 200005; ++i) parent[i]=i;

  sort(edges.begin(), edges.end(), [](const auto &a, const auto &b){ return a[2] < b[2]; });
  // onion, find
  ll res = 0;
  rep(i, k) {
    if (onion(edges[i][0], edges[i][1])) res += edges[i][2];
  }

  int parent = find(1);
  for (int i = 2; i <= n; ++i) {
    if (parent != find(i)) { cout << "IMPOSSIBLE"; return; }
  }

  cout << res;
  
}

int main() {
  flash;
  solve();
  return 0;
}