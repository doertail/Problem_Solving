// 11559: Puyo Puyo
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
using namespace std;

char board[12][6];
int _board[12][6]; // 0이면 탐색 x 1이면 탐색 완

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int ANS;
void _Find();

vector<pair> temp;
queue<pair> Q;

int main(void){
    FAST_IO
    for(int i=0; i<12; i++)
        for(int j=0; j<6; j++)
            cin >> board[i][j];
    
    _Find();

    cout << ANS <<"\n";
    
    return 0;
}

void _Find(){
    bool flag = true;
    
    while(flag){
        flag = false;

        for(int i=0; i<12; i++)
                fill(_board[i], _board[i]+6 ,0);

        for(int i=0; i<12; i++){
            for(int j=0; j<6; j++){
                if(board[i][j] == '.')
                    continue;
                if(_board[i][j] == 1)
                    continue;

                Q.push({i, j});
                _board[i][j]++;
                char s = board[i][j];
                temp.push_back({i, j});
                
                while(!Q.empty()){
                    int x = Q.front().first;
                    int y = Q.front().second; 
                    Q.pop();

                    for(int n=0; n<4; n++){
                        int nx = x + dx[n];
                        int ny = y + dy[n];

                        if(nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
                            continue;
                        if(board[nx][ny] != s)
                            continue;
                        if(_board[nx][ny]) // 이미 탐색!
                            continue;

                        _board[nx][ny]++;
                        Q.push({nx, ny});
                        temp.push_back({nx, ny});
                    }
                }

                if(temp.size()>=4){
                    flag = true;
                    for(pair p:temp)
                        board[p.first][p.second] = '.';
                }

                temp.clear();
            }
        }
        

        if(flag){
            ANS++;
            for(int j=0; j<6; j++){
                stack<char> S;
                for(int i=0; i<12; i++){
                    if(board[i][j] == '.')
                        continue;
                    S.push(board[i][j]);
                    board[i][j] = '.';
                }
                for(int i=11; i>=0; i--){
                    if(S.empty())  break;

                    board[i][j] = S.top();
                    S.pop();
                }
            }
        }
    }   
}