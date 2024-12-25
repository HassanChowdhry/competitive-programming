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
int MOD=1000000007;

void solve() {
  int n, target; cin >> n >> target;
  vector<pair<ll, ll>> nums(n);
  rep(i, n) {
    cin >> nums[i].fs; nums[i].sc = i+1;
  } sort(nums.begin(), nums.end());
  int l, r;
  rep(pivot, n-2) {
    l = pivot + 1; r = n - 1;
    while (l < r) {
      ll curr = nums[pivot].fs + nums[l].fs + nums[r].fs;
      if (curr == target) {
        cout << nums[pivot].sc << " " << nums[l].sc << " " << nums[r].sc; return;
      } else if (curr < target) {
        ++l;
      } else {
        --r;
      }
    }
  }
  cout << "IMPOSSIBLE";
}

int main() {
  flash;
  solve();
  return 0;
}