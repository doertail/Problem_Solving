// 12913: 숨바꼭질 4
#include <bits/stdc++.h>
#define max 100000

using namespace std;
int start, desination; 

int board[max+1];
queue<int> Q;
stack<int> S;

int main(void) 
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> start >> desination;
    fill(board, board+max+1, -2);

    Q.push(start);
    board[start] = 0;

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();

        for(int nxt: {cur -1, cur +1, cur*2}){
            if(nxt < 0|| nxt > max) continue;

            if(board[nxt] != -2) continue;

            board[nxt] = board[cur] +1;
            Q.push(nxt);
        }
    }

    cout << board[desination] << "\n";

    // Backtracking
    Q.push(desination);
    S.push(desination);

    while(!Q.empty()){
        int cur = Q.front(); Q.pop();
        bool is_pushed = false;

        for(int nxt: {cur -1, cur +1}){
            if(is_pushed) continue;

            if(nxt < 0|| nxt > max) continue;

            if(board[nxt] != board[cur] -1) continue;

            Q.push(nxt);
            S.push(nxt);
            is_pushed = true;
        }
        if(cur % 2 == 0){
            if(is_pushed) continue;
            int nxt = cur /2;
            if(nxt < 0|| nxt > max) continue;

            if(board[nxt] != board[cur] - 1) continue;

            Q.push(nxt);
            S.push(nxt);
        }
    }

    while(!S.empty()){
        cout << S.top() <<' ';
        S.pop();
    }
    return 0;    
}
