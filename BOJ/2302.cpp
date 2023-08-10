// 2302 : 극장 좌석
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
int tmp;
int ANS=1;
int main(void){
    FAST_IO
    int N, M; cin >> N >> M;
    int a[41];
    int d[41];
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    d[3] = 3;
    d[4] = 5;
    for(int i=5; i<=41; i++)
        d[i] = d[i-1] + d[i-2];
        
    for(int i=1; i<=M; i++){
        int num;
        cin >> num;
        ANS *= d[(num-tmp)-1];
        tmp = num;
    }
    ANS *= d[N-tmp];
    cout << ANS;
    return 0;
}