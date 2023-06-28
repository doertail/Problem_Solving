// 9663: N-Queen
#include <bits/stdc++.h>
#define ll long long
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);

int board[16][16];
ll result[16];
int N;
ll sum, temp;

using namespace std;

bool check(int x, int y);
void push(int i, int j, int n);

int main(void){
    FAST_IO
    cin >> N;
    
    for(int j=0; j<N; j++){
        if(result[j]){
            sum += result[j];
            continue;
        }
        push(0, j, 1);
        result[N-1-j] = temp;
        sum += temp;
        temp = 0;
    }
    
    cout << sum <<"\n";

    return 0;
}

void push(int x, int y, int n){
    if(n == N){temp++; return;}

    board[x][y] = 1;
    for(int j=0; j<N; j++){
        if(!check(x+1, j)) continue;
        push(x+1, j, n+1);
    }

    board[x][y] = 0;
}

bool check(int x, int y){ // (x, y)에 넣어도 괜찮은지!

    for(int i=0; i<N; i++)
        if(board[i][y]) return false;

    int smaller = min(x, y);
    for(int i=1; i<=smaller; i++)
        if(board[x-i][y-i]) return false;

    // /방향
    for(int i=1; ; i++){
        if(x-i < 0 || y+i >=N) break;
        if(board[x-i][y+i]) return false;
    }
    
    return true;
}