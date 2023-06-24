// 1992: 쿼드 트리 만들기
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define MAX 65

void func(int i, int j, int len);
int are_same(int x, int y, int len);

int board[MAX][MAX];

using namespace std;

int main(void){
    FAST_IO
    int N;
    cin >> N;

    for(int i=0; i < N; i++)
        for(int j=0; j < N; j++){
            char input;
            cin >> input;
            board[i][j] = input - '0';
        }
    
    func(0,0, N); //시작점,  한

    return 0;
}

void func(int x, int y, int len){
    if(are_same(x, y, len)){
        cout << board[x][y];
        return;
    } 
    cout << "(";
    int newlen = len / 2;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            func(x + i*newlen, y + j*newlen, newlen);
    cout << ")";
}

int are_same(int x, int y, int len){
    int ref = board[x][y];

    for(int i=x; i<x+len; i++){
        for(int j=y; j<y+len; j++){
            if(ref != board[i][j])
                return 0;
        }
    }

    return 1;
}