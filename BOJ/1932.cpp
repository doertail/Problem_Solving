// 1932: 정수 삼각형
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int arr[1000][1000];

int main(void){
    FAST_IO
    int H;
    cin >> H;
    int garo = (H-1) * 2;
    int ref = garo/2;

    for(int i=0; i<H; i++){
        for(int j=ref, n=0; n <= i; j = j+2, n++ )
            cin >> arr[i][j];
        ref--;
    }
    
    ref=0;
    for(int i=H-1; i>0; i--){
        for(int j=ref, n=0; n <i; j = j+2, n++)
            arr[i-1][j+1] += max(arr[i][j], arr[i][j+2]);
        
        ref++;
    }
    cout << arr[0][garo/2] << "\n";
    
    return 0;
}