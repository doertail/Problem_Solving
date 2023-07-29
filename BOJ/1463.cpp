// 1463: 1로 만들기
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);

int d[10000005];
int N;

int main(void){
    FAST_IO
    cin >> N;
    d[1] = 0;
    for(int i=2; i<=N; i++){
        d[i] = d[i-1]+1;
        if(i%2==0) d[i] = min(d[i], d[i/2]+1);
        if(i%3==0) d[i] = min(d[i], d[i/3]+1);
    }

    cout << d[N];

    return 0;
}
