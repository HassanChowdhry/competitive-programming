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

void digit(ll n) {
	if (n <= 9) { cout << n << ln; return; }
	
	ll digit = 1, start = 1;
	while (n > 9 * digit * start) {
		n -= 9 * digit * start;
		digit += 1;
		start *= 10;
	}

	ll offset = (n-1) / digit;
	start += offset;
	n -= (digit * offset);
	
	// return to_string(n);
	// cout << n << " " << digit << " " << start << ln;
	string res = to_string(start);
	// cout << res << ln;
	cout << res[n-1] << ln;
 	// return to_string(start);
}

void solve() {
	int q; cin >> q;
	ll n;
	rep(_, q) {
		cin >> n;
		digit(n);
	}
}

int main() {
  flash;
  solve();
  return 0;
}
