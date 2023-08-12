// 11502: 카드 구매하기 
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
int a[10005];
int d[10005];
int main(void){
    FAST_IO
    int N; cin >> N;
    for(int i=1; i<=N; i++)
        cin >> a[i];
    for(int i=1; i<=N; i++)
        d[i] = a[i];
    for(int i=2; i<=N; i++)
        for(int j=1; j<=i; j++)
            d[i] = max(d[i], d[i-j]+a[j]);
    
    cout << d[N];
    return 0;
}