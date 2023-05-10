#include <bits/stdc++.h>

using namespace std;

int row, column, num_of_square;

int board[101][101];

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

priority_queue<int, vector<int>, greater<int>> pq;
queue<pair<int, int>> que;

int sq_nums;

void BFS(int x, int y);

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> row >> column  >> num_of_square;

    int x_1, y_1, x_2, y_2;
    
    while(num_of_square--) {
        cin >> y_1 >> x_1 >> y_2 >> x_2;
        y_2--; x_2--;

        for(int i=x_1; i<=x_2; i++) {
            for(int j=y_1; j<=y_2; j++) {
                board[i][j] = 1;
            }
        }
    }
    for(int i=0; i < row; i++) {
        for(int j=0; j < column; j++) {
            if(board[i][j] != 0) 
                continue;
            BFS(i, j);
            sq_nums++;
        }
    }   

    cout << sq_nums <<"\n";

    while(!pq.empty()) {
        cout << pq.top() <<" ";
        pq.pop();
    }

    return 0;   
}

void BFS(int x, int y) {
    que.push({x, y});
    int sum = 1;
    board[x][y] = -1;

    while(!que.empty()) {
        pair<int, int> temp = que.front(); que.pop();
        int x = temp.first; int y = temp.second;

        for(int i=0; i<4; i++) {
            int x = temp.first + dx[i]; 
            int y = temp.second + dy[i];
            
            if(x >= row || x < 0 || y >= column || y < 0)
                continue;
            if(board[x][y] != 0) 
                continue;

            que.push({x, y});

            sum ++;
            board[x][y] = -1;
        }
    }   

    pq.push(sum);
}