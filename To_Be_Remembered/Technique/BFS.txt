#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>

using namespace std;
int board[8][8];
int visited[8][8];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int N, M;


vector<pair> vec;

void BFS(pair);

int main(void){
    FAST_IO

    return 0;
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