// 15684: 사다리 조작
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
using namespace std;

int N, M, H, board[32][12];
bool solve(int a, int b, int target);
int main(void){
    FAST_IO
    cin >> N >> M >> H;
    while(M--){
        int a, b;
        cin >> a >> b;
        board[a][b+1] = b;
        board[a][b] = b+1;
    }
    bool flag = true;
    for(int j=1; j<=N; j++){
        if(!solve(1, j, j)){
            flag = false;
            break;
        }
    }
    if(flag){
        cout << 0 <<'\n';
        return 0;
    }

    flag = true;
    vector<pair> vec;
    for(int i=1; i<=H; i++){ 
        for(int j=1; j<N; j++){
            if(board[i][j] == 0 && board[i][j+1] == 0)
                vec.push_back({i, j});
        }
    }
    int size =vec.size();
    int* arr = new int[size];
    fill(arr, arr+size, 1);
    arr[0] = 0;
    do{
        queue<pair> Q;
        for(int i=0; i<size; i++){
            if(arr[i] == 0){
                board[vec[i].first][vec[i].second] = vec[i].second+1;
                board[vec[i].first][vec[i].second+1] = vec[i].second;
                Q.push({vec[i].first, vec[i].second});
            }
        }
        for(int j=1; j<=N; j++){
            if(!solve(1, j, j)){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << 1 <<'\n';
            return 0;
        }
        else{
            flag = true;
            while(!Q.empty()){
                board[Q.front().first][Q.front().second] = 0;
                board[Q.front().first][Q.front().second+1] = 0;
                Q.pop();
            }
        }
    }while(next_permutation(arr, arr+size));

    flag = true;
    fill(arr, arr+size, 1);
    arr[0] = 0, arr[1] = 0;
    do{
        queue<pair> Q;
        for(int i=0; i<size; i++){
            if(arr[i] == 0){
                board[vec[i].first][vec[i].second+1] = vec[i].second;
                board[vec[i].first][vec[i].second] = vec[i].second+1;
                Q.push({vec[i].first, vec[i].second});
            }
        }
        for(int j=1; j<=N; j++){   
            if(!solve(1, j, j)){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << 2 <<'\n';
            return 0;
        }
        else{
            flag = true;
            while(!Q.empty()){
                board[Q.front().first][Q.front().second] = 0;
                board[Q.front().first][Q.front().second+1] = 0;
                Q.pop();
            }
        }
    }while(next_permutation(arr, arr+size));

    flag = true;
    fill(arr, arr+size, 1);
    arr[0] = 0, arr[1] = 0, arr[2] =0;
    do{
        queue<pair> Q;
        for(int i=0; i<size; i++){
            if(arr[i] == 0){
                board[vec[i].first][vec[i].second+1] = vec[i].second;
                board[vec[i].first][vec[i].second] = vec[i].second+1;
                Q.push({vec[i].first, vec[i].second});
            }
        }
        for(int j=1; j<=N; j++){
            if(!solve(1, j, j)){
                flag = false;
                break;
            }   
        }
        if(flag){
            cout << 3 <<'\n';
            return 0;
        }
        else{
            flag = true;
            while(!Q.empty()){
                board[Q.front().first][Q.front().second] = 0;
                board[Q.front().first][Q.front().second+1] = 0;
                Q.pop();
            }
        }
    }while(next_permutation(arr, arr+size));
        
    cout << -1 << '\n';

    return 0;
}

bool solve(int a, int b, int target){
    for(int i=a; i<=H; i++){
        if(board[i][b] != 0)
            return solve(i+1, board[i][b], target);
    }
    if(b == target)
        return true;
    else
        return false;
}