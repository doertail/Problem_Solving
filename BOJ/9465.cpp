// 9465: 스티커
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
int a[2][100001];
int d[2][100001];
int main(void){
    FAST_IO
    int TC; cin >> TC;
    while(TC--){
        int n; cin >> n;
        for(int i=0; i<2; i++)
            for(int j=0; j<n; j++)
                cin >> a[i][j];
        
        d[0][0] = a[0][0];
        d[1][0] = a[1][0]; 

        d[0][1] = a[0][1] + d[1][0];
        d[1][1] = a[1][1] + d[0][0];

        for(int i=2; i<n; i++){
            d[0][i] = max({d[0][i-2], d[1][i-2], d[1][i-1]}) + a[0][i];
            d[1][i] = max({d[0][i-2], d[1][i-2], d[0][i-1]}) + a[1][i];
        }

        cout << max({d[0][n-1], d[1][n-1], d[0][n-2], d[1][n-2]}) << '\n';
    }
    
    return 0;
}