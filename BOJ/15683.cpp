// 15683: 감시
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
using namespace std;

int board[9][9];
int my_board[9][9];
int num_of_CCTV;
vector<pair> vec;
int MIN = 81;
int column, row;

void right(int x, int y);
void rev_right(int x, int y);
void left(int x, int y);
void rev_left(int x, int y);
void down(int x, int y);
void rev_down(int x, int y);
void up(int x, int y);
void rev_up(int x, int y);
void CCTV(int n);

int main(void){
    FAST_IO
    
    cin >> column >> row;

    for(int i=0; i<column; i++){
        for(int j=0; j<row; j++){
            cin >> board[i][j];
            if(0 < board[i][j] && board[i][j] < 6) // cctv라면
                vec.push_back({i, j});
            my_board[i][j] = board[i][j];
        }
    }
    num_of_CCTV = vec.size();

    CCTV(0);

    cout << MIN <<"\n";

    return 0;
}

void CCTV(int n){
    if(n == num_of_CCTV){
        int temp = 0;
        for(int i=0; i<column; i++){
            for(int j=0; j<row; j++){
                temp += (my_board[i][j] == 0);
            }
        }

        MIN = min(MIN, temp);

        return;
    }

    int x = vec[n].first; int y = vec[n].second;
    int num = board[x][y];

    if(num == 1){
        //오른쪽만
        right(x, y);
        CCTV(n+1);
        rev_right(x, y);
        // 왼쪽만
        left(x, y);
        CCTV(n+1);
        rev_left(x, y);
        // 위만
        up(x, y);
        CCTV(n+1);
        rev_up(x, y);
        // 아래만
        down(x, y);
        CCTV(n+1);
        rev_down(x, y);
    }
    else if(num == 2){
        // 가로만
        right(x, y); left(x, y);
        CCTV(n+1);
        rev_right(x, y); rev_left(x, y);
        // 세로만
        up(x, y); down(x, y);
        CCTV(n+1);
        rev_up(x, y); rev_down(x, y);
    }
    else if(num == 3){
        // 오른쪽, 위
        right(x, y); up(x, y);
        CCTV(n+1);
        rev_right(x, y); rev_up(x,y);
        // 오른쪽 아래
        right(x, y); down(x, y);
        CCTV(n+1);
        rev_right(x, y); rev_down(x,y);
        // 왼쪽 위
        left(x, y); up(x, y);
        CCTV(n+1);
        rev_left(x, y); rev_up(x,y);
        // 왼쪽 아래
        left(x, y); down(x, y);
        CCTV(n+1);
        rev_left(x, y); rev_down(x,y);
    }
    else if(num == 4){
        // 아래 빼고
        right(x, y); left(x, y); up(x, y);
        CCTV(n+1);
        rev_right(x, y); rev_left(x, y); rev_up(x, y);

        // 위 빼고
        right(x, y); left(x, y); down(x, y);
        CCTV(n+1);
        rev_right(x, y); rev_left(x, y); rev_down(x, y);
        
        // 오른쪽 빼고
        up(x, y); left(x, y); down(x, y);
        CCTV(n+1);
        rev_up(x, y); rev_left(x, y); rev_down(x, y);
        
        // 왼쪽 빼고
        up(x, y); right(x, y); down(x, y);
        CCTV(n+1);
        rev_up(x, y); rev_right(x, y); rev_down(x, y);
    }
    else if(num == 5){
        right(x, y); left(x, y); down(x, y); up(x, y); 
        CCTV(n+1);
        rev_right(x, y); rev_left(x, y); rev_down(x, y); rev_up(x, y); 
    }
}

void right(int x, int y){
    if(y+1 != row){
        for(int j=y+1; j<row; j++){
            if(board[x][j] == 6)
                break;
            if(board[x][j] == 0)
                my_board[x][j]--;
        }
    }
}
void rev_right(int x, int y){
    if(y+1 != row){
        for(int j=y+1; j<row; j++){
            if(board[x][j] == 6)
                break;
            if(board[x][j] == 0)
                my_board[x][j]++;
        }
    }
}

void left(int x, int y){
    if(y != 0){
        for(int j=y-1; j>=0; j--){
            if(board[x][j] == 6)
                break;
            if(board[x][j] == 0)
                my_board[x][j]--;
        }
    }
}

void rev_left(int x, int y){
    if(y != 0){
        for(int j=y-1; j>=0; j--){
            if(board[x][j] == 6)
                break;
            if(board[x][j] == 0)
                my_board[x][j]++;
        }
    }
}

void up(int x, int y){
    if(x != 0){
        for(int i=x-1; i>=0; i--){
            if(board[i][y] == 6)
                break;
            if(board[i][y] == 0)
                my_board[i][y]--;
        }
    }
}

void rev_up(int x, int y){
    if(x != 0){
        for(int i=x-1; i>=0; i--){
            if(board[i][y] == 6)
                break;
            if(board[i][y] == 0)
                my_board[i][y]++;
        }
    }
}

void down(int x, int y){
    if(x+1 != column){
        for(int i=x+1; i<column; i++){
            if(board[i][y] == 6)
                break;
            if(board[i][y] == 0)
                my_board[i][y]--;
        }
    }
}

void rev_down(int x, int y){
    if(x+1 != column){
        for(int i=x+1; i<column; i++){
            if(board[i][y] == 6)
                break;
            if(board[i][y] == 0)
                my_board[i][y]++;
        }
    }
}