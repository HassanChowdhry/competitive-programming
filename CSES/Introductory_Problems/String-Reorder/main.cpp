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

void solve() {
  string in; cin >> in; int n = in.size();
  vector<int> cnt(26, 0);
  rep(i, n) ++cnt[in[i] - 'A'];

  int mx = *max_element(cnt.begin(), cnt.end());
  if (mx > n+1 / 2) {
    cout << -1; return;
  }

  vector<char> res(n, 'A'); 
  int prev = -1;
  rep(i, n) {
    bool pick = false;
    for (int j = 0; j < 26; ++j) {
      if (cnt[j] == 0 || j == prev) continue;

      --cnt[j];
      int r = n - i;
      if (*max_element(cnt.begin(), cnt.end()) <= r / 2) {
        res[i] = j+'A';
        pick = true;
        prev = j;
        break;
      }
      ++cnt[j];
    }
    if (!pick) { cout << -1; return; }
  }
  // cout << res[0];
  rep(i, n) cout << res[i];
}

int main() {
  flash;
  solve();
  return 0;
}