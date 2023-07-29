// 28017: 게임을 클리어하자
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;


int board[502][502];
int d[502][502];

int main(void){
    FAST_IO
    int N, M;
    cin >> N >> M;
    for(int i=1; i<=N; i++)
        for(int j=1; j<=M; j++)
            cin >> board[i][j];
    
    for(int j=1; j<=M; j++)
        d[1][j] = board[1][j];
    

    for(int i=2; i<= N; i++){
        for(int j=1; j<=M; j++){
            int min1 = 1000001101; 
            for(int k=1; k<=M; k++){
                if(k == j)
                    continue;
                if(d[i-1][k] < min1)
                    min1 = d[i-1][k]; 
            }
            d[i][j] = min1 + board[i][j];
        }
    }
    cout << *min_element(d[N]+1, d[N]+M+1);
    return 0;
}