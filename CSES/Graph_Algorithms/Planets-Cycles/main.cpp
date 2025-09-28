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

// int max = 200000;
bool vis[200000];
int dest[200000];
int path_len[200000];
queue<int> path;
int steps = 0;

void dfs(int node) {
  path.push(node);

  if (vis[node]) {
    steps += path_len[node]; return;
  }
  vis[node] = true;
  ++steps;
  dfs(dest[node]);
}

void solve() {
  // functional graph, one edge out only
  // in this question you have to find the path length of the thing
  int n; cin >> n;
  for(int i =0 ; i < n; ++i) { cin >> dest[i]; dest[i]--; };

  for (int i = 0; i < n; ++i) {
    if (vis[i]) continue;

    steps = 0;
    dfs(i);
    int dec = 1;
    
    // path lenght
    while (!path.empty()) {
      if (path.front() == path.back()) { dec = 0; }
      path_len[path.front()] = steps;
      steps -= dec; path.pop();
    }
  }

  for (int i = 0; i < n; ++i) cout << path_len[i] << " ";
}

int main() {
  flash;
  // int t; cin >> t;
  // rep(i, t) 
  solve();
  return 0;
}