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
  int n; cin >> n;
  vector<int> nums(n); input(nums, n);
  int x, y, e1, e2, e3, e4, diff;
  int curr, prev = nums[0];
  
  // repx(i, 2, n + 1) {
  //   curr = nums[i-1];
  //   diff = curr - prev;
  //   // x * (i) + (n - i + 1) * y
  //   // diff between the two should be same and satisfy the condition above
  //   // y = diff + x
  //   // x * (i) + (n - i + 1) * (diff + x)
  //   // so whatever eq must be solvable and should be same for the rest
  //   e1 = i + (n - i + 1);
  //   e2 = curr - ((n - i + 1) * -diff);

  //   e3 = (i-1) + (n - (i-1) + 1);
  //   e4 = prev - ((n - (i-1) + 1) * -diff);
  //   cout << curr << " " << prev << " " << ln;
  //   cout << e1 << " " << e2 << " " << e2 % e1 << ln;
  //   cout << e3 << " " << e4 << " " << e4 % e3 << ln;
  //   prev = curr;
  //   bool check = e2 % e1 == 0;
  //   // cout << check << ln;

  //   if (!check){ cout << "NO" << ln; return;}
  // }
  // // cout << ln;
  // cout << "YES" << ln;


  diff = nums[1] - nums[0];
  repx(i, 2, n) {
    if (nums[i] - nums[i - 1] != diff) {
      cout << "NO" << ln; return;
    }
  }

  int c = nums[0] - diff;                   
  if (c < 0 || c % (n + 1) != 0) {
    cout << "NO" << ln; return;
  }

  y = c / (n + 1);               
  x = y + diff;
  if (x < 0) {
    cout << "NO" << ln; return;
  }
  cout << "YES" << ln;
}

int main() {
  flash;
  int t; cin >> t;
  rep(i, t)
    solve(); 
  return 0;
}