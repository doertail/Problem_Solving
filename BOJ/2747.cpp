// 2747: 피보나치 수
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define MOD 1000000
using namespace std;

ll d[10000];
int main(void){
    FAST_IO
    int n; cin >> n;
    d[0] = 0;
    d[1] = 1;
    for(int i=2; i<=10000; i++)
        d[i] = (d[i-1] + d[i-2]);
    cout << d[n];
    
    return 0;
}