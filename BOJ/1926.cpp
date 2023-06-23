#include <bits/stdc++.h>

using namespace std;

int row, column;

int board[501][501];
bool vis[501][501];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> que;

int max_n, temp_max;
int number_of_pictures;

void BFS(int x, int y);

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> row >> column;

    for(int i=1; i <= row; i++)
        for(int j=1; j <= column; j++)
            cin >> board[i][j];

    for(int i=1; i <= row; i++)
    {
        for(int j=1; j <= column; j++)
        {
            if(board[i][j] == 0 || vis[i][j]) 
                continue;
            BFS(i, j);
            number_of_pictures++;
            max_n = max(max_n, temp_max);
        }
    }   
    cout << number_of_pictures <<"\n"<< max_n<<"\n";

    return 0;   
}

void BFS(int x, int y)
{
    temp_max = 1;
    que.push({x, y});
    vis[x][y] = 1;

    while(!que.empty())
    {
        pair<int, int> temp = que.front(); que.pop();

        for(int i=0; i<4; i++)
        {
            int x = temp.first + dx[i]; 
            int y = temp.second + dy[i];

            if( x > row || x < 1 || y > column || y < 1)
                continue;
            if(board[x][y] == 0 || vis[x][y] == true)
                continue;
                
            que.push({x, y});
            vis[x][y] = 1;
            temp_max++;
        }
    }   
}