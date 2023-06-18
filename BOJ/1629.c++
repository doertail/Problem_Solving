// 1629: 곱셈
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll POW(ll a, ll b, ll m);

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    long long A, B, C;
    cin >> A >> B >> C;
    cout << POW(A, B, C);

    return 0;
}

ll POW(ll a, ll b, ll m){
    if(b==1) return a%m;

    ll val = POW(a, b/2, m);

    val = val * val %m;

    if(b % 2 == 0) return val;
    
    return val * a % m;
}