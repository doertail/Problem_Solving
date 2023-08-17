// 1799: 비숍
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
using namespace std;
vector<pair> b[2][20]; // 짝홀 나누는 [2], i+j에 해당하는 [20]
int N;
void DFS(int idx, int ref, int num); // idx: 짝인지 홀인지, ref: i+j어디에 해당하는지, num: 몇 번쨰?
int ANS[2];
bool ymx[21];
int main(void){
    FAST_IO
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int num;
            cin >> num;
            // cin >> num;
            if(num){
                if((i+j)%2==0)
                    b[0][i+j].push_back({i, j});
                else
                    b[1][i+j].push_back({i, j});
            }
        }
    }
    fill(ymx, ymx+21, false);
    DFS(0, 0, 0);
    fill(ymx, ymx+21, false);
    DFS(1, 0, 0);
    cout << ANS[0] + ANS[1];
    return 0;
}
void DFS(int idx, int ref, int num){
    if(ref >= 2 * N)
        return;

    for(pair p: b[idx][ref]){
        int x, y;
        tie(x, y) = p;
        if(ymx[y-x+10])
            continue;
        ymx[y-x+10] = true;
        ANS[idx] = max(num+1, ANS[idx]);
        DFS(idx, ref+1, num+1);
        ymx[y-x+10] = false;
    }

    DFS(idx, ref+1, num);

    return;
}