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
		vector<ll> tree;
		int n;
	
		void buildTree(vector<ll>& nums, int left, int right, int index) {
			if (left == right) 
				{ tree[index] = nums[left]; return; }
			int mid = left + (right - left) / 2;
			buildTree(nums, left, mid, 2 * index + 1);
			buildTree(nums, mid + 1, right, 2 * index + 2);
			tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
		}
	
		ll query_sum(int left, int right, int index, int qleft, int qright) {
			if (qright < left || qleft > right) return 0;
			if (qleft <= left && right <= qright) return tree[index];
			int mid = left + (right - left) / 2;
			return query_sum(left, mid, 2 * index + 1, qleft, qright) +
				query_sum(mid + 1, right, 2 * index + 2, qleft, qright);
		}
	
		void update(int left, int right, int index, int pos, ll val) {
			if (left == right) 
				{ tree[index] = val; return; }
			int mid = left + (right - left) / 2;
			if (pos <= mid) update(left, mid, 2 * index + 1, pos, val);
			else update(mid + 1, right, 2 * index + 2, pos, val);
			tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
		}
	
	public:
		SegmentTree(vector<ll>& nums) {
			n = nums.size(); tree.resize(4 * n, 0); buildTree(nums, 0, n - 1, 0);
		}
	
		ll query_sum(int qleft, int qright) {
			return query_sum(0, n - 1, 0, qleft, qright);
		}
	
		void update(int pos, ll val) {
			update(0, n - 1, 0, pos, val);
		}
	};

void solve() {
  ll n, m, num; cin >> n >> m;
  vector<ll> arr(n); input(arr, n);
	SegmentTree st = SegmentTree(arr);
  ll t, a, b;
  rep(i, m) {
    cin >> t >> a >> b;
    if (t == 1) {
      st.update(a-1, b);
    } else {
      cout << st.query_sum(a-1, b-1) << ln;
    }
  }
}

int main() {
  flash;
  solve();
  return 0;
}