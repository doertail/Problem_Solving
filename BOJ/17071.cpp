// 17071: 숨바꼭질 5
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define MAX 500000
using namespace std;

int dx[3] = {-1, 1, 2};
int m_board[MAX+1][2]; // 짝수, 홀수
int d_board[MAX+1];
int Time = 0;

int main(void){
    FAST_IO
    for(int i=0; i<MAX+2; i++){
        m_board[i][0] = -1;
        m_board[i][1] = -1;
    }
    fill(d_board, d_board+MAX+1, -1);

    int N, K; // N: subin, K: dongsaeng
    cin >> N >> K;

    if(N == K){
        cout << 0 <<'\n';
        return 0;
    }

    queue<pair<int, int>> m_Q; // 거리, 시간
    m_Q.push({N, 0});
    m_board[N][0] = 0;

    queue<int> d_Q;
    d_Q.push(K);
    d_board[K] = 0;

    while(!m_Q.empty() && !d_Q.empty()){
        pair m_tmp = m_Q.front(); m_Q.pop();
        if(Time%2 == m_tmp.second%2){
            Time++;
            int d_tmp = d_Q.front(); d_Q.pop(); 
            int nd_tmp = d_tmp + (Time * dx[1]);
            if(nd_tmp <= MAX){
                d_board[nd_tmp] = Time;
                if(m_board[nd_tmp][Time%2] <= d_board[nd_tmp] && m_board[nd_tmp][Time%2]%2 == d_board[nd_tmp]%2){
                    cout<< Time <<'\n';
                    return 0;
                }
                d_Q.push(nd_tmp);
            }
        }
        int bin = Time%2;

        for(int i=0; i<2; i++){
            int nm_tmp = m_tmp.first + dx[i];
            if(nm_tmp >= 0 && nm_tmp <= MAX){
                if(m_board[nm_tmp][bin] != -1)
                    continue;
                m_board[nm_tmp][bin] = Time;
                if(m_board[nm_tmp][bin] == d_board[nm_tmp]){
                    cout<< Time <<'\n';
                    return 0;
                }
                m_Q.push({nm_tmp, Time});
            }
        }
        int nm_tmp = m_tmp.first * dx[2];
        if(nm_tmp > 0 && nm_tmp <= MAX){
            if(m_board[nm_tmp][bin] != -1)
                    continue;
            m_board[nm_tmp][bin] = Time;
            if(m_board[nm_tmp][bin]== d_board[nm_tmp]){
                cout<< Time <<'\n';
                return 0;
            }
            m_Q.push({nm_tmp, Time});
        }        
    }
    cout << -1 <<"\n";

    return 0;
}

/*
앞으로 갔다가 뒤로 갈 수 있을 때 방문처리에 대한 문제. 
이 경우에는 제자리로 돌아올 수 있다는건데, 일반 BFS와 이 점에서 차이를 보인다.
계속 Queue에 넣다가는 메모리가 터지니, 짝수 홀수로 분리하여 사고하는 방법이 필요하다.
*/