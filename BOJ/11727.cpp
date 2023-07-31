// 11727: 2xn 타일링 2
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
using namespace std;

#define DEBUG
#ifdef ONLINE_JUDGE
#endif

ll d[1002]; //
int main(void){
    FAST_IO
    d[1] = 1;
    d[2] = 3;
    for(int i=3; i<=1000; i++)
        d[i] = (d[i-1] + 2*d[i-2]) % 10007;

    int n;
    cin >> n;

    cout << d[n] <<'\n';

    return 0;
}
