#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5 + 1;
int n, h[maxN], R[maxN], L[maxN];
long long ans;

void solve() {
  cin >> n;
  ans = 0;

  fill(R+1, R+n+1, n);
  fill(L+1, L+n+1, 1);

  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
  }

  stack<int> st;
  for (int i = 1; i <= n; ++i) {
    while (!st.empty() && h[st.top()] > h[i]) {
      int j = st.top(); R[j] = i - 1;
      st.pop();
    }
    
    st.push(i);
  }

  st = {};
  for (int i = n; i >= 1; --i) {
    while (!st.empty() && h[st.top()] > h[i]) {
      int j = st.top(); L[j] = i + 1;
      st.pop();
    }
    
    st.push(i);
  }

  for (int i = 1; i <= n; ++i) {
    long long curr = (R[i] - L[i] + 1) * 1LL * (h[i] * 1LL);
    ans = max(ans, curr);
  }

  cout << ans;
}


int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
  solve();
  return 0;
}