// 1600: 말이 되고픈 원숭이
#include <bits/stdc++.h>
#define tuple tuple<int, int, int>
using namespace std;

int jump, row, column;

int board[201][201];
int dis[201][201][32]; // 세번째는 나이트 몇 번 ..

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

// 나이트
int Nx[8] = {2, 2, -2, -2, 1, -1, 1, -1};
int Ny[8] = {1, -1, 1, -1, 2, 2, -2, -2}; 

queue<tuple> Q;

void BFS();

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> jump >> column >> row; 

    for(int i=0; i < row; i++)
        for(int j=0; j < column; j++)
            cin >> board[i][j];

    if(row == 1 && column == 1){
        cout << 0;
        return 0;
    }

    BFS();   
    
    return 0;   
}

void BFS() {
    Q.push({0, 0, 0});
    dis[0][0][0] = 0;

    while(!Q.empty()) {
        tuple temp = Q.front(); Q.pop();
        int num = dis[get<0>(temp)][get<1>(temp)][get<2>(temp)];

        if(get<2>(temp) != jump){
            for(int i=0; i<8; i++){
                int nx = get<0>(temp) + Nx[i]; int ny = get<1>(temp) + Ny[i]; int nz = get<2>(temp)+1;

                if(nx < 0 || nx >= row || ny < 0 || ny >= column) continue;
                if(board[nx][ny] == 1)  continue;
                if(dis[nx][ny][nz-1] == -1) continue;
                if(dis[nx][ny][nz] == 0 || dis[nx][ny][nz] > num + 1){
                    dis[nx][ny][nz] = num + 1;
                    Q.push({nx, ny, nz});
                }
            }
        }

        for(int i=0; i<4; i++){
            int nx = get<0>(temp) + dx[i]; int ny = get<1>(temp)+ dy[i]; int nz = get<2>(temp);

            if(nx < 0 || nx >= row || ny < 0 || ny >= column)   continue;
            if(board[nx][ny] == 1)  continue;
            if(dis[nx][ny][nz] == -1) continue;
            if(dis[nx][ny][nz] == 0 || dis[nx][ny][nz] > num+1 ){
                dis[nx][ny][nz] = num + 1;
                Q.push({nx, ny, nz});
            }
        }

        dis[get<0>(temp)][get<1>(temp)][get<2>(temp)] = -1;

        for(int i=0; i<=jump; i++){
            if(dis[row-1][column-1][i] != 0) {
                cout << dis[row-1][column-1][i] <<"\n";
                return;
            }
        }
    }
    cout <<-1 <<"\n";
}