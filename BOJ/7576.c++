#include <bits/stdc++.h>

using namespace std;

int row, column, day;

int board[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> que;

void BFS();
int check();

int main(void) 
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> column >> row;

    for(int i=1; i <= row; i++)
        for(int j=1; j <= column; j++)
            cin >> board[i][j];

    for(int i=1; i <= row; i++) {
        for(int j=1; j <= column; j++) {
            if(board[i][j] == 0 || board[i][j] == -1)   continue;
            que.push({i,j}); // 토마토 있음!
        }
    }   
    que.push({0, 0});

    BFS();

    cout << check() <<"\n";

    return 0;   
}

void BFS() 
{
    while(!que.empty()) {
        pair<int, int> temp = que.front(); que.pop();

        if(temp.first == 0 && temp.second == 0) {
            day++;
            if(que.empty()) return;
            que.push({0, 0});   continue;
        }

        for(int i = 0; i < 4; i++) {
            int x = temp.first + dx[i]; 
            int y = temp.second + dy[i];

            if(x > row || x < 1 || y > column || y < 1) continue;
            if(board[x][y] == 1 || board[x][y] == -1)   continue;

            que.push({x, y});
            board[x][y] = 1;
        }
    }   
}

int check() 
{
    for(int i=1; i <= row; i++) {
        for(int j=1; j <= column; j++) {
            if(board[i][j] == 0)    return -1;
        }
    }
    
    return (day-1);
}