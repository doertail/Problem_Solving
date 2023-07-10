// 18809: Gaaaaaaaaaarden
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
#define tuple tuple<int, int, int>
using namespace std;

int MAX; // 출력할 값
int board[51][51]; // 입력 여기서 받기
int lab[51][51][2]; // 여기서 BFS

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int num_of_g, num_of_r, low, column;
queue<tuple> Q; //BFS에서 쓸 큐
vector<pair> vec; // 배양액 뿌릴 수 있는 땅

void BFS();
int main(void){
    FAST_IO
    cin >> low >> column >> num_of_g >> num_of_r;

    for(int i=0; i<low; i++){
        for(int j=0; j<column; j++){
            cin >> board[i][j];
            if(board[i][j] == 2)
                vec.push_back({i, j});
        }
    }
    int num_of_chemi = num_of_g + num_of_r;

    int possible_ground = vec.size();
    int* arr = new int[possible_ground]; // vec size가 배양액 뿌릴 수 있는 땅
    fill(arr, arr+possible_ground, 1);
    fill(arr, arr+num_of_chemi, 0);
    // (0, 0, 0, 1, 1) 6개 중에서 4개 6C4

    // 뿌릴 수 있는 땅 중에서 배양액 개수만큼 고르기
    do{
        vector<pair> vec2; // 이제 여기서 빨강 초록 나눔! 
        for(int i=0; i<possible_ground; i++){
            if(!arr[i])
                vec2.push_back(vec[i]); // 땅 고르기
        }
        // 고른 땅에서 빨강, 초록 분리
        int* arr2 = new int[num_of_chemi]; 
        fill(arr2, arr2+num_of_chemi, 1); // 1이면 빨강
        fill(arr2, arr2+num_of_g, 0); // 0이면 초록
        // 배양액 뿌릴 땅 정하기
        do{
            for(int i=0; i<low; i++)
                for(int j=0; j<column; j++){
                    for(int c=0; c<2; c++)
                        lab[i][j][c] = -1;
            } // 초기화

            if(!Q.empty())
                Q.pop();

            for(int i=0; i<num_of_chemi; i++){
                if(arr2[i] == 1){ // 빨강
                    lab[vec2[i].first][vec2[i].second][1] = 0;
                    Q.push({vec2[i].first, vec2[i].second, 1});
                }
                else{ // 초록
                    lab[vec2[i].first][vec2[i].second][0] = 0;
                    Q.push({vec2[i].first, vec2[i].second, 0});
                }
            }
            BFS();
        }while(next_permutation(arr2, arr2+num_of_chemi));
    }while(next_permutation(arr, arr+possible_ground));
    
    cout << MAX << "\n"; 
    
    return 0;
}

void BFS(void)
{
    int temp_flower = 0;

    while(!Q.empty()){
        tuple frt = Q.front(); Q.pop();
        int x = get<0>(frt);
        int y = get<1>(frt);
        int c = get<2>(frt);
        if(lab[x][y][c] == -3) // 꽃인데 큐에 넣은것
            continue;

        for(int i=0; i<4; i++){
            int nx = x + dx[i]; int ny = y + dy[i];
            if(nx < 0 || ny < 0 || board[nx][ny] == 0)
                continue;
            if(lab[nx][ny][c] != -1) // 같은 색 배양재를 이미 뿌림!
                continue;

            if(lab[nx][ny][1-c] != -1){ // 다른 색 배양제를 이미 뿌림!
                if(lab[nx][ny][1-c] != lab[x][y][c] + 1)  
                    continue; // 뒷북! 꽃 안됨
                temp_flower++;
                lab[nx][ny][0] = -3; // 꽃
                lab[nx][ny][1] = -3; // 꽃
                continue;
            }
            lab[nx][ny][c] = lab[x][y][c] + 1;
            Q.push({nx, ny, c});
        }
    }
    MAX = max(MAX, temp_flower);
}