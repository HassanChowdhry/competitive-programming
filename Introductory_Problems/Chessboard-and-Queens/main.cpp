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
#define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i]
#define rem(mp, el) if(mp[el]==0)mp.erase(el)
#define ln "\n"

bool hor(vector<vector<char>>& board) {
  int r;
  rep(i, 8) {
    rep(j, 8) { if (board[j][i] == 'x') r = j; }
    for(int c = i+1; c < 8; ++c) {
      if (board[r][c] == 'x') return false;
    }
  }
  return true;
}
bool diag1(vector<vector<char>>& board) {
  int r;
  rep(i, 8) {
    rep(j, 8) { if (board[j][i] == 'x') r = j; }
    int rt = r + 1, rb = r - 1, c = i+1;
    while (rt < 8 && c < 8) {
      if (board[rt][c] == 'x') return false;
      ++rt; ++c;
    }
    c = i+1;
    while (rb >= 0 && c < 8) {
      if (board[rb][c] == 'x') return false;
      --rb; ++c;
    }
  }
  return true;
}

int rec1(int i, int r, vector<vector<char>>& board) {
  if (r >= 8) return 0;
  if (i == 8) {
    return (hor(board) && diag1(board) ? 1: 0);
  }

  int res = 0;
  if (board[r][i] != '*') {
    board[r][i] = 'x';
    res += rec1(i + 1, (r == 0 ? 1: 0), board);
    board[r][i] = '.';
  }
  res += rec1(i, r + 1, board);
  return res;
}

// bool hor(vector<vector<char>>& board) {
//   int r;
//   rep(i, 8) {
//     rep(j, 8) { if (board[j][i] == 'x') r = j; }
//     for(int c = i+1; c < 8; ++c) {
//       if (board[r][c] == '*') break;
//       if (board[r][c] == 'x') return false;
//     }
//   }
//   return true;
// }

// int rec2(int i, int c, vector<vector<char>>& board) {
//   if (c >= 8) return 0;
//   if (i == 8) return (vert(board) && diag2(board) ? 1: 0);

//   int res = 0;
//   if (board[i][c] != '*') {
//     board[i][c] = 'x';
//     res += rec1(i + 1, (c == 0 ? 1: 0), board);
//     board[i][c] = '.';
//   }
//   res += rec1(i, c + 1, board);
//   return res;
// }

void solve() {
  vector<vector<char>> board(8, vector<char>(8));

  rep(i, 8) {
    string in; cin >> in;
    rep(j, 8) board[i][j] = in[j];
  }

  cout << rec1(0, 0, board);
}

int main() {
  flash;
  solve();
  return 0;
}