#include <bits/stdc++.h>
using namespace std;

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

  int query_sum(int left, int right, int index, int qleft, int qright) {
    if (qright < left || qleft > right) return 0;
    if (qleft <= left && right <= qright) return tree[index];
    int mid = left + (right - left) / 2;
    return query_sum(left, mid, 2 * index + 1, qleft, qright) +
      query_sum(mid + 1, right, 2 * index + 2, qleft, qright);
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

  int query_sum(int qleft, int qright) {
    return query_sum(0, n - 1, 0, qleft, qright);
  }

  void update(int pos, int val) {
    update(0, n - 1, 0, pos, val);
  }
};