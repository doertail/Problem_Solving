// 11660: 구간 합 구하기 5
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define MAX 1026
using namespace std;

int a[MAX][MAX];
int d[MAX][MAX];
int main(void){
    FAST_IO
    int N, M;
    cin >> N >> M;

    for(int i=1; i<N+1; i++)
        for(int j=1; j<N+1; j++)
            cin >> a[i][j];

    d[1][1] = a[1][1];
    for(int i=1; i<N+1; i++){
        for(int j=1; j<N+1; j++){
            if(j == 1){
                d[i][j] = a[i][j];
                continue;
            }
            d[i][j] = d[i][j-1] + a[i][j];
        }
    }

    while(M--){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int sum=0;
        for(int i=x1; i<=x2; i++)
            sum += d[i][y2] - d[i][y1-1];
        cout << sum << '\n';
    }

    return 0;
}
