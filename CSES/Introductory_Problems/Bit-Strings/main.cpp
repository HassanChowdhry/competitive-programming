#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"
int MOD=1000000007;
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

void solve() {
  ll n; cin >> n;
  cout << powMod(2, n);
}

int main() {
  flash;
  solve();
  return 0;
}