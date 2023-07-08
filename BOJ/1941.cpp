// 1941: 소문난 칠공주
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
char board[25];
int arr[25];
bool trace[5][5];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool BFS();

int main(void){
    FAST_IO

    int sum = 0;
    for(int i=0; i<25; i++)
        cin >> board[i];

    fill(arr+7, arr+25, 1);

    do{
        int num_y = 0; int num_s = 0;
    
        fill(&trace[0][0], &trace[5-1][5], false);

        for(int i=0; i<25; i++){
            if(arr[i])  continue; // 1이면 pass
            
            trace[i/5][i%5] = true; // 표시
            if(board[i]=='Y')
                num_y++;
            else
                num_s++;
        }

        if(num_s < 4)
            continue;

        if(!BFS()) // 연결여부
            continue;

        sum++;
        
    }while(next_permutation(arr, arr+25));

    cout << sum <<"\n";

    return 0;
}

bool BFS()
{
    int num = 0;
    bool is_visited[5][5];
    fill(&is_visited[0][0], &is_visited[5-1][5], false);
    queue<pair<int, int>> Q; 

    for(int x=0; x<5; x++){
        for(int y=0; y<5; y++){
            if(!trace[x][y])
                continue;
            Q.push({x, y});
            num++;
            break;
        }
        if(!Q.empty())
            break;
    }

    while(!Q.empty()){
        pair<int, int> ref = Q.front(); Q.pop();
        is_visited[ref.first][ref.second] = true;
        for(int i=0; i<4; i++){
            int nx = ref.first + dx[i]; int ny = ref.second + dy[i];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5)
                continue;
            if(!is_visited[nx][ny]&& trace[nx][ny]){
                Q.push({nx, ny});
                is_visited[nx][ny] = true;
                num++;
            }
        }
    }

    if(num != 7) return false;
    else        return true;
}