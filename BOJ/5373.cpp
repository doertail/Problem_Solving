// 5373:큐빙
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define N 3
using namespace std;
int cube[6][3][3];
// 0위, 1아래, 2앞, 3뒷, 4왼, 5오
// 위: 앞 옆 뒤 오
// 아래: 앞 옆 뒤 오
// 왼쪽, 
void print_color();
void rotate_plane(char p, char l);
void turn_plane(int n, char l);
int main(void){
    FAST_IO
    int T; cin >> T;
    while(T--){
        // cube 초기화
        for(int i=0; i<6; i++)
            for(int j=0; j<3; j++)
                for(int k=0; k<3; k++)
                    cube[i][j][k] = i;
        // 회전 입력받고 구현하기.
        int n; cin >> n;
        for(int i=0; i<n; i++){
            char p, l;
            cin >> p >> l;
            rotate_plane(p, l);
        }
        // 맨 윗 면 print
        print_color();
    }
    
    return 0;
}


void rotate_plane(char p, char l){
    int tmp[3];
    if(p == 'U'){
        if(l == '+'){// 시계
            // 기준 면 변경
            turn_plane(0, l);
            for(int i=0; i<3; ++i){
                tmp[i] = cube[2][0][i];
                cube[2][0][i] = cube[5][0][i];
                cube[5][0][i] = cube[3][2][2 - i];
                cube[3][2][2 - i] = cube[4][0][i];
                cube[4][0][i] = tmp[i];
            }
        }
        else{ // 반시계
            turn_plane(0, l);
            for(int i=0; i<3; ++i){
                tmp[i] = cube[2][0][i];
                cube[2][0][i] = cube[4][0][i];
                cube[4][0][i] = cube[3][2][2 - i];
                cube[3][2][2 - i] = cube[5][0][i];
                cube[5][0][i] = tmp[i];
            }
        }
    }

    else if(p == 'D'){
        
        if(l == '+'){// 시계
            turn_plane(1, l);

            for(int i=0; i<3; ++i){
                tmp[i] = cube[2][2][i];
                cube[2][2][i] = cube[4][2][i];
                cube[4][2][i] =  cube[3][0][2-i];
                cube[3][0][2-i] = cube[5][2][i];
                cube[5][2][i] = tmp[i]; 
            }
        }

        else{
            turn_plane(1, l);
            for(int i=0; i<3; ++i){
                tmp[i] = cube[2][2][i];
                cube[2][2][i] = cube[5][2][i];
                cube[5][2][i] =  cube[3][0][2-i];
                cube[3][0][2-i] = cube[4][2][i];
                cube[4][2][i] = tmp[i]; 
            }
        }
    }
    else if(p == 'F'){
        if(l == '+'){// 시계
            // 기준 면 변경
            turn_plane(2, l);
            for(int i=0; i<3; ++i){
                tmp[i] = cube[0][2][i];
                cube[0][2][i] = cube[4][2-i][2];
                cube[4][2-i][2] = cube[1][0][2-i];
                cube[1][0][2-i] = cube[5][i][0];
                cube[5][i][0] = tmp[i]; 
            } 
        }

        else{
            turn_plane(2, l);
            for(int i=0; i<3; ++i){
                tmp[i] = cube[0][2][i];
                cube[0][2][i] = cube[5][i][0];
                cube[5][i][0] = cube[1][0][2-i];
                cube[1][0][2-i] = cube[4][2-i][2];
                cube[4][2-i][2] = tmp[i]; 
            } 
        }
    }
    else if(p == 'B'){
        if(l == '+'){// 시계 뒤니까 반시계가 됨. .
            // 기준 면 변경
            turn_plane(3, l);
            int tmp[3] = {cube[0][0][0], cube[0][0][1], cube[0][0][2]};
            cube[0][0][0] = cube[5][0][2]; 
            cube[0][0][1] = cube[5][1][2]; 
            cube[0][0][2] = cube[5][2][2];

            cube[5][0][2] = cube[1][2][2]; 
            cube[5][1][2] = cube[1][2][1]; 
            cube[5][2][2] = cube[1][2][0];

            cube[1][2][2] = cube[4][2][0]; 
            cube[1][2][1] = cube[4][1][0]; 
            cube[1][2][0] = cube[4][0][0];

            cube[4][2][0] = tmp[0];        
            cube[4][1][0] = tmp[1];       
            cube[4][0][0] = tmp[2];
        }
        else{
            turn_plane(3, l);
            int tmp[3] = {cube[0][0][0], cube[0][0][1], cube[0][0][2]};

            cube[0][0][0] = cube[4][2][0];
            cube[0][0][1] = cube[4][1][0];
            cube[0][0][2] = cube[4][0][0];

            cube[4][2][0] = cube[1][2][2]; 
            cube[4][1][0] = cube[1][2][1]; 
            cube[4][0][0] = cube[1][2][0];

            cube[1][2][2] = cube[5][0][2]; 
            cube[1][2][1] = cube[5][1][2]; 
            cube[1][2][0] = cube[5][2][2];

            cube[5][0][2] = tmp[0];        
            cube[5][1][2] = tmp[1];        
            cube[5][2][2] = tmp[2];
        }
    }
    else if(p == 'L'){
        if(l == '+'){// 시계
            // 기준 면 변경
            turn_plane(4, l);
            int tmp[3] = {cube[0][0][0], cube[0][1][0], cube[0][2][0]};

            cube[0][0][0] = cube[3][0][0]; 
            cube[0][1][0] = cube[3][1][0]; 
            cube[0][2][0] = cube[3][2][0];

            cube[3][0][0] = cube[1][0][0]; 
            cube[3][1][0] = cube[1][1][0]; 
            cube[3][2][0] = cube[1][2][0];

            cube[1][0][0] = cube[2][0][0]; 
            cube[1][1][0] = cube[2][1][0]; 
            cube[1][2][0] = cube[2][2][0];

            cube[2][0][0] = tmp[0];        
            cube[2][1][0] = tmp[1];       
            cube[2][2][0] = tmp[2];
        }
        else{
            turn_plane(4, l);
            int tmp[3] = {cube[0][0][0], cube[0][1][0], cube[0][2][0]};

            cube[0][0][0] = cube[2][0][0]; 
            cube[0][1][0] = cube[2][1][0]; 
            cube[0][2][0] = cube[2][2][0];

            cube[2][0][0] = cube[1][0][0]; 
            cube[2][1][0] = cube[1][1][0]; 
            cube[2][2][0] = cube[1][2][0];

            cube[1][0][0] = cube[3][0][0]; 
            cube[1][1][0] = cube[3][1][0]; 
            cube[1][2][0] = cube[3][2][0];

            cube[3][0][0] = tmp[0];        
            cube[3][1][0] = tmp[1];        
            cube[3][2][0] = tmp[2];
        }
    }
    else if(p == 'R'){
        if(l == '+'){// 시계
            // 기준 면 변경
            turn_plane(5, l);
            int tmp[3] = {cube[0][0][2], cube[0][1][2], cube[0][2][2]};

            cube[0][0][2] = cube[2][0][2]; 
            cube[0][1][2] = cube[2][1][2]; 
            cube[0][2][2] = cube[2][2][2];

            cube[2][0][2] = cube[1][0][2]; 
            cube[2][1][2] = cube[1][1][2]; 
            cube[2][2][2] = cube[1][2][2];

            cube[1][0][2] = cube[3][0][2]; 
            cube[1][1][2] = cube[3][1][2]; 
            cube[1][2][2] = cube[3][2][2];

            cube[3][0][2] = tmp[0];        
            cube[3][1][2] = tmp[1];        
            cube[3][2][2] = tmp[2];
        }
        else{
            turn_plane(5, l);
            int tmp[3] = {cube[0][0][2], cube[0][1][2], cube[0][2][2]};

            cube[0][0][2] = cube[3][0][2]; 
            cube[0][1][2] = cube[3][1][2]; 
            cube[0][2][2] = cube[3][2][2];

            cube[3][0][2] = cube[1][0][2]; 
            cube[3][1][2] = cube[1][1][2]; 
            cube[3][2][2] = cube[1][2][2];

            cube[1][0][2] = cube[2][0][2]; 
            cube[1][1][2] = cube[2][1][2]; 
            cube[1][2][2] = cube[2][2][2];

            cube[2][0][2] = tmp[0];        
            cube[2][1][2] = tmp[1];        
            cube[2][2][2] = tmp[2];
        }
    }
}
void turn_plane(int n, char l){
    if(l == '+'){ // 우시계
        int tmp[N][N];
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                tmp[j][N-1-i] = cube[n][i][j];

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cube[n][i][j] = tmp[i][j];
    }    
    else{
        int tmp[N][N];
        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                tmp[N-1-j][i] = cube[n][i][j];

        for(int i=0; i<N; i++)
            for(int j=0; j<N; j++)
                cube[n][i][j] = tmp[i][j];
    }
}

void print_color(){
    for(int j=0; j<3; j++){
        for(int k=0; k<3; k++){
            int color = cube[0][j][k];
            if(color == 0)
                cout << 'w';
            else if(color == 1)
                cout << 'y';
            else if(color == 2)
                cout << 'r';
            else if(color == 3)
                cout << 'o';
            else if(color == 4)
                cout << 'g';
            else if(color == 5)
                cout << 'b';
        }
        cout << '\n';
    }
}