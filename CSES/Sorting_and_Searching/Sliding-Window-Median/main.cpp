#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define pb push_back
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
#define loop(n) for(int i=0;i<n;++i)
#define loopx(x, n) for(int i=x;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i];
#define ln "\n";

void solve() {
  int n, k; cin >> n >> k;
  int l = 0, r = 0;
  vector<int> nums(n); input(nums, n);

  ordered_set<pair<int, int>> ost;
  loop(k-1) 
    { ost.insert({nums[i], i}); ++r; }

  while (r < n) {
    ost.insert({nums[r], r}); ++r;

    if (k & 1) {
      cout << (*ost.find_by_order(k / 2)).first << " ";
    } else {
      cout << (*ost.find_by_order((k / 2) - 1)).first << " ";
    }
    ost.erase(ost.find({nums[l], l}));
    ++l; 
  }
}

int main() {
  flash
  solve();
  return 0;
}