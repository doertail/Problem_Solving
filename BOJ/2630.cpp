// 2630: 색종이 만들기
#include <bits/stdc++.h>

#define condition ios_base::sync_with_stdio(0); cin.tie(NULL);

void func(int i, int j, int len);
int are_same(int x, int y, int len);

int board[129][129];

int arr[2];

using namespace std;

int main(void){
    condition
    int N;
    cin >> N;
    
    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++)
            cin >> board[i][j];

    func(0,0, N); //시작점, 한
    for(int n: arr) cout << n <<"\n";

    return 0;
}

void func(int x, int y, int len){
    if(are_same(x, y, len)) return;

    int newlen = len / 2;

    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            func(x + i*newlen, y + j*newlen, newlen);
}

int are_same(int x, int y, int len){
    int ref = board[x][y];

    for(int i=x; i<x+len; i++){
        for(int j=y; j<y+len; j++){
            if(ref != board[i][j])
                return 0;
        }
    }

    arr[ref]++;

    return 1;
}