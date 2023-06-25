// 2448: 별 찍기 11
#include <bits/stdc++.h>

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);

char board[3072][6143];
using namespace std;

void func(int i, int j, int l);

int main(void){
    FAST_IO

    int k;
    cin >> k; // height_of_tri
    int base = 2*k-1;

    for(int i=0; i<k; i++)
        for(int j=0; j<base; j++)
            board[i][j] = ' ';

    func(0, base/2, k);

    for(int i=0; i<k; i++){
        for(int j=0; j<base; j++)
            cout << board[i][j];
        cout << "\n";
    }

    return 0;
}

void func(int i, int j, int l){
    if(l == 3){
        board[i][j] = '*';
        board[i+1][j+1] = '*';
        board[i+1][j-1] = '*';
        board[i+2][j-2] = '*';
        board[i+2][j-1] = '*';
        board[i+2][j] = '*';
        board[i+2][j+1] = '*';
        board[i+2][j+2] = '*';

        return;
    }

    else{
        func(i, j, l/2);
        func(i + l/2, j - l/3-l/6 , l/2);
        func(i + l/2, j + l/3+l/6 , l/2);
    }
}