#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define ll long long
#define pb push_back
#define fs first 
#define sc second 
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i];
#define ln "\n";

class SegmentTree {
private:
  vector<int> tree;
  int n;

  void buildTree(vector<int>& nums, int left, int right, int index) {
    if (left == right) 
      { tree[index] = nums[left]; return; }
    int mid = left + (right - left) / 2;
    buildTree(nums, left, mid, 2 * index + 1);
    buildTree(nums, mid + 1, right, 2 * index + 2);
    tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
  }

  int query(int left, int right, int index, int qleft, int qright) {
    if (qright < left || qleft > right) return 0;
    if (qleft <= left && right <= qright) return tree[index];
    int mid = left + (right - left) / 2;
    return query(left, mid, 2 * index + 1, qleft, qright) +
      query(mid + 1, right, 2 * index + 2, qleft, qright);
  }

  void update(int left, int right, int index, int pos, int val) {
    if (left == right) 
      { tree[index] = val; return; }
    int mid = left + (right - left) / 2;
    if (pos <= mid) update(left, mid, 2 * index + 1, pos, val);
    else update(mid + 1, right, 2 * index + 2, pos, val);
    tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
  }
  
public:
  SegmentTree(vector<int>& nums) {
    n = nums.size(); tree.resize(4 * n, 0); buildTree(nums, 0, n - 1, 0);
  }

  int query(int qleft, int qright) {
    return query(0, n - 1, 0, qleft, qright);
  }

  void update(int pos, int val) {
    update(0, n - 1, 0, pos, val);
  }
};
  

void solve() {
  int n, k; cin >> n >> k;
  int l = 0, r = 0;
  vector<int> nums(n); input(nums, n);
  SegmentTree st(nums);
  ordered_set<pair<int, int>> ost;

  rep(i, k-1) 
    { ost.insert({nums[i], i}); ++r; }

  while (r < n) {
    ost.insert({nums[r], r}); ++r;

    if (k & 1) {
      cout << (*ost.find_by_order(k / 2)).fs << " ";
    } else {
      cout << (*ost.find_by_order((k / 2) - 1)).fs << " ";
    }
    ost.erase(ost.find({nums[l], l}));
    ++l; 
  }

}

int main() {
  flash;
  solve();
  return 0;
}