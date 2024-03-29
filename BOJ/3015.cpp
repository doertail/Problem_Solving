// 3015: 오아시스 재결합
#include <bits/stdc++.h>
#define ll long long
#define pair pair<ll, ll>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

ll ans;
stack<pair> stk;
vector<ll> vec(500001);

int main(void){
    FAST_IO
    
    int N;
    cin >> N;

    for(int i=0; i<N; i++)
        cin >> vec[i];

    for(int i=0; i<N; i++){
        ll cnt = 0;
        
        while(!stk.empty() && stk.top().first < vec[i]){
            // 스택이 채워져있고, 탑의 원소가 vec[i]보다 작다면 pop
            stk.pop();
            cnt++;
        }

        if(!stk.empty() && stk.top().first == vec[i]){
            if(stk.size() > stk.top().second)
                ans += cnt + stk.top().second + 1;
            else
                ans += cnt + stk.top().second;
        }
        else if(!stk.empty() && stk.top().first != vec[i])
            ans += cnt + 1;
        else
            ans += cnt;


        if(!stk.empty() && stk.top().first == vec[i])
            stk.push({vec[i], stk.top().second+1});
        else
            stk.push({vec[i], 1});
    }

    cout << ans <<'\n';

    return 0;
}