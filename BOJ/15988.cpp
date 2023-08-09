// 15988: 1, 2, 3 더하기 3
#include <bits/stdc++.h>
#define MAX 1000000
#define MOD 1000000009
#define condition ios_base::sync_with_stdio(0); cin.tie(NULL);

using namespace std;
int dp[MAX+2] = {0, 1, 2, 4};

int main(void){
    condition
    int N;
    cin >> N;

    for(int n=4; n<=MAX; n++)
        dp[n] = ((dp[n-1]%MOD + dp[n-2]%MOD)%MOD + dp[n-3]%MOD)%MOD;
    

    while(N--){
        int n;
        cin >> n;
        cout << dp[n] <<"\n";
    }


    return 0;
}