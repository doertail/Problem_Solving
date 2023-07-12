// 18808: 스티커 붙이기
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
using namespace std;

int board[41][41];
int my_board[11][11]; // 스티커 정보 입력
int temp_board[11][11];
int num_of_STK;
int column, row;

void take_stk(int row, int column, int n=0);
bool put_stk(int i, int j, int _row, int _column);

int main(void){
    FAST_IO
    cin >> row >> column >> num_of_STK;
    int _column, _row;

    while(num_of_STK--){
        cin >> _row >> _column;
        
        for(int i=0; i<_row; i++){
            for(int j=0; j<_column; j++){
                cin >> my_board[i][j];
                temp_board[i][j] = my_board[i][j];
            }
        }
        take_stk(_row, _column);
    }


    /* 종이 얼마나 붙였는지 ..*/
    int sum = 0;

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(board[i][j])
                sum++;
        }
    }
    cout << sum << "\n";
    
    return 0;
}

// 스티커 가져오는 함수
void take_stk(int _row, int _column, int n){ // n*90도 만큼 돌림.
    if(n == 4) // 넌 답이 없다
        return;

    for(int i=0; i<row; i++){
        for(int j=0; j<column; j++){
            if(put_stk(i, j, _row, _column))
                return; // 스티커 붙이기 완료!
        }
    }
    // 못 붙임 ..
    
    for(int i=0; i<_column; i++)
        for(int j=0; j<_row; j++)
            my_board[i][j] = temp_board[_row-j-1][i];

    for(int i=0; i<_column; i++)
        for(int j=0; j<_row; j++)
            temp_board[i][j] = my_board[i][j];

    take_stk(_column, _row, n+1);
}

bool put_stk(int i, int j, int _row, int _column) // i, j자리에 붙일 수 있는지
{
    for(int x=0; x<_row; x++){
        for(int y=0; y<_column; y++){
            if(x+i >= row || y+j >= column) 
                return false;

            if(board[i+x][j+y]&& my_board[x][y])
                return false;
        }
    }

    /* 붙이기! */
    for(int x=0; x<_row; x++){
        for(int y=0; y<_column; y++){
            board[i+x][j+y] = max(board[i+x][j+y],my_board[x][y]);
        }
    }

    return true;
}