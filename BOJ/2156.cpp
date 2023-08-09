// 2156: 포도주 시식
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
int d[10002][3]; // n번째, k번 연속으로 마셨을 때,
int main(void){
    FAST_IO
    int a[100002];
    int n; cin >> n;
    for(int i=1; i<=n; i++)
        cin >> a[i];
    
    d[1][1] = a[1];
    d[1][2] = 0;
    d[2][1] = a[2];
    d[2][2] = a[1] + a[2];
    d[3][1] = a[1] + a[3];
    d[3][2] = a[3] + d[2][1];

    for(int i=4; i<=n; i++){
        d[i][1] = a[i] + max({d[i-3][2], d[i-2][1], d[i-2][2], d[i][1]});
        d[i][2] = a[i] + d[i-1][1];
    }
    // for(int i=1; i<=n ;i++)
        // cout << i << ": " << a[i]<<"|| 1: " << d[i][1] << "| 2: " << d[i][2] <<'\n';

    cout << max({d[n-1][1], d[n-1][2], d[n][1], d[n][2]});

    return 0;
}