#include <bits/stdc++.h>
using namespace std;

string s;
long long n;
long long L[2000005], R[2000005];
stack<int> st;
void solve() {
  cin >> s;
  n = s.size();

  
  for (int i = 0; i < n; ++i) {
    L[i] = i + 1;
    R[i] = n - i;
  }

  for (int i = 0; i < n; ++i) {
    while (!st.empty() && s[st.top()] < s[i]) {
      int j = st.top();
      st.pop();
      R[j] = i - j;
    }

    st.push(i);
  }

  while (!st.empty()) st.pop();

  for (int i = n-1; i >= 0; --i) {
    while (!st.empty() && s[st.top()] <= s[i]) {
      int j = st.top();
      st.pop();
      L[j] = j - i;
    }

    st.push(i);
  }

  long long ans = 0;
  long long tot = n * (n + 1LL) / 2LL;
  for (int i = 0; i < n; ++i) {
    // cout << s[i] << " " << L[i] << " " << R[i] << "\n";
    // cout << (L[i] * R[i] * (s[i]-'0'))<<"\n";
    ans += (L[i] * R[i] * (s[i]-'0'));
  }
  long long gcd = __gcd(ans, tot);
  ans /= gcd; tot /= gcd;
  long long res = ans / tot;
  // cout << res << " " << gcd << " " << ans << " " << tot << "\n";
  if (tot == 1 || ans == 0) {
    cout << res << "\n";
  } else if (ans < tot) {
    cout << ans << "/" << tot << "\n";
  } else {
    cout << res << " " << (ans % tot) << "/" << tot << "\n";
  }
}

int main() {
  solve();
  return 0;
}
