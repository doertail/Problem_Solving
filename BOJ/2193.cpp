// 2193: 이친수
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<ll, ll>
using namespace std;
pair d[91];

int main(void){
    FAST_IO
    int n; cin >> n;
    d[1] = {1,0};
    d[2] = {1,0};
    d[3] = {1,1};
    d[4] = {2,1};
    d[5] = {3,2};
    d[6] = {5,3};
    
    for(int i=7; i<91; i++)
        d[i] = {d[i-1].first+d[i-1].second, d[i-1].first};

    cout << d[n].first + d[n].second << '\n';

    return 0;
}