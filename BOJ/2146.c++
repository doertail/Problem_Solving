// 2146: 다리 만들기
#include <bits/stdc++.h>

using namespace std;

int row, column;
int temp = 1;
int dis=200; 

int board[101][101];
int island[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue< pair<int, int>> Q;
priority_queue<int> PQ;
queue< pair<int, int>> LQ;
queue< pair<int, int>> LLQ;

void BFS(int x, int y);
void L_BFS();

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> row;
    column = row;

    for(int i=0; i < row; i++)
        for(int j=0; j < column; j++)
            cin >> board[i][j];

    for(int i=0; i < row; i++) {
        for(int j=0; j < column; j++) {
            if(board[i][j] != 0 && island[i][j] == 0)
                BFS(i, j);
        }
    }

    L_BFS();

    cout << dis << "\n";
}

void BFS(int x, int y) {
    Q.push({x, y});

    island[x][y] = temp;

    while(!Q.empty()) {
        pair<int, int> temp = Q.front(); Q.pop();
        bool flag = false;

        for(int i=0; i < 4; i++) {
            int nx = temp.first + dx[i];  int ny = temp.second + dy[i];

            if(nx >= row || nx < 0 || ny >= column || ny < 0 || island[nx][ny] != 0)
                continue;

            if(board[nx][ny] == 0) { // 바다를 접함
                flag = true;
                continue;
            }

            Q.push({nx, ny});
            island[nx][ny] = island[x][y];
        }

        if(flag) LQ.push({temp.first, temp.second});
    }   
    temp++;   
}

void L_BFS() {
    while(!LQ.empty()) {
        memset(board, 0, sizeof(board));

        LLQ.push(LQ.front()); LQ.pop();
        int x = LLQ.front().first; int y = LLQ.front().second;

        int num = island[x][y];

        while(!LLQ.empty()) {
            pair<int, int> temp = LLQ.front(); LLQ.pop();

            for(int i = 0; i < 4; i++) {
                int nx = temp.first + dx[i];  int ny = temp.second + dy[i];
                
                if(nx >= row || nx < 0 || ny >= column || ny < 0)
                    continue;

                if(island[nx][ny] == num || board[nx][ny] != 0)
                    continue;

                if(island[nx][ny] == 0) {
                    LLQ.push({nx, ny});
                    board[nx][ny] = 1;
                }

                else {
                    dis = min(abs(x-nx) + abs(y-ny) - 1, dis);
                    while(!LLQ.empty()) 
                        LLQ.pop();
                    break;
                }
            }
        }
    }   
}
