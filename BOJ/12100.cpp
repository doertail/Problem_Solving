// 12100: 2048 (Easy)
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int MAX;
int Length;

int divided_2(int n);
void solve(int n, int board[21][21]);

int main(void){
    FAST_IO

    cin >> Length;
    int board[21][21];
    int num;
    for(int i=0; i<Length; i++){
        for(int j=0; j<Length; j++){
            cin >> num;
            board[i][j] = divided_2(num);
        }
    }
    solve(0, board);

    cout << (1 << MAX) << "\n";

    return 0;
}

void solve(int n, int board[21][21]){
    if(n==5){
        int temp = 0;
        
        for(int i=0; i<Length; i++)
            for(int j=0; j<Length; j++)
                temp = max(temp, board[i][j]);

        MAX = max(temp, MAX);
        
        return;
    }
    
    if(!MAX){
        int temp = 0;
        
        for(int i=0; i<Length; i++)
            for(int j=0; j<Length; j++)
                temp = max(temp, board[i][j]);

        if(temp < MAX-(5-n))
            return;
    }
        
    int temp[21][21];
    for(int i=0; i<Length; i++)
        for(int j=0; j<Length; j++)
            temp[i][j] = board[i][j];

    for(int i=0; i<Length; i++){
        for(int j=0; j<Length; j++){
            if(!temp[i][j]) //0이면 나가라~
                continue;

            for(int k=j+1; k<Length; k++){
                if(temp[i][j] == temp[i][k]){
                    temp[i][j]++;
                    temp[i][k] = 0;
                    j = k;
                    break;
                }
                else if(temp[i][k]){
                    break;
                }
            }
        }
    }
    for(int i=0; i<Length; i++){
        for(int j=0; j<Length-1; j++){
            if(temp[i][j])
                continue;

            for(int k=j+1; k<Length; k++){
                if(!temp[i][k])
                    continue;
                //(i,k) 가 양수!
                temp[i][j] = temp[i][k];
                temp[i][k] = 0;
                break;
            }
        }
    }
    solve(n+1, temp);

    for(int i=0; i<Length; i++)
        for(int j=0; j<Length; j++)
            temp[i][j] = board[j][i];
    
    for(int i=0; i<Length; i++){
        for(int j=0; j<Length; j++){
            if(!temp[i][j])
                continue;
            for(int k=j+1; k<Length; k++){
                if(temp[i][j] == temp[i][k]){
                    temp[i][j]++;
                    temp[i][k]=0;
                    j = k;
                    break;
                }
                else if(temp[i][k]){
                    break;
                }
            }
        }
    }

    for(int i=0; i<Length; i++){
        for(int j=0; j<Length-1; j++){
            if(temp[i][j]) 
                continue;

            for(int k=j+1; k<Length; k++){
                if(!temp[i][k])
                    continue;
                temp[i][j] = temp[i][k];
                temp[i][k] = 0;
                break;
            }
        }
    }
    
    solve(n+1, temp);

    for(int i=0; i<Length; i++)
        for(int j=0; j<Length; j++)
            temp[i][j] = board[Length -1 -j][i];

    for(int i=0; i<Length; i++){
        for(int j=0; j<Length; j++){
            if(!temp[i][j])
                continue;
            for(int k=j+1; k<Length; k++){
                if(temp[i][j] == temp[i][k]){
                    temp[i][j]++;
                    temp[i][k] = 0;
                    j = k;
                    break;
                }
                else if(temp[i][k]){
                    break;
                }
            }
        }
    }

    for(int i=0; i<Length; i++){
        for(int j=0; j<Length-1; j++){
            if(temp[i][j])
                continue;

            for(int k=j+1; k<Length; k++){
                if(!temp[i][k])
                    continue;
                temp[i][j] = temp[i][k];
                temp[i][k] = 0;
                break;
            }
        }
    }
    solve(n+1, temp);

    for(int i=0; i<Length; i++)
        for(int j=0; j<Length; j++)
            temp[i][j] = board[i][Length-1-j];

    for(int i=0; i<Length; i++){
        for(int j=0; j<Length; j++){
            if(!temp[i][j])
                continue;
            for(int k=j+1; k<Length; k++){
                if(temp[i][j] == temp[i][k]){
                    temp[i][j]++;
                    temp[i][k] = 0;
                    j = k;
                    break;
                }
                else if(temp[i][k])
                    break;
            }
        }
    }

    for(int i=0; i<Length; i++){
        for(int j=0; j<Length-1; j++){
            if(temp[i][j])
                continue;

            for(int k=j+1; k<Length; k++){
                if(!temp[i][k])
                    continue;
                temp[i][j] = temp[i][k];
                temp[i][k] = 0;
                break;
            }
        }
    }
    solve(n+1, temp);
}

int divided_2(int n){   
    if(n==0)
        return 0;

    int i=0;
    while(n != 1){
        n = n >> 1;
        i++;
    }

    return i;
}