#include <bits/stdc++.h>
using namespace std;

void solve() {
    string sec, in; cin >> sec >> in;
    string out = "-----";
    vector<int> cnt(26, 0);
    
    for (int i = 0; i < 5; ++i) {
        if (sec[i] == in[i]) out[i] = 'G'; 
        else ++cnt[sec[i] - 'A'];
    }
    
    for (int i =0; i < 5; ++i) {
      if (sec[i] == in[i]) continue;
      char check = in[i] - 'A';
      if (cnt[check]) {
        --cnt[check];
        out[i]='Y';
      }
    }
    
    cout << out;
}

int main() {
    solve();
    return 0;
}