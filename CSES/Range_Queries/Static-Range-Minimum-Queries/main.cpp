#include <bits/stdc++.h>
using namespace std;

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
int MOD=1000000007;

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
      tree[index] = min(tree[2 * index + 1], tree[2 * index + 2]);
    }
  
    int query_sum(int left, int right, int index, int qleft, int qright) {
      if (qright < left || qleft > right) return MOD;
      if (qleft <= left && right <= qright) return tree[index];
      int mid = left + (right - left) / 2;
      return min(query_sum(left, mid, 2 * index + 1, qleft, qright), query_sum(mid + 1, right, 2 * index + 2, qleft, qright));
    }
  
    void update(int left, int right, int index, int pos, int val) {
      if (left == right) 
        { tree[index] = val; return; }
      int mid = left + (right - left) / 2;
      if (pos <= mid) update(left, mid, 2 * index + 1, pos, val);
      else update(mid + 1, right, 2 * index + 2, pos, val);
      tree[index] = min(tree[2 * index + 1], tree[2 * index + 2]);
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

void solve() {
  int n, k; cin >> n >> k;
  vector<int> arr(n, 0); input(arr, n);
  SegmentTree st = SegmentTree(arr);

  int l, r;
  rep(i, k) {
    cin >> l >> r;
    cout << st.query_sum(l-1, r-1) << ln;
  }

}

int main() {
  flash;
  solve();
  return 0;
}