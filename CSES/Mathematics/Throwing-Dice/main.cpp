#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int oo = 1e9 + 7;

ll X[6][6] = {
	{0, 1, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1}
};

ll Y[6][6] = {
	{1, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0},
	{0, 0, 0, 1, 0, 0},
	{0, 0, 0, 0, 1, 0},
	{0, 0, 0, 0, 0, 1}
};

long long n;

void matmul(ll A[6][6], ll B[6][6]){
    ll C[6][6];

	for(int i = 0; i < 6; i++)
		for(int j = 0; j < 6; j++)
			C[i][j] = 0;
	
    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 6; j++){
            for(int k = 0; k < 6; k++){
                C[i][j] += A[i][k] * B[k][j];
                C[i][j] %= oo;
            }
        }
    }

    for(int i = 0; i < 6; i++)
        for(int j = 0; j < 6; j++)
            A[i][j] = C[i][j];
}

void solve() {
	// f(n) = f(n - 1) + f(n - 2) + f(n - 3) + f(n - 4) + f(n - 5) + f(n - 6)
	// k = 6, c1=c2=c3=c4=c5=c6 = 1;
	cin >> n;

	while (n) {
		if (n & 1) {
			matmul(Y, X);
		}
		matmul(X, X);
		n >>= 1;
	}

	// for (int i = 0; i < 6; ++i) {
	// 	// for (int j = 0; j < 6; ++j) {
	// 		cout << Y[i][i] << "\t";
	// 	// } 
	// 	cout << "\n";
	// }


	cout << Y[5][5];
}

int main() {
  cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);
//   int t; cin >> t;
//   while(t--)
  solve();
  return 0;
}