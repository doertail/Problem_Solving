// 2447: 별 찍기 10
#include <bits/stdc++.h>

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);

using namespace std;
char board[6562][6562];

void func(int i, int j, int N);

int main(void){
    FAST_IO
    
    int k;
    cin >> k;

    for(int i=0; i<k; i++)
        for(int j=0; j<k; j++)
            board[i][j] = ' ';

    func(0, 0, k);

    for(int i=0; i<k; i++){
        for(int j=0; j<k; j++){
            cout  << board[i][j];
        }
        cout << "\n";
    }

    return 0;
}

void func(int x, int y, int k){
    if(k==1){
        board[x][y] = '*';
        return;
    }

    int len = k/3;

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            if(i == 1 && j == 1)
                continue;
            func(x + i*len, y+ j*len, len);
        }
    }
}