// 9461: 파도반 수열
#include <bits/stdc++.h>
#define ll long long
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int main(void){
    FAST_IO
    ll T; cin >> T;
    ll d[101];
    d[1] = 1;
    d[2] = 1;
    d[3] = 1;
    d[4] = 2;
    d[5] = 2;
    d[6] = 3;

    for(int i=6; i<=100; i++)
        d[i] = d[i-1] + d[i-5];

    while(T--){
        int N;
        cin >> N;
        cout << d[N] <<'\n';
    }
    
    return 0;
}