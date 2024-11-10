#include <bits/stdc++.h>
# define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
# define loop(n) for(int i=0;i<n;++i)
# define nline "\n"
using namespace std;

// upper/lower bound binary search
int main() {
  flash
  int n, m, num; cin >> n >> m;
  int left, right, lower, higher;
	set<int> nums = {0, n};
  multiset<int> lengths = {n};

  loop(m) {
    cin >> num;
    auto it = nums.upper_bound(num);

    left = *prev(it);
		right = *it;

    lower = num - left;
    higher = right - num;

    lengths.erase(lengths.find(right - left));
    lengths.insert(lower);
    lengths.insert(higher);

    nums.insert(it, num);
    cout << *--lengths.end() << " ";
  } 
}

// 1 3 6 8
//3 2