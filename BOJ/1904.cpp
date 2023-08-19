// 1904 : 01타일
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define MOD 15746
using namespace std;
int d[1000001];
int main(void){
    FAST_IO
    int N; cin >> N;
    d[1] = 1; // 1
    d[2] = 2; // 00 11
    d[3] = 3; // 111 100 001
    d[4] = 5; // 1111 1100 1001 0011 0000
    d[5] = 8; // 11111 11100 11001 10011 00111 10000 00001
    for(int i=5; i<=N; i++)
        d[i] = (d[i-2] + d[i-1])%MOD;
    cout << d[N];
    return 0;
}