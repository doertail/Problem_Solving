// 2240: 자두나무
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
using namespace std;

int a[1002];
int dd[1002][2][32]; // T초, 1또는 2, 몇 번 이동
int T, W;

int main(void){
    FAST_IO
    cin >> T;
    cin >> W;
    for(int i=1; i<=T; i++)
        cin >> a[i];
    for(int i=0; i<=T; i++)
        dd[i][1][0] = -2;
    
    for(int i=1; i<=T; i++){
        if(a[i] == 1){
            for(int j=0; j<=W; j++){
                if(j > i)
                    break;
                if(j == 0){
                    dd[i][0][j] = dd[i-1][0][j]+1;
                    // dd[i][1][j] = dd[i-1][1][j];
                    continue;
                }
                dd[i][0][j] = max(dd[i-1][0][j], dd[i-1][1][j-1])+1;
                dd[i][1][j] = max(dd[i-1][0][j-1], dd[i-1][1][j]);
            }
        }
        else{ // a[i] =2
            for(int j=0; j<=W; j++){
                if(j > i)
                    break;
                if(j == 0){
                    dd[i][0][j] = dd[i-1][0][j];
                    // dd[i][1][j] = dd[i-1][1][j]+1;
                    continue;
                }
                dd[i][0][j] = max(dd[i-1][0][j], dd[i-1][1][j-1]);
                dd[i][1][j] = max(dd[i-1][0][j-1], dd[i-1][1][j])+1;
            }
        }
    }

    cout << max(*max_element(dd[T][0], dd[T][0]+W+1), *max_element(dd[T][1], dd[T][1]+W+1));

    return 0;
}