#include <bits/stdc++.h>
using namespace std;

void LSH() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

string minNum(string hexa) {
    string ans = "";
    int n = hexa.size();
    for ( int i = 0 ; i < n ; ++i ) {
        if ( hexa[i] == 'D' ) {
            ans += '0';
        } else if ( hexa[i] == 'B' ) {
            ans += '8';
        } else {
            ans += hexa[i];
        }
    }
    if ( ans[0] == '0' && ans.size() > 1) {
        ans[0] = 'D';
    } 
    return ans;
}

string maxNum(string hexa) {
    string ans = "";
    int n = hexa.size();
    for ( int i = 0 ; i < n ; ++i ) {
        if ( hexa[i] == '0' ) {
            ans += 'D';
        } else if ( hexa[i] == '8' ) {
            ans += 'B';
        } else {
            ans += hexa[i];
        }
    }
    return ans;
}

long long mark[1005];
long long convertNum( string hexa ) {
    long long ans = 0;
    int n = hexa.size();
    for ( int i = 0 ; i < n ; ++i ) {
        ans += (1LL << (4*(n - i - 1))) * mark[hexa[i]];
    }
    return ans;
}
long long findLog(long long num ) {
    long long ans = 0;
    while ( (1LL << (4*(ans + 1))) <= num ) {
        ans++;
    }
    return ans;
}

char markHexa[20];
string convertHexa(long long num ) {
    string ans;
    long long pos = 0;
    char res[20];
    for ( int i = 0 ; i < 20 ; ++i ) {
        res[i] = '0';
    }
    while ( num > 0 ) {
        long long val = findLog(num);
        pos = max(pos,val);
        long long cur = num / (1LL << (4*val));
        res[val] = markHexa[cur];
        num -= cur * (1LL << (4*val));
    }
    for ( int i = pos ; i >= 0 ; --i ) {
        ans += res[i];
    }
    return ans;

}
long long n, sum = 0;
long long minAns = 0,maxAns = 0;
string s;
void solve() {
    cin >> n;
    for ( int i = '0' ; i <= '9' ; ++i ) {
        mark[i] = i - '0';
        markHexa[i - '0'] = i;
    }
    for ( int i = 'A' ; i <= 'F' ; ++i ) {
        mark[i] = i - 'A' + 10;
        markHexa[i - 'A' + 10] = i;
    }
    for ( int i = 1 ; i <= n ; ++i ) {
        cin >> s;
        minAns += convertNum(minNum(s));
        maxAns += convertNum(maxNum(s));
    }
    cout<<convertHexa(maxAns)<<'\n';
    cout<<convertHexa(minAns)<<'\n';
}

int main() {
    LSH();
    solve();
}