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

int first_max[2000005];
int second_max[2000005];
int child_path[2000005];

void dfs(int node, int parent, vector<vector<int>>& adj) {
  for (int child : adj[node]) {
    if (child == parent) continue;

    dfs(child, node, adj);
    if (first_max[child] + 1 > first_max[node]) {
      second_max[node] = first_max[node];
      first_max[node] = first_max[child] + 1;
      child_path[node] = child;
    } else if (first_max[child] + 1 > second_max[node]) {
      second_max[node] = first_max[child] + 1;
    }
  }
}

void dfs2(int node, int parent, vector<vector<int>>& adj) {
  for (int child : adj[node]) {
    if (child == parent) continue;

    if (child_path[node] == child) {
      if (second_max[node] + 1 > first_max[child]) {
        first_max[child] = second_max[node] + 1;
        child_path[child] = node;
      } else if (second_max[node] + 1 > second_max[child]) {
        second_max[child] = second_max[node] + 1;
      }
    } else {
      first_max[child] = max(first_max[child], first_max[node] + 1);
      child_path[child] = node;
    }
    dfs2(child, node, adj);
  }
}

void solve() {
  int n; cin >> n;
  vector<vector<int>> adj(n+1);

  int a, b;
  rep(i, n-1) {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  dfs(1, 0, adj);
  dfs2(1, 0, adj);
  repx(i, 1, n+1) { 
    cout << first_max[i] << " ";
  }
}

int main() {
  flash;
  solve();
  return 0;
}