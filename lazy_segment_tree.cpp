#include <bits/stdc++.h>
using namespace std;

class SegmentTree {
  private:
    vector<long long> tree, lazy;
    int n;
    void apply_lazy(int node, int start, int end) {
      if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) 
          { lazy[node * 2 + 1] += lazy[node]; lazy[node * 2 + 2] += lazy[node]; }
        lazy[node] = 0;
      }
    }
    void update_range(int node, int start, int end, int l, int r, int value) {
      apply_lazy(node, start, end);
      if (start > end || start > r || end < l) return;
      
      if (start >= l && end <= r) {
        tree[node] += (end - start + 1) * value;
        if (start != end) 
          { lazy[node * 2 + 1] += value; lazy[node * 2 + 2] += value; }
        return;
      }
      int mid = (start + end) / 2;
      update_range(node * 2 + 1, start, mid, l, r, value);
      update_range(node * 2 + 2, mid + 1, end, l, r, value);
      tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
    }
    int query(int node, int start, int end, int idx) {
      apply_lazy(node, start, end);
      if (start > end || idx < start || idx > end) return 0;
      if (start == end) return tree[node];
      int mid = (start + end) / 2;
      if (idx <= mid) return query(node * 2 + 1, start, mid, idx);
      return query(node * 2 + 2, mid + 1, end, idx);
    }
  public:
    SegmentTree(int size) {
      n = size; tree.resize(4 * n, 0); lazy.resize(4 * n, 0);
    }
    void update_range(int l, int r, int value) {
      update_range(0, 0, n - 1, l, r, value);
    }
    int query(int idx) {
      return query(0, 0, n - 1, idx);
    }
};