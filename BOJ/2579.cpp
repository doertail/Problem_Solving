// 2579: 계단 오르기 
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

#define DEBUG
#ifdef ONLINE_JUDGE
#endif

int d[301][3];

int main(void){
    FAST_IO
    int N;
    cin >> N;

    vector<int> S;
    S.push_back(0);
    while(N--){
        int score;
        cin >> score;
        S.push_back(score);
    }
    N = S.size()-1;
    d[1][1] = S[1]; d[1][2] = 0;
    d[2][1] = S[2]; d[2][2] = S[1]+S[2];

    for(int k=3; k<=N; k++){
        d[k][1] = max(d[k-2][1], d[k-2][2]) + S[k];
        d[k][2] = d[k-1][1] + S[k];
    }
    cout << max(d[N][1], d[N][2]);

    return 0;
}