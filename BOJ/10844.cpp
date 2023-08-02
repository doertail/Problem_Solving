// 10844: 쉬운 계단수
#include <bits/stdc++.h>
#define MOD 1000000000
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int d[101][10]; // 정상, 위험 요소, 위험
int rd[101]; // real d
int main(void){
    FAST_IO
    int N; cin >> N;
    for(int i=1; i<10; i++)
        d[1][i] = 1;
    rd[1] = 9;

    for(int i=2; i<=100; i++){
        int cnt =0;
        
        d[i][0] = d[i-1][1]%MOD;
        cnt = cnt%MOD+d[i][0];
        for(int j=1; j<9; j++){
            d[i][j] = d[i-1][j-1] % MOD + d[i-1][j+1] % MOD;
            cnt = (cnt%MOD + d[i][j]%MOD)%MOD;
        }
        d[i][9] = d[i-1][8]%MOD;
        cnt = (cnt%MOD + d[i][9]%MOD)%MOD;

        rd[i] = cnt;
    }
    cout << rd[N]%MOD;
    return 0;
}