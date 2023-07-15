// 17070: 파이프 옮기기 1
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
#define SIZE 18
#define X first
#define Y second

using namespace std;
int board[SIZE][SIZE];
int Len, M;
int NUM;

void move(pair first, pair second, int status);
int main(void){
    FAST_IO
    
    cin >> Len;

    for(int i=1; i<=Len; i++)
        for(int j=1; j<=Len; j++)
            cin >> board[i][j];
    
    move({1,1}, {1,2}, 0);
    
    cout << NUM <<"\n";

    return 0;
}
void move(pair first, pair second, int status){
    if(second.X >Len || second.Y >Len)
        return;

    if(second.X == Len && second.Y == Len){
        NUM++;
        return;
    }

    if(status == 0){
        if(!board[second.X][second.Y+1])
            move(second, {second.X, second.Y+1}, 0);
        if(!board[second.X+1][second.Y+1] && !board[second.X][second.Y+1] && !board[second.X+1][second.Y])
            move(second, {second.X+1, second.Y+1}, 2);
    } 
    else if(status == 1){
        if(!board[second.X+1][second.Y])
            move(second, {second.X+1, second.Y}, 1);
        if(!board[second.X+1][second.Y+1] && !board[second.X][second.Y+1] && !board[second.X+1][second.Y])
            move(second, {second.X+1, second.Y+1}, 2);
    }
    else{ // status == 2
        if(!board[second.X][second.Y+1])
            move(second, {second.X, second.Y+1}, 0);
        if(!board[second.X+1][second.Y])
            move(second, {second.X+1, second.Y}, 1);
        if(!board[second.X+1][second.Y+1] && !board[second.X][second.Y+1] && !board[second.X+1][second.Y])
            move(second, {second.X+1, second.Y+1}, 2);
    }
}