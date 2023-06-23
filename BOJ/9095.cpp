// 9095: 1, 2, 3 더하기
#include <bits/stdc++.h>

#define condition ios_base::sync_with_stdio(0); cin.tie(NULL);

using namespace std;
int dp[12] = {0, 1, 2, 4};

int main(void){
    condition
    int N;
    cin >> N;

    for(int n=4; n<12; n++){
        dp[n] = dp[n-1] + dp[n-2] + dp[n-3];
    }
    // cout << dp[4];

    while(N--){
        int n;
        cin >> n;
        cout << dp[n] <<"\n";
    }


    return 0;
}