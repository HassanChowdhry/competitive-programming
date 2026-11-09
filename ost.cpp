#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
ordered_set<int> s;
// s.order_of_key(x);        Count elements < x
// *s.find_by_order(k);      kth smallest (0-indexed, k < size)
ordered_set<pair<int,int>> ms;
// ms.order_of_key({x, -1});       Count < x
// ms.order_of_key({x, INT_MAX});  Count <= x
// ms.find_by_order(k)->first;    kth smallest value