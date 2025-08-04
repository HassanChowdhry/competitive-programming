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

ll f(ll n, ll k) {
  if (n == 1) return 1;

  if (k <= ((n+1) / 2)) {
    if (2*k > n) return 2*k%n;
    else return 2*k;
  }

  ll temp = f(n / 2, k - ((n + 1) / 2));
  if (n % 2) return 2 * temp + 1;
  return 2 * temp - 1;
}
void solve() {
  ll N; cin >> N;
  ll n, k;
  rep(_, N) {
    cin >> n >> k;
    cout << f(n, k) << ln;
  }

}

int main() {
  flash;
  solve();
  return 0;
}