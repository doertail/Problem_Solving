// 2468: 안전 영역
#include <bits/stdc++.h>

using namespace std;

int row, column;

int board[101][101];
bool vis[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> que;

int safety_zones;

void BFS(int x, int y, int max);

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> row;
    column = row;
    int _max = 0;

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            cin >> board[i][j];
            _max = max(_max, board[i][j]);
        }
    }

    int temp_max = -1;

    for(int n = 0; n <= _max; n++ ) { 
        memset(vis, false, sizeof(vis));

        for(int i=0; i < row; i++) {
            for(int j=0; j < column; j++) {
                if(board[i][j] <= n || vis[i][j] == true) 
                    continue;
                BFS(i, j, n);
                safety_zones++;
            }
        }
        temp_max = max(temp_max, safety_zones);
        safety_zones = 0;
    }
    cout << temp_max << "\n";

    return 0;   
}

void BFS(int x, int y, int max)
{
    que.push({x, y});
    vis[x][y] = true;

    while(!que.empty()) {
        pair<int, int> temp = que.front(); que.pop();

        for(int i = 0; i < 4; i++)
        {
            int x = temp.first  + dx[i]; 
            int y = temp.second + dy[i];

            if( x >= row || x < 0 || y >= column || y < 0)
                continue;

            if(board[x][y] <= max || vis[x][y] == true)
                continue;
                
            que.push({x, y});
            vis[x][y] = true;
        }
    }   
}