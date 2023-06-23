// 2667: 단자번호 붙이기
#include <bits/stdc++.h>

using namespace std;

int row, column, day;

int board[1001][1001];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int temp;
priority_queue<int, vector<int>, greater<int>> pq;
queue<pair<int, int>> que;

void BFS();

int main(void) 
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> column;
    row = column;
    char c;
    for(int i=0; i < row; i++){
        for(int j=0; j < column; j++){
            cin >> c;
            if(c=='0')    board[i][j] = 0;
            else          board[i][j] = 1;
        }
    }
        

    for(int i=0; i < row; i++) {
        for(int j=0; j < column; j++) {
            if(board[i][j] != 1) continue;
            que.push({i,j});
            board[i][j] = -1;
            BFS();
            temp++;
        }
    }   
    cout << temp<<"\n";

    while(!pq.empty()) {
        cout << pq.top() <<"\n";
        pq.pop();
    }

    return 0;   
}

void BFS() 
{
    int sum = 1;
    while(!que.empty()) {
        pair<int, int> temp = que.front(); que.pop();

        for(int i = 0; i < 4; i++) {
            int x = temp.first + dx[i]; 
            int y = temp.second + dy[i];

            if(x >= row || x < 0 || y >= column || y < 0) continue;
            if(board[x][y] != 1) continue;

            que.push({x, y});
            sum ++;
            board[x][y] = -1;
        }
    }   
    pq.push(sum);
}