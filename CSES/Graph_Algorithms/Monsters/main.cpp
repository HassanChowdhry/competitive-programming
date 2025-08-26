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

int h[] = {1, -1, 0, 0};
int v[] = {0, 0, 1, -1};

string reconstruct_path(vector<vector<pair<int, int>>>& parent, int si, int sj, int i, int j) {
  string path;
  
  while (i != si || j != sj) {
    int pi = parent[i][j].fs, pj = parent[i][j].sc;
    if (pi == -1 || pj == -1) { return "NO"; }
    if (i == pi + 1) path += 'D';
    else if (i == pi - 1) path += 'U';
    else if (j == pj + 1) path += 'R';
    else if (j == pj - 1) path += 'L';
    i = pi;
    j = pj;
  }

  reverse(path.begin(), path.end());
  return path;
}

void solve() {
  int n, m, si, sj; cin >> n >> m;

  vector<vector<char>> grid(n, vector<char>(m));
  vector<vector<bool>> vis(n, vector<bool>(m, false));
  vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, { -1, -1 }));

  rep(i, n) rep(j, m) cin >> grid[i][j];

  vector<vector<char>> moves(n, vector<char>(m));
  bool yes = false;
  queue<pair<pair<int, int>, pair<char, int>>> q; // i, j, A/M
  rep(i, n) rep(j, m) if (grid[i][j] == 'A') { si = i; sj = j; q.push({{ i, j }, { grid[i][j], 0 }}); }
  rep(i, n) rep(j, m) if (grid[i][j] == 'M') { q.push({{ i, j }, { grid[i][j], 0 }}); }   
  
  while (!q.empty()) {
    auto x = q.front(); q.pop();
    int i = x.fs.fs, j = x.fs.sc;
    char curr = x.sc.fs;
    int moves = x.sc.sc;
    if ( vis[i][j] ) continue;
    if (curr == 'A' && (i == 0 || j == 0 || i == n-1 || j == m-1)) { 
      string path = reconstruct_path(parent, si, sj, i, j);
      if (path != "NO") { yes = true; cout << "YES" << ln << moves <<ln << path; return; }
    }
    vis[i][j] = true;

    for (int k = 0; k < 4; ++k) {
      int pi = i + h[k];
      int pj = j + v[k];
      if (pi < 0 || pj < 0 || pi >= n || pj >= m || vis[pi][pj] || grid[pi][pj] != '.') continue;
      if (curr == 'A') parent[pi][pj] = { i, j };
      else if (curr == 'M') parent[pi][pj] = { -1, -1 };
      q.push({{pi, pj}, { curr, moves + 1 }});
    }
  }

  if (!yes) { cout << "NO"; return; }
}

int main() {
  flash;
  solve();
  return 0;
}