// 16933 벽 부수고 이동하기 3
#include <bits/stdc++.h>
#define tuple tuple<int, int, int, bool, bool>
#define MAX 1000

using namespace std;

int crush, row, column;

string board[1002];
int dis[12][MAX+1][MAX+1];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

queue<tuple> Q;

void BFS();

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> row >> column >> crush;

    for(int i=0; i<row; i++)
        cin >> board[i];

    if(row == 1 && column == 1){
        cout << 1 << "\n";
        return 0;
    }

    BFS();

    return 0;   
}

void BFS() {
    Q.push({0, 0, 0, true, false});
    dis[0][0][0] = 1;

    while(!Q.empty()){
        auto [z, x, y, is_day, retry] = Q.front(); Q.pop();

        if(x == row -1 && y == column -1){ // 맨 마지막
            cout << dis[z][x][y] << "\n";
            return;
        }
        int num = dis[z][x][y];

        for(int i=0; i<4; i++){
            int nx = x + dx[i]; int ny = y + dy[i]; int nz = z;
            bool time = is_day; // true : 낮, false: 밤

            if(nx < 0 || nx >= row || ny < 0 || ny >= column)   continue; // 맵 넘음 ;;
            if(board[nx][ny] == '1'){
                if(time == true)
                    nz++;
                else{ // 밤 // time == false
                    Q.push({z, x, y, true, true});
                    continue;
                }
            }

            if(dis[nz][nx][ny] > 0 || nz > crush) continue;

            if(retry) dis[nz][nx][ny] = num + 2;
            else dis[nz][nx][ny] = num + 1;

            Q.push({nz, nx, ny, !time, false});
        }
    }

    cout << -1 << "\n";
}