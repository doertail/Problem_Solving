#include <bits/stdc++.h>

using namespace std;

int L, R, C;// z x y

int board[31][31][31];
int dz[] = {0, 0, 0, 0, 1, -1};
int dx[] = {1, -1, 0, 0, 0, 0};
int dy[] = {0, 0, 1, -1, 0, 0};


queue<tuple<int, int, int>> que;

void BFS();
void solution();

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    solution();

    return 0;   
}

void BFS() {
    while(!que.empty()) {
        tuple<int, int, int> temp = que.front(); que.pop();
        int num = board[get<0>(temp)][get<1>(temp)][get<2>(temp)];

        for(int i = 0; i < 6; i++) {
            int z = get<0>(temp) + dz[i]; int x = get<1>(temp) + dx[i]; int y = get<2>(temp) + dy[i];

            if(board[z][x][y] == -3) 
            {
                std::cout << "Escaped in "<< num <<" minute(s)." << "\n";
                return;   
            }   

            if(board[z][x][y] != 0) continue; // 벽이나 불이나 과거의 자신을 만난 지훈이 ..

            if(z >= L || z < 0 || x >= R || x < 0 || y >= C || y < 0) // 탈출 가능한 지훈이
                continue;

            que.push({z, x, y});

            board[z][x][y] = num + 1; // 시간 반영!
        }
    }
         
    cout << "Trapped!\n";
}

void solution() {
    while(1) {
        memset(board, 0, sizeof(board));
        while(!que.empty()) que.pop();

        cin >> L >> R >> C;

        if(L == 0 && R == 0 && C == 0)
            return;

        char c;

        for(int z=0; z < L; z++) {
            for(int i=0; i < R; i++) {
                for(int j=0; j < C; j++) {
                    cin >> c;
                    if(c == '#')
                        board[z][i][j] = -1; // 벽

                    else if(c == 'E')
                        board[z][i][j] = -3;  //마지막

                    else if(c == 'S') {
                        board[z][i][j] = 1; // 시작
                        que.push({z,i,j});
                    }
                }
            }
        }
        
        BFS();
    }
}