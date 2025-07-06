#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

void solve() {
  int n, k, x; cin >> n >> k;
  vi nums(n + 1, 0);
  ordered_set<pair<int, int>> ost;
  repx(i, 1, n+1) {
    cin >> x;
    nums[i] = x;
    ost.insert({ x, i });
  }

  char v; int a, b;
  rep(_, k) {
    cin >> v >> a >> b;
    if (v == '?') {
      int r = ost.order_of_key({ b, n + 1 });
      int l = ost.order_of_key({ a, 0 });

      cout << r - l << ln;
    } else {
      ost.erase({ nums[a], a });
      nums[a] = b;
      ost.insert({ b, a });
    }
  }
}

int main() {
  flash;
  solve();
  return 0;
}