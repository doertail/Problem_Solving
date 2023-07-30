// 6549: 히스토그램에서 가장 큰 직사각형
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define MAX 100001
#define pair pair<ll, int>
#define ll long long
using namespace std;

int main(void){
    FAST_IO
// stack에 {놓이, 해당 높이가 처음 나온 index를 기록함}
    while(1){
        ll ANS = 0;
        int T;
        cin >> T;
        if(T==0)    break;

        stack<pair> S;
        
        for(int i=0; i<T; i++){
            int h;
            cin >> h;
            int idx = i;
            while(!S.empty() && S.top().first >= h){
                ANS = max(ANS, S.top().first * (i-S.top().second));
                idx = S.top().second;
                S.pop();
            }
            S.push({h, idx});
        }
        while(!S.empty()){
            ANS = max(ANS, (T-S.top().second) * S.top().first);
            S.pop();
        }
        cout << ANS << '\n';
    }
    
    return 0;
}