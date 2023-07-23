// 7795: 먹을 것인가 먹힐 것인가
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int Aarr[20000];
int Barr[20000];

int main(void){
    FAST_IO

    int T;
    cin >> T;
    while(T--){
        int N, M;
        cin >> N >> M;
        int ANS = 0;
        for(int i=0; i<N; i++)
            cin >> Aarr[i];

        for(int i=0; i<M; i++)
            cin >> Barr[i];
            
        sort(Aarr, Aarr+N);
        sort(Barr, Barr+M);

        for(int i=0; i<N; i++){
            int num = Aarr[i];
            for(int j=0; j<M; j++){
                if(num > Barr[j])
                    ANS++;
                else
                    break;
            }
        }
        
        cout << ANS <<'\n';
    }

    return 0;
}