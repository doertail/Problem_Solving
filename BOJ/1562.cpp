// 1562:  계단수
#include <bits/stdc++.h>
#define MOD 1000000000
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int d[101][10][1<<10]; // i길이, j로 끝나는, 비트 정보
int main(void){
    FAST_IO
    int N; cin >> N;
    for(int i=1; i<10; i++)
        d[1][i][1<<i] = 1;
    for(int i=2; i<=100; i++){
        for(int j=0; j<10; j++){
            for(int k=0; k<1024; k++){
                if(j==0)
                    d[i][j][k|(1<<j)] = (d[i][j][k|(1<<j)]+ d[i-1][j+1][k])%MOD;
                else if(j==9)
                    d[i][j][k|(1<<j)] = (d[i][j][k|(1<<j)]+ d[i-1][j-1][k])%MOD;
                else{
                    d[i][j][k|(1<<j)] = (d[i][j][k|(1<<j)]+ d[i-1][j-1][k])%MOD;
                    d[i][j][k|(1<<j)] = (d[i][j][k|(1<<j)]+ d[i-1][j+1][k])%MOD;
                }
            }
        }
    } 
    int sum = 0;
    for(int j=0; j<10; j++)
        sum = (sum%MOD + d[N][j][1023]%MOD)%MOD;
    
    cout << sum;

    return 0;
}