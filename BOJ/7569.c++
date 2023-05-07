#include <bits/stdc++.h>

using namespace std;

int row, column, height, day;

int board[101][101][101];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

queue<tuple<int, int, int>> que;

void BFS();
int check();

int main(void) 
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> column >> row >> height;

    for(int k=1; k <= height; k++) 
        for(int i=1; i <= row; i++) 
                for(int j=1; j <= column; j++) 
                    cin >> board[k][i][j];

    for(int k=1; k<= height; k++) {
        for(int i=1; i <= row; i++) {
                for(int j=1; j <= column; j++) {
                    if(board[k][i][j] == 0 || board[k][i][j] == -1)   continue;
                    que.push({k, i, j}); // 토마토 있음! // 1임!
                }
        }
    }   
    que.push({0, 0, 0});

    BFS();

    cout << check() <<"\n";

    return 0;   
}

void BFS() 
{
    while(!que.empty()) {
        tuple<int, int, int> temp = que.front(); que.pop();

        if(get<0>(temp) == 0 && get<1>(temp) == 0 && get<2>(temp) == 0) {
            day++;
            if(que.empty()) return;
            que.push({0, 0, 0});   continue;
        }

        for(int i = 0; i < 6; i++) {
            int z = get<0>(temp) + dz[i]; 
            int x = get<1>(temp) + dx[i];
            int y = get<2>(temp) + dy[i];

            if(x > row || x < 1 || y > column || y < 1 || z > height || z < 1) continue;
            if(board[z][x][y] == 1 || board[z][x][y] == -1)   continue;

            que.push({z, x, y});
            board[z][x][y] = 1;
        }
    }   
}

int check() 
{
    for(int k=1; k<= height; k++) {
        for(int i=1; i <= row; i++) {
                for(int j=1; j <= column; j++) {
                    if(board[k][i][j] == 0)    return -1;
            }
        }
    }
    
    return (day-1);
}