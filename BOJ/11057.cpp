// 11057: 오르막수
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define MOD 10007
using namespace std;
int d[1001][10]; // 길이, 맨 앞수
int main(void){
    FAST_IO
    int n; cin >> n;
    for(int i=0; i<10; i++)
        d[1][i] = 1;
    for(int i=2; i<=n; i++){
        for(int j=0; j<10; j++){
            if(j==0){
                d[i][j] = d[i-1][j]%MOD; 
            }
            else
                d[i][j] = (d[i-1][j]%MOD+d[i][j-1]%MOD)%MOD;
        }
    }
    int sum=0;
    for(int i=0; i<10; i++)
        sum = (sum+d[n][i])%MOD;
    cout << sum;
    return 0;
}