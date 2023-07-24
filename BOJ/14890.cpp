// 14890: 경사로
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
int board[101][101];
int N, L;

int solve(int sx, int sy, int fx, int fy);
int main(void){
    FAST_IO
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            board[i][j] = -1;

    int sum=0;
    cin >> N >> L;
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> board[i][j];

    for(int i=0; i<N; i++)
        sum += solve(i, 0, i, N-1);
    
    for(int j=0; j<N; j++)
        sum += solve(0, j, N-1, j);
    
    cout << sum << '\n';

    return 0;
}

int solve(int sx, int sy, int fx, int fy){
    int temp = board[sx][sy];
    int cnt=0;
    bool flag = true;
    for(int i=sx; i<=fx; i++){
        for(int j=sy; j<=fy; j++){
            if(board[i][j] == -1)   
                continue;
            if(!flag && cnt >= L){
                flag = true;
                cnt -= L;
            }
            if(temp == board[i][j]){
                cnt++;
                continue;
            }
            if(abs(temp - board[i][j]) > 1)
                return 0;

            if(!flag)
                return 0;

            if(temp > board[i][j]){
                cnt = 1;
                flag = false;
            }

            else{
                if(cnt < L)
                    return 0;
                else
                    cnt = 1;
            }
            temp = board[i][j];
        }
    }

    if(!flag && cnt >= L)
        flag = true;
    
    if(flag)
        return 1;
    
    else
        return 0;
}