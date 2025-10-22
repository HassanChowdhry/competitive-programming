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

int A[500005];
int n; 

bool valid(int val) {
  queue<int> q;
  vector<int> vis(n);
  int cnt = 0;
  for (int i =0; i < n; ++i) { if (A[i] <= val) { q.push(i); vis[i]=1; ++cnt; }}

  while (!q.empty()) {
    int x = q.front(); q.pop();

    if (x > 0) { 
      if (!vis[x-1] && abs(A[x-1] - A[x]) <= val) {
        vis[x-1] = 1;
        q.push(x-1);
        ++cnt;
      }
    }
    if (x < n-1) {
      if (!vis[x+1] && abs(A[x+1] - A[x]) <= val) {
        vis[x+1] = 1;
        q.push(x+1);
        ++cnt;
      }
    }

    if (cnt == n) return true;
  }
  
  return false;
}

void solve(int t) {
  cin >> n;
  for (int i =0; i < n; ++i) { cin >> A[i]; };
  if (n == 1) { 
    cout << "Case #" << t << ": " << A[0] << ln;
    return;
  }

  int l = 0, r = 1e9+7;
  int res = 1e9+7;
  while ( l <= r ) {
    int mid = (l + r) / 2;

    if (valid(mid)) {
      res = mid;
      r = mid - 1;
    } else l = mid + 1;

  }

  cout << "Case #" << t << ": " << res << ln;
}

int main() {
  flash;
  int t; cin >> t;
  for (int i = 1; i <= t; ++i) 
    solve(i);
  return 0;
}