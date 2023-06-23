// 2573: 빙산
#include <bits/stdc++.h>

using namespace std;

int row, column, year;

int board[301][301];
int sec[301][301];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue< pair<int, int>> que;
queue< tuple<int, int, int>> Q;

void BFS(int x, int y);
int find(int x, int y);

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> row >> column;

    for(int i=0; i < row; i++) {
        for(int j=0; j < column; j++) {
            cin >> board[i][j];
        }
    }   

    while(1) { 
        int num = 0; // 빙산의 개수

        for(int i=0; i < row; i++) { // 빙산 찾기..
            for(int j=0; j < column; j++) {
                if(board[i][j] != 0)
                    Q.push({find(i, j), i, j});
            }
        }   

        while(!Q.empty()) { // 물 반영
            tuple<int, int, int> t = Q.front();
            int i = get<1>(t); int j = get<2>(t);

            board[i][j] = board[i][j] - get<0>(t);
            
            if(board[i][j] < 0) board[i][j] = 0;

            Q.pop();
        }

        year++;

        for(int i=0; i < row; i++) {
            for(int j=0; j < column; j++) {
                if(sec[i][j] == 0 && board[i][j] != 0) {
                    BFS(i, j);
                    num += 1;
                }
            }
        }

        if(num >= 2){
            cout << year << "\n";
            return 0;
        }
   
        else if(num == 0){
            cout << 0 << "\n";
            return 0;
        }
        
        memset(sec, 0, sizeof(sec));
    }
}

void BFS(int x, int y) {
    que.push({x, y});

    sec[x][y] = -1;

    while(!que.empty()) {
        pair<int, int> temp = que.front(); que.pop();
        for(int i =0 ; i < 4; i++) {
            int X = temp.first + dx[i];  int Y = temp.second + dy[i];

            if(X >= row || X < 0 || Y >= column || Y < 0)
                continue;

            if(board[X][Y] == 0 || sec[X][Y] == -1) 
                continue;

            que.push({X, Y});
            sec[X][Y] = -1;
        }
    }   
}

int find(int x, int y)
{
    int ret = 0;

    for(int i = 0; i < 4; i++) {
        int X = x + dx[i];  int Y = y + dy[i];

        if(X >= row || X < 0 || Y >= column || Y < 0)
            continue;

        if(board[X][Y] != 0) 
            continue;

        ret += 1;
    }
    
    return ret;
}