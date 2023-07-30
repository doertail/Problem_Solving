// 1725: 히스토그램
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define MAX 100001
#define ll long long
#define pair pair<ll, ll>
ll Ans;
using namespace std;
stack<pair> stk;
int main(void){
    FAST_IO
    int N;
    cin >> N;

    for(int i=0; i<N; i++){
        ll h;
        cin >> h;
        int idx = i;
        if(stk.empty()){
            stk.push({h, i});
            continue;
        }
        while(!stk.empty() && stk.top().first >= h){
            Ans = max(Ans, stk.top().first * (i-stk.top().second));
            idx = stk.top().second;   
            stk.pop();
        }
        stk.push({h, idx});
    }
    while(!stk.empty()){
        Ans = max(Ans, stk.top().first * (N-stk.top().second));
        stk.pop();
    }

    cout << Ans << '\n';

    return 0;
}