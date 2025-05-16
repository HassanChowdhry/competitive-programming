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

ll sum_distance[2000005];
ll size_subtree[2000005];
vector<vector<int>> adj(2000005);
int n;

void dfs(int node, int parent, ll depth) {
  for (int child: adj[node]) {
    if (child == parent) continue;
    dfs(child, node, depth + 1);
  }
  sum_distance[node] = depth;
}

void dfs2(int node, int parent) {
  size_subtree[node] = 1;
  for (int child: adj[node]) {
    if (child == parent) continue;
    dfs2(child, node);
    size_subtree[node] += size_subtree[child];
  }
}

void dfs3(int node, int parent) {
  for (int child: adj[node]) {
    if (child == parent) continue;

    sum_distance[child] = sum_distance[node] + n - 2 * size_subtree[child];
    dfs3(child, node);
  }
}

void solve() {
  cin >> n;
  int a, b;
  rep(i, n-1) {
    cin >> a >> b;
    adj[a].pb(b);
    adj[b].pb(a);
  }

  dfs(1, 0, 0);
  repx(i, 1, n+1) sum_distance[1] += sum_distance[i];
  dfs2(1, 0);
  dfs3(1, 0);

  repx(i, 1, n+1) {
    cout << sum_distance[i] << " ";
  }
  // } cout << ln;
  // repx(i, 1, n+1) {
  //   cout << size_subtree[i] << " ";
  // }
}

int main() {
  flash;
  solve();
  return 0;
}