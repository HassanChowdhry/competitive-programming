#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pb push_back
#define fs first 
#define sc second 
#define flash ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,n) for(int i=0;i<n;++i)
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define ln "\n"

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

  int sumRange(int left, int right, int index, int qleft, int qright) {
    if (qright < left || qleft > right) return 0;
    if (qleft <= left && right <= qright) return tree[index];
    int mid = left + (right - left) / 2;
    return sumRange(left, mid, 2 * index + 1, qleft, qright) +
      sumRange(mid + 1, right, 2 * index + 2, qleft, qright);
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
    return sumRange(0, n - 1, 0, qleft, qright);
  }

  void update(int pos, int val) {
    update(0, n - 1, 0, pos, val);
  }
};

void solve() {
  int n, q, start, end; cin >> n >> q;
  vector<int> nums(n, 0); input(nums, n);
  SegmentTree st(nums);
  rep (i, q) {
    cin >> start >> end;
    cout <<  st.query(start - 1, end - 1) << ln;
  }
}

signed main() {
  flash;
  solve();
  return 0;
}