// 14503: 로봇 청소기
#include <bits/stdc++.h>
#define tuple tuple<int, int, int>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int dx[8] = {-1, 0, 1, 0, -1, 0, 1, 0};
int dy[8] = {0, -1, 0, 1,  0, -1, 0, 1};
int N, M, r, c, d, board[50][50], ans;

void solve(tuple robot);

int main(void){
    FAST_IO
    cin >> N >> M >> r >> c >> d;
    if(d == 1 || d == 3)
        d = 4 - d;

    tuple robot = {r, c, d};

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            cin >> board[i][j];
    
    solve(robot);

    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            ans += board[i][j]/2;

    cout << ans <<"\n";

    return 0;
}

void solve(tuple robot){
    queue<tuple> Q;
    Q.push(robot);
    board[get<0>(robot)][get<1>(robot)] = 2;

    while (!Q.empty()){
        tuple _robot = Q.front();
        int x = get<0>(_robot);
        int y = get<1>(_robot);
        int d = get<2>(_robot);
        Q.pop();
        board[x][y] = 2;
        for(int i=d+1; i<d+6; i++){ 
            if(i == d+5){// 빈칸이 없다!!
                int nx = x+dx[d+2]; int ny = y+dy[d+2]; 
                if(board[nx][ny]== 1)
                    break;
                Q.push({x+dx[d+2], y+dy[d+2], d}); // 후진
                break;
            }
            int nx = x + dx[i]; int ny = y + dy[i];
            if(board[nx][ny] >= 1)
                continue;

            if(board[nx][ny] == 0){ // 빈칸이 있다!
                if(i+1 > 4)
                    i -= 4;
                Q.push({nx, ny, i});
                break;
            }
        }
    }   
}