#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define fs first 
#define sc second
#define mod(num, n) (num % n + n) % n
#define all(a) a.begin(),a.end()
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"

void solve() {
  ll n, target, sum = 0, total = 0; cin >> n >> target;
  vector<ll> nums(n); input(nums, n);
  sum = accumulate(nums.begin(), nums.end(), sum);
  map<ll, ll> pre;
  ll prefix = 0, idx;

  rep(i, n) {
    prefix += nums[i];
    idx = prefix - target;
    if (prefix == target) { ++total; }
    if (pre.count(idx)) { total += pre[idx]; }
    ++pre[prefix];
  }

  cout << total;
}

int main() {
  flash;
  solve();
  return 0;
}