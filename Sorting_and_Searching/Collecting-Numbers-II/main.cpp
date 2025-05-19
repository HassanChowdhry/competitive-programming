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
int MOD=1000000007;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }

void update(int a, int b, vi& nums, vi& rev_num, int& cnt) {
  // cout << "a: " << a << " nums[a] " << nums[a] << " rev_num[nums[a] + 1] " << rev_num[nums[a] + 1] << " rev_num[nums[a] - 1] " << rev_num[nums[a] - 1] << ln;
  // cout << "b: " << b << " nums[b] " << nums[b] << " rev_num[nums[b] + 1] " << rev_num[nums[b] + 1] << " rev_num[nums[b] - 1] " << rev_num[nums[b] - 1] << ln;
  // cout << ln;
  if (b <= rev_num[nums[a] + 1] && a > rev_num[nums[a] + 1]) --cnt;
  if (b <= rev_num[nums[a] - 1] && a > rev_num[nums[a] - 1]) ++cnt;
  if (b >= rev_num[nums[a] - 1] && a < rev_num[nums[a] - 1]) --cnt;
  if (b >= rev_num[nums[a] + 1] && a < rev_num[nums[a] + 1]) ++cnt;

  if (a < rev_num[nums[b] + 1] && b > rev_num[nums[b] + 1]) --cnt;
  if (a < rev_num[nums[b] - 1] && b > rev_num[nums[b] - 1]) ++cnt;
  if (a > rev_num[nums[b] - 1] && b < rev_num[nums[b] - 1]) --cnt;
  if (a > rev_num[nums[b] + 1] && b < rev_num[nums[b] + 1]) ++cnt;
}
void solve() {
  int n, q; cin >> n >> q;
  int a, b, temp, cnt = 1;
  vi nums(n + 2, 0), rev_num(n + 2, 0);

  nums[0] = rev_num[0] = 0;
  nums[n + 1] = rev_num[n + 1] = n + 1;

  repx(i, 1, n+1) {
    cin >> temp;
    nums[i] = temp;
    rev_num[temp] = i;
  };

  set<int> collected;
  collected.insert(0);
  repx(i, 1, n) {
    if (!collected.count(nums[i]-1))
      { ++cnt; }
    collected.insert(nums[i]);
  }

  rep(_, q) {
    cin >> a >> b;
    update(a, b, nums, rev_num, cnt);
    
    swap(rev_num[nums[a]], rev_num[nums[b]]);
    swap(nums[a], nums[b]);
    
    cout << cnt << ln;
    // repx(i, 1, n + 1) cout << nums[i] << " "; cout << ln;
    // repx(i, 1, n + 1) cout << rev_num[i] << " "; cout << ln << ln;
  }
}

int main() {
  flash;
  solve();
  return 0;
}