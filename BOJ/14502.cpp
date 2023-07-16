// 14502: 연구소
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>

using namespace std;
int board[8][8];
int visited[8][8];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, M;
int ANS;

vector<pair> vec;
void solve(int i=0, int j=0, int n=0);
void BFS(pair);

int main(void){
    FAST_IO
    
    cin >> N >> M;

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
            if(board[i][j] == 2)
                vec.push_back({i, j});
        }
    }

    solve();
    
    cout << ANS <<"\n";

    return 0;
}

void solve(int x, int y, int n){
    if(n==3){
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                visited[i][j] = 0;
        
        for(pair p:vec)
            BFS(p);

        int temp=0;

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(visited[i][j] == 0 && board[i][j] == 0)
                    temp++;       
            }
        }
        
        ANS = max(temp, ANS);
        
        return;
    }

    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            if(board[i][j] == 0){
                board[i][j]++;
                solve(i, j, n+1);
                board[i][j]--;
            }
        }
    }
}

void BFS(pair p){
    queue<pair> Q;
    Q.push(p);
    visited[Q.front().first][Q.front().second] = 1;

    while(!Q.empty()){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        for(int n=0; n<4; n++){
            int nx = x + dx[n]; int ny = y + dy[n];

            if(nx < 0 || nx >= N || ny < 0 || ny >= M)
                continue;
            if(visited[nx][ny])
                continue;
            if(board[nx][ny] == 1)
                continue;
            visited[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
}