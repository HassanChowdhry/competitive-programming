#include <bits/stdc++.h>
# define ll long long
# define pb push_back
# define all(a) a.begin(),a.end()
# define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
# define test int t;cin>>t;while(t--)
# define loop(n) for(int i=0;i<n;++i)
# define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i];
# define nline "\n"
using namespace std;
int MOD=1000000007;

int main() {
  flash

  int n, temp; cin >> n;
  bool flag = false;
  queue<int> q;
  loop(n)
    { q.push(i+1); }
  
  while (!q.empty()) {
    temp = q.front(); q.pop();
    if (flag) 
      { cout << temp << " "; }
    else 
      { q.push(temp); }

    flag = !flag;
  }
}