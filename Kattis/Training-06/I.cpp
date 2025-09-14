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
ll INF = 1e18;

string rotate(string t, int l, int r, int dir) {
  string s = t;
  for (int i = l; i <= r; ++i) {
    int d=(s[i] - '0' + dir +10) % 10;
    s[i] = char('0'+d);
  }

  return s;
}
void solve() {
  string in, out; cin >> in >> out;
  
  queue<pair<string, int>> q;
  unordered_set<string> vis;
  q.push({ in, 0 });

  while (!q.empty()) {
    auto [curr, step] = q.front(); q.pop();

    if (curr == out) { cout << step; return; }

    for (int l = 0; l < 4; ++l) {
      for (int r = l; r < 4; ++r) {
        for (int dir: {-1, 1}) {
          string n = rotate(curr, l, r, dir);
          if (vis.count(n)) continue;
          vis.insert(n);
          q.push({ n, step + 1 });
        }
      }
    }
  }

}

int main() {
  flash;
  // int t; cin >> t;
  // rep(i, t) 
  solve();
  return 0;
}