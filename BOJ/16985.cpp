// 17985: Maaaaaaaaaze
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define tuple tuple<int, int, int>
using namespace std;
int dz[] = {0, 0, 0, 0, 1, -1};
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {1, -1, 0, 0, 0, 0};
tuple start[4] = {{0, 0, 0}, {0, 0, 4}, {0, 4, 0}, {0, 4, 4}};
bool board[5][5][5]; // 1층 5x5
bool new_board[20][5][5]; // 0: 0~3, 1: 4~7, 2: 8~11, 3: 12~15, 4: 16~19  
bool maze[5][5][5];
int visited[5][5][5]; // for BFS

int arr[5] = {0, 1, 2, 3, 4};
int Pow[5] = {0, 0, 0, 0, 0};

void turn(int h);
void make_maze(int num=4);
void BFS();
int ANS = (1<<10);

int main(void){
    FAST_IO
    // 입력
    for(int h=0; h<5; h++){
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                cin >>board[h][i][j];
                new_board[h*4][i][j] = board[h][i][j];
            }
        }
        // new_board에 돌린거 미리 저장
        turn(h);
    }

    // 순서 정하기 12345 , 54312
    do{
        make_maze();
        if(ANS == 12)
            break;
    }while(next_permutation(arr, arr+5));

    if(ANS == 1024)
        cout << -1;
    else 
        cout << ANS <<"\n";

    return 0;
}

void turn(int h){
    bool temp[5][5];
    int n=4;
    for(int n=0; n<4; n++){
        // board에서 옮기기
        for(int i=0; i<5; i++)
            for(int j=0; j<5; j++)
                temp[i][j] = board[h][4-j][i];   
        // new_board에 옮기고, board에도 반영하기
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                new_board[h*4 +n][i][j] = temp[i][j];
                board[h][i][j] = temp[i][j];
            }
        }
    }
}

void make_maze(int num){
    for(int h=0; h<5; h++)
        for(int i=0; i<5; i++)
            for(int j=0; j<5; j++)
                maze[h][i][j] = new_board[arr[h]*4 + Pow[arr[h]]][i][j];
    BFS();
    if(ANS == 12)
        return;
    int idx = 4;
    while(1)
    if(Pow[idx] == 3){
        if(idx == 0)
            break;
        Pow[idx] = 0;
        idx--;
        continue;
    }
    else{
        Pow[idx]++;
        make_maze(idx);
        break;
    }
}

void BFS(){
    for(int num=0; num<4; num++){

        for(int h=0; h<5; h++)
            for(int i=0; i<5; i++)
                for(int j=0; j<5; j++)
                    visited[h][i][j] = -1;

        int sh = get<0>(start[num]);
        int si = get<1>(start[num]);
        int sj = get<2>(start[num]);

        if(!maze[sh][si][sj] || !maze[4-sh][4-si][4-sj])
            continue;
        
        queue<tuple> Q;
        Q.push({sh, si, sj});
        visited[sh][si][sj] = 0;

        while(!Q.empty()){
            int z = get<0>(Q.front());
            int x = get<1>(Q.front());
            int y = get<2>(Q.front());
            Q.pop();

            for(int n=0; n<6; n++){
                int nz = z + dz[n];
                int nx = x + dx[n];
                int ny = y + dy[n];
                if(nz < 0 || nz >= 5 || nx < 0 || nx >= 5 || ny < 0 || ny >= 5) // Out of Range
                    continue;
                if(!maze[nz][nx][ny]) // not accessiable
                    continue;
                if(visited[nz][nx][ny] != -1) // Already visited
                    continue;

                visited[nz][nx][ny] = visited[z][x][y] + 1;
                Q.push({nz, nx, ny});
            }
        }

        if(visited[4-sh][4-si][4-sj] == -1) // 방문 불가 ㅠㅠ
            continue;
        ANS = min(ANS, visited[4-sh][4-si][4-sj]);
    }
}