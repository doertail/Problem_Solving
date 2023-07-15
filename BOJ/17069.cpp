// 17069: 파이프 옮기기 2
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
#define ll long long
#define SIZE 34
#define X first
#define Y second

using namespace std;
ll board[SIZE][SIZE];
ll DP[SIZE][SIZE][3];
int Len, M;
ll ANS;

ll move(pair first, pair second, int status);
int main(void){
    FAST_IO
    
    cin >> Len;

    for(int i=1; i<=Len; i++)
        for(int j=1; j<=Len; j++)
            cin >> board[i][j];
    
    move({1,1}, {1,2}, 0);
    
    cout << ANS << "\n";

    return 0;
}
ll move(pair first, pair second, int status){
    if(second.X >Len || second.Y >Len)
        return 0;

    if(DP[second.X][second.Y][status]){
        ANS += DP[second.X][second.Y][status];
        return DP[second.X][second.Y][status];
    }

    if(second.X == Len && second.Y == Len){
        ANS++;
        return 1;
    }

    if(status == 0){
        if(!board[second.X][second.Y+1])
            DP[second.X][second.Y][0] += move(second, {second.X, second.Y+1}, 0);
        if(!board[second.X+1][second.Y+1] && !board[second.X][second.Y+1] && !board[second.X+1][second.Y])
            DP[second.X][second.Y][0] += move(second, {second.X+1, second.Y+1}, 2);
    } 
    else if(status == 1){
        if(!board[second.X+1][second.Y])
            DP[second.X][second.Y][1] += move(second, {second.X+1, second.Y}, 1);
        if(!board[second.X+1][second.Y+1] && !board[second.X][second.Y+1] && !board[second.X+1][second.Y])
            DP[second.X][second.Y][1] += move(second, {second.X+1, second.Y+1}, 2);
    }
    else{ // status == 2
        if(!board[second.X][second.Y+1])
            DP[second.X][second.Y][2] += move(second, {second.X, second.Y+1}, 0);
        if(!board[second.X+1][second.Y])
            DP[second.X][second.Y][2] += move(second, {second.X+1, second.Y}, 1);
        if(!board[second.X+1][second.Y+1] && !board[second.X][second.Y+1] && !board[second.X+1][second.Y])
            DP[second.X][second.Y][2] += move(second, {second.X+1, second.Y+1}, 2);
    }
    return DP[second.X][second.Y][status];
}