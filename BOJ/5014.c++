// 5014: 스타트링크
#include <bits/stdc++.h>

using namespace std;

int F, S, G, U, D;

int board[10000001];

int temp;
priority_queue<int, vector<int>, greater<int>> pq;
queue<int> que;

void BFS();

int main(void) 
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    fill_n(board, 10000001 , -1);

    cin >> F >> S >> G >> U >> D;
    
    int* arr = new int[2];

    arr[0] = U;
    arr[1] = -1 * D;

    if(S == G) {
        cout << 0 <<"\n";
        return 0;
    }

    que.push(S);
    board[S] = 0;

    while(!que.empty()) {
        int temp = que.front(); que.pop();
        for(int i = 0; i < 2; i++) {
            int x = temp + arr[i]; 

            if(x == G) {
                cout <<  board[temp] + 1 << "\n";
                return 0;
            }
                
            if(x > F || x < 1) continue;

            if(board[x] != -1) continue;
            
            que.push(x);
            board[x] = board[temp] + 1;
        }
    }   

    cout << "use the stairs\n";

    return 0;   
}


    