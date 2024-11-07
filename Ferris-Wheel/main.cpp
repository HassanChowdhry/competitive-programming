#include <bits/stdc++.h>
# define ll long long
# define pb push_back
# define all(a) a.begin(),a.end()
# define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
# define test int t;cin>>t;while(t--)
# define loop(n) for(int i=0;i<n;i++)
# define input(arr,n);for(int i=0;i<n;i++)cin>>arr[i];
# define nline "\n"
using namespace std;
int MOD=1000000007;
using namespace std;

int binary_search(int l, int r, int target, vector<ll>& children_weight, unordered_set<ll>& visit) {
  int start = l, res = -1;
  while (l <= r) {
    int mid = (int) ((l + r + 1) / 2);
    if (start == mid) { break; }

    if (!visit.count(mid) && children_weight[start] + children_weight[mid] == target) 
      { return mid; } 
    else if (!visit.count(mid) && children_weight[start] + children_weight[mid] < target) 
      { res = mid; l = mid + 1; }
    else 
      { r = mid - 1; }
  }

  return res;
}

int main() {
  int n, w, res = 0; cin >> n >> w;
  vector<ll> children_weight(n); loop(n) { cin >> children_weight[i]; } 
  unordered_set<ll> visit;
  sort(children_weight.begin(), children_weight.end());

  loop(n) {
    if (visit.count(i)) { continue; } 
    visit.insert(i); ++res;

    int r = binary_search(i, n-1, w, children_weight, visit);
    if (r != -1) { visit.insert(r); }
  }

  cout << res;
}