#include <bits/stdc++.h>
#define max 200000

using namespace std;
int start, desination; 
int board[max+2];

int main(void) {   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> start >> desination;

    deque<int> dq;
    fill(board, board+max, -1);
    board[start] = 0;
    dq.push_back(start);

    while(!dq.empty()){
        int cur = dq.front(); dq.pop_front();
        if(cur * 2 < max && board[cur * 2] == -1){
            board[cur * 2] = board[cur];
            dq.push_front(cur * 2);
        }
        for(int nxt: {cur - 1, cur + 1}){
            if(nxt < 0 || nxt > max) continue;
            if(board[nxt] != -1 )    continue;
            board[nxt] = board[cur]+1;
            dq.push_back(nxt);
        }    
    }

    cout << board[desination];

    return 0;    
}