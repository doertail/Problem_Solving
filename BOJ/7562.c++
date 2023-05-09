#include <bits/stdc++.h>

using namespace std;

int row, column;

int board[302][302];

int dx[8] = {2,  2, 1,  1, -1, -1, -2, -2};
int dy[8] = {1, -1, 2, -2,  2, -2,  1, -1};

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

        cin >> column;
        row = column;

        int x, y;
        cin >> x >> y;
        que.push({x, y});

        cin >> x >> y;
            
        board[x][y] = -1; // destination

        BFS();
    }

    return 0;   
}

void BFS() 
{
    while(!que.empty()) {
        pair<int, int> temp = que.front(); que.pop();

        int num = board[temp.first][temp.second];

        if(num == -1) {
            cout << 0 <<"\n";
            return;
        }

        for(int i = 0; i < 8; i++) {
            int x = temp.first + dx[i]; int y = temp.second + dy[i];
            if(x >= row || x < 0 || y >= column || y < 0) continue;
            
            if(board[x][y] == -1) {
                cout << x <<' '<< y <<' ' << ' '<< num <<"\n";
                cout << num+1 << "\n";
                return;
            }

            if(board[x][y] > 0) continue;

            

            que.push({x, y});
            board[x][y] = num + 1; // 시간 반영!
            // cout << x <<' '<< y <<' ' << ' '<< num <<"\n";
        }
    }
}

/*
300 
0 0 
299 299
*/