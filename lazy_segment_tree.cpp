#include <bits/stdc++.h>
#define ll long long
using namespace std;

class SegmentTree {
  private:
    vector<ll> tree, lazy;
    int n;
    void apply_lazy(int node, int start, int end) {
      if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) 
          { lazy[node * 2] += lazy[node]; lazy[node * 2 + 1] += lazy[node]; }
        lazy[node] = 0;
      }
    }
    void update_range(int node, int start, int end, int l, int r, int value) {
      apply_lazy(node, start, end);
      if (start > end || start > r || end < l) return;
      
      if (start >= l && end <= r) {
        tree[node] += (end - start + 1) * value;
        if (start != end) 
          { lazy[node * 2] += value; lazy[node * 2 + 1] += value; }
        return;
      }
      int mid = (start + end) / 2;
      update_range(node * 2, start, mid, l, r, value);
      update_range(node * 2 + 1, mid + 1, end, l, r, value);
      tree[node] = tree[node * 2] + tree[node * 2 + 1];
    }
    int query(int node, int start, int end, int idx) {
      apply_lazy(node, start, end);
      if (start > end || idx < start || idx > end) return 0;
      if (start == end) return tree[node];
      int mid = (start + end) / 2;
      if (idx <= mid) return query(node * 2, start, mid, idx);
      return query(node * 2 + 1, mid + 1, end, idx);
    }
  public:
    SegmentTree(int size) {
      n = size; tree.resize(4 * n + 2, 0); lazy.resize(4 * n + 2, 0);
    }
    void update_range(int l, int r, int value) {
      update_range(1, 0, n - 1, l, r, value);
    }
    int query(int idx) {
      return query(1, 0, n - 1, idx);
    }
};