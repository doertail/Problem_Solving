// 13717: A
#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll POW(ll a, ll b);
int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll A, B;
    cin >> A >> B;
    cout << POW(A%MOD, B) << "\n";

    return 0;
}

ll POW(ll a, ll b){
    if(b==1) return a%MOD;
    ll val = POW(a, b/2);
    val = val * val %MOD;
    if(b % 2 == 0) return val;
    return val * a % MOD;
}