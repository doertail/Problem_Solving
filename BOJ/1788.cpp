// 1788: 피보나치 수의 확장
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define C 1000001
#define MOD 1000000000
using namespace std;
int d[2*C];
int main(void){
    FAST_IO
    d[0+C] = 0;
    d[1+C] = 1;
    d[-1+C] = 1;
    int N; cin >> N;
    if(N<0){
        for(int i=-1; i>= N; i--)
            d[i+C] = (d[i+2+C] - d[i+1+C])%MOD;
    }
    else if(N>0){
        for(int i=1; i<= N; i++)
            d[i+C] = (d[i-2+C] + d[i-1+C])%MOD;
    }

    if(d[N+C] > 0)
        cout << 1 << '\n';
    else if(d[N+C] == 0)
        cout << 0<<'\n';
    else
        cout << -1 <<'\n';
    cout << abs(d[N+C]);
    return 0;
}