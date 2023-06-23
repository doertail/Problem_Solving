#include <bits/stdc++.h>

using namespace std;

int row, column;

int board[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<pair<int, int>> que;

void BFS();

int main(void) 
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> row >> column;
    char c;
    
    vector<pair<int, int>> fire;

    for(int i=1; i <= row; i++) {
        for(int j=1; j <= column; j++) {
            cin >> c;
            if(c == '#')
                board[i][j] = -2; // 벽
            else if(c == 'J')
                board[i][j] = 1; // 지훈
            else if(c == 'F')
            {
                board[i][j] = -1;   // 불(움직임 o
                fire.push_back({i, j});
            }
            // .은 그냥 0으로 ..
        }
    }
    

    for(int i=1; i <= row; i++) {
        for(int j=1; j <= column; j++) {
            if(board[i][j] != 1)   continue;
            que.push({i,j}); 
        }
    }   
    for(auto c: fire)
        que.push(c);

    BFS();

    return 0;   
}
void BFS() 
{
    while(!que.empty()) {
        pair<int, int> temp = que.front(); que.pop();
        int num = board[temp.first][temp.second]; // 불인지 지훈이인지 구분!

        if(num > 0) { // 짛운
            for(int i = 0; i < 4; i++) {
            int x = temp.first + dx[i]; int y = temp.second + dy[i];

            if(board[x][y] != 0) continue; // 벽이나 불이나 과거의 자신을 만난 지훈이 ..

            if(x > row || x < 1 || y > column || y < 1) { // 탈출 가능한 지훈이
                cout << num << "\n";
                return;
            }

            que.push({x, y}); // 길을 만난 짛운

            board[x][y] = num + 1; // 시간 반영!
            }
        }

        else {// num <0 불
            board[temp.first][temp.second] = -2; // 지나간 불은 벽으로 처리
            for(int i = 0; i < 4; i++) {
            int x = temp.first + dx[i]; int y = temp.second + dy[i];

            if(x > row || x < 1 || y > column || y < 1) continue; // 불은 밖으로 안 나감
            if(board[x][y] == -2 || board[x][y] == -1) continue; // 벽을 만난 나..
            if(board[x][y] > 0) {//불인데 지훈이 만남 ..            
                board[x][y] = -2;
                continue;
            }
            que.push({x, y});
            board[x][y] = -1;
            }
        }
    }   
    cout <<"IMPOSSIBLE\n";
}