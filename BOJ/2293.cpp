// 2293 : 동전 1
#include <bits/stdc++.h>
#define ll long long
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
ll dp[100001];
int a[101];
int main(void){
    FAST_IO
    int N, K; cin >> N >> K;    
    for(int i=0; i<N; i++)
        cin >> a[i];
    
    
    dp[0] = 1;
    for(int i=0; i<N; i++)
        for(int j=a[i]; j<=K; j++)
            dp[j] += dp[j-a[i]];
    
    cout << dp[K];
    
    return 0;
}
/*
1 1
2 2 (11,2)
3 2 (111, 21)
4 3 (1111, 211, 22)
*/