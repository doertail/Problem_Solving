// 12851: 숨바꼭질 2
#include <bits/stdc++.h>
#define max 100000

using namespace std;
int start, desination; 

int board[max+1];
queue<int> Q;

int main(void) 
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> start >> desination;
    fill(board, board+max+1, -1);

    Q.push(start);
    board[start] = 0;

    int sum = 1;

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        for(int nxt: {cur -1, cur +1, cur*2}){
            if(nxt < 0|| nxt > max) continue;
            if(board[nxt] != -1 && board[nxt] < board[cur] + 1) continue;
            if(nxt == desination && board[desination] != -1 && board[desination] == board[cur] + 1)
                sum ++;
            else{
            board[nxt] = board[cur] +1;
            Q.push(nxt);
            }
        }
    }

    cout << board[desination] << "\n" << sum <<"\n";

    return 0;    
}