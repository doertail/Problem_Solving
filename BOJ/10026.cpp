// 10026: 적록색맹
#include <bits/stdc++.h>

using namespace std;

int row, column;

int board[102][102];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> que;

void BFS1();
void BFS2();

int main(void) 
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> column;  row = column;

    char c;
    
    for(int i=1; i <= row; i++) {
        for(int j=1; j <= column; j++) {
            cin >> c;
            if(c == 'R') board[i][j] = 1;       // 4
            else if (c == 'G') board[i][j] = 2; // 4
            else if (c == 'B') board[i][j] = 3; // 5
        }
    }
    int ret = 0;

    // 처음
    for(int i=1; i <= row; i++) {
        for(int j=1; j <= column; j++) {
            if(board[i][j] > 3) continue;
            que.push({i,j}); 
            BFS1();
            ret++;
        }
    }   

    cout << ret << "\n";

    ret = 0;

    // 다음
    for(int i=1; i <= row; i++) {
        for(int j=1; j <= column; j++) {
            if(board[i][j] == 0) continue;
            que.push({i,j}); 
            BFS2();
            ret++;
        }
    }   

    cout << ret << "\n";
    
    return 0;   
}

void BFS1() 
{
    while(!que.empty()) {
        pair<int, int> temp = que.front(); que.pop();

        int color = board[temp.first][temp.second];

        if(color == 3) board[temp.first][temp.second] = 5;
        else if(color < 3) board[temp.first][temp.second] = 4;

        for(int i = 0; i < 4; i++) {
            int x = temp.first + dx[i]; 
            int y = temp.second + dy[i];

            if(x > row || x < 1 || y > column || y < 1) continue;

            if(board[x][y] > 3)   continue;

            if(board[x][y] != color)    continue;

            que.push({x, y});
        }
    }   
}

void BFS2() 
{
    while(!que.empty()) {
        pair<int, int> temp = que.front(); que.pop();

        int color = board[temp.first][temp.second];
        
        board[temp.first][temp.second] = 0;

        for(int i = 0; i < 4; i++) {
            int x = temp.first + dx[i]; 
            int y = temp.second + dy[i];

            if(x > row || x < 1 || y > column || y < 1) continue;

            if(board[x][y] == 0)   continue;

            if(board[x][y] != color)    continue;

            que.push({x, y});
        }
    }   
}