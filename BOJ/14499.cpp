// 14499: 주사위 굴리기
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
using namespace std;

int board[20][20];
int dice[4][3]; // (0,1) (1,0) (1,1) (1,2) (2,1) (3,1)만 사용!
int dx[5] = {0,0, 0, -1, 1};
int dy[5] = {0,1, -1, 0, 0};

pair tempLocation;
int N, M;

void moveDice(int n);
int main(void){
    FAST_IO
    int x, y, numberOfMove;
    cin >> N >> M >> x >> y >> numberOfMove;
    tempLocation.first = x;
    tempLocation.second = y;

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> board[i][j];

    // move
    for(int i=0; i<numberOfMove; i++){
        int direction;
        cin >> direction;
        moveDice(direction);
    }
    
    return 0;
}

void moveDice(int n){
    int x = tempLocation.first; int y = tempLocation.second;

    int nx = x + dx[n]; int ny = y + dy[n];
    if(nx < 0 || nx >= N || ny < 0 || ny >= M)
        return;

    tempLocation.first = nx;
    tempLocation.second = ny;

    int temp = dice[1][1]; 

    if(n==1){
        dice[1][1] = dice[1][0];
        dice[1][0] = dice[3][1];
        dice[3][1] = dice[1][2];
        dice[1][2] = temp;
    }
    else if(n==2){
        dice[1][1] = dice[1][2];
        dice[1][2] = dice[3][1];
        dice[3][1] = dice[1][0];
        dice[1][0] = temp;
    }
    else if(n==3){
        dice[1][1] = dice[0][1];
        dice[0][1] = dice[3][1];
        dice[3][1] = dice[2][1];
        dice[2][1] = temp;
    }
    else if(n==4){
        dice[1][1] = dice[2][1];
        dice[2][1] = dice[3][1];
        dice[3][1] = dice[0][1];
        dice[0][1] = temp;
    }

    if(board[nx][ny]==0)
        board[nx][ny] = dice[3][1];
    else{
        dice[3][1] = board[nx][ny];
        board[nx][ny] = 0;
    }
    cout << dice[1][1] <<'\n';
}