// 11652: 카드
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
using namespace std;

ll MAX_cnt, MAX_num;
ll temp_cnt, temp_num;

vector<ll> vec;
int main(void){
    FAST_IO
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        ll num;
        cin >> num;
        vec.push_back(num);
    }
    sort(vec.begin(), vec.end(), greater<ll>());
    
    temp_num = vec[0];
    for(int i=0; i<N; i++){
        if(temp_num == vec[i])
            temp_cnt++;
        else{
            MAX_cnt = max(temp_cnt, MAX_cnt);
            if(temp_cnt == MAX_cnt)
                MAX_num = vec[i-1];

            temp_cnt = 1;
            temp_num = vec[i];
        }
    }

    MAX_cnt = max(temp_cnt, MAX_cnt);
    if(temp_cnt == MAX_cnt)
        MAX_num = vec.back();

    cout << MAX_num;

    return 0;
}