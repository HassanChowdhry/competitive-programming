#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"

void solve() {
  int n, x; cin >> n >> x;
  vector<int> nums(n); input(nums, n);
  
  int l = 0, sum = 0, total = 0;
  rep(r, n) {
    sum += nums[r];
    
    while (sum > x && l < r) {
      sum -= nums[l++];
    } 
    
    if (sum == x) ++total;
  }

  cout << total;
}

int main() {
  flash;
  solve();
  return 0;
}