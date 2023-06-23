// 13549: 숨바꼭질 3
// by Dijkstra
#include <bits/stdc++.h>
#define max 100000

using namespace std;

int start, desination; 
int board[max+1];

struct compare{
    bool operator()(pair<int, int> a, pair<int, int> b){
        return a.second>b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> Q;

int main(void) 
{   
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> start >> desination;
    
    fill(board, board+max+1, max+1);
    board[start] = 0;
    Q.push({start, board[start]});

    while(!Q.empty()){
        auto cur = Q.top(); Q.pop();

        int nxt = cur.first * 2;
        if(nxt <= max && board[nxt] > cur.second ){
            board[nxt] = cur.second;
            Q.push({nxt, board[nxt]});
        }

        for(int nxt: {cur.first -1, cur.first + 1}){
            if(nxt < 0|| nxt > max) continue;
            if(board[nxt] < cur.second+1) continue;

            board[nxt] = cur.second+1;
            Q.push({nxt, board[nxt]});
        }
    }

    cout << board[desination] << "\n";

    return 0;    
}