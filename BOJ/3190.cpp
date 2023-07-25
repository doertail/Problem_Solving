// 3190: 뱀
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int N, K;
int board[101][101]; // -1 사과 2뱀
int T=1;
pair<int, int> head;
pair<int, int> tail;
queue<pair<int, char>> Q;
vector<pair<int, int>> Snake;
void turnLeftArray();
void turnRightArray();
int main(void){
    FAST_IO
    cin >> N >> K;
    while(K--){
        int x, y;
        cin >> x >> y;
        board[x-1][y-1] = -1; // 사과
    }
    int L;
    cin >> L;
    while(L--){
        int X; char C;
        cin >> X >> C;
        Q.push({X, C});
    }
    board[0][0] = 2;
    head = {0, 0};
    Snake.push_back(head);
    tail = Snake.front();
    
    while(1){
        tail = Snake.front();
        head = Snake.back();
        int x = head.first; int y = head.second;
        if(y+1 == N || board[x][y+1] == 2)
            break;
        else if(board[x][y+1] == -1){
            head = {x, y+1};
            board[x][y+1] = 2;
            Snake.push_back(head);
        }
        else if(board[x][y+1] == 0){
            board[x][y+1] = 2;
            Snake.push_back({x, y+1});
            head ={x, y+1};
            tail = Snake.front();
            
            board[tail.first][tail.second] = 0;
            Snake.erase(Snake.begin());
        }
        T++;
        if(!Q.empty() && Q.front().first == T-1){
            auto frt = Q.front(); Q.pop();
            if(frt.second == 'L'){
                turnRightArray();
                for(int i=0; i< Snake.size(); i++){
                    auto temp = Snake[i];
                    Snake[i] = {temp.second, N- 1- temp.first};
                }
            }
            else{
                turnLeftArray();
                for(int i=0; i< Snake.size(); i++){
                    auto temp = Snake[i];
                    Snake[i] = {N-1-temp.second, temp.first};
                }
            }
        }
    }

    cout << T << '\n';

    return 0;
}

void turnLeftArray(){
    int tmp[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            tmp[N-1-j][i] = board[i][j];

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            board[i][j] = tmp[i][j];
}

void turnRightArray(){
    int tmp[N][N];
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            tmp[j][N-1-i] = board[i][j];

    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            board[i][j] = tmp[i][j];
}