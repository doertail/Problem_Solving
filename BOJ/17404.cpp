// 17404: RGB거리
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int d[1002][3];
int arr[1002][3];
int ANS[3];
int main(void){
    FAST_IO
    int N;
    cin >> N;
    for(int i=1; i<=N; i++)
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    d[1][0] = arr[1][0];
    d[1][1] = arr[1][1];
    d[1][2] = arr[1][2];

    d[2][0] = 100000;
    d[2][1] = arr[1][0] + arr[2][1];
    d[2][2] = arr[1][0] + arr[2][2];
    for(int i=3; i<=N; i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + arr[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + arr[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + arr[i][2];
    }
    ANS[0] = min(d[N][1], d[N][2]);

    d[2][0] = arr[1][1] + arr[2][0];
    d[2][1] = 100000;
    d[2][2] = arr[1][1] + arr[2][2]; 
    for(int i=3; i<=N; i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + arr[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + arr[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + arr[i][2];
    }
    ANS[1] = min(d[N][0], d[N][2]);

    d[2][0] = arr[1][2] + arr[2][0];
    d[2][1] = arr[1][2] + arr[2][1];
    d[2][2] = 100000;
    for(int i=3; i<=N; i++){
        d[i][0] = min(d[i-1][1], d[i-1][2]) + arr[i][0];
        d[i][1] = min(d[i-1][0], d[i-1][2]) + arr[i][1];
        d[i][2] = min(d[i-1][0], d[i-1][1]) + arr[i][2];
    }
    ANS[2] = min(d[N][0], d[N][1]);

    cout << min({ANS[0], ANS[1], ANS[2]});

    return 0;
}
