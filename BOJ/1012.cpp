// 1012: 유기농 배추
#include <bits/stdc++.h>

using namespace std;

int row, column;

int board[52][52];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> que;

void BFS();

int main(void) 
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int TestCase;   
    cin >> TestCase;

    while(TestCase--)
    {
        while(!que.empty()) que.pop(); // 큐 초기화
        memset(board, 0, sizeof(board)); // board 초기화
        int num_of_cabbage;

        cin >> column >> row;
        cin >> num_of_cabbage;

        int x, y;

        while (num_of_cabbage--)
        {    
            cin >> x >> y;
            board[y][x]=1;
        }

        int ret = 0;
        for(int i=0; i < row; i++) {
            for(int j=0; j < column; j++) {
                if(board[i][j] != 1)   continue;
                
                que.push({i,j}); 
                BFS();
                ret++;
            }
        }   

        cout << ret << "\n";
    }

    return 0;   
}

void BFS() 
{
    while(!que.empty()) {
        pair<int, int> temp = que.front(); que.pop();

        for(int i = 0; i < 4; i++) {
            int x = temp.first + dx[i]; int y = temp.second + dy[i];
            if(x < 0 || x >= row || y < 0 || y >= column) continue;
            
            if(board[x][y] != 1) continue;

            que.push({x, y}); 

            board[x][y] = 2;
        }
    }
}   