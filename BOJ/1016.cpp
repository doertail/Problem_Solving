// 1016: 제곱 ㄴㄴ수
#include <bits/stdc++.h>
#define ll long long 
#define MAX 1000002
using namespace std;

bool answer[MAX];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll Min, Max;
    cin >> Min >> Max;
    ll sum = 0;

    for(ll i=2; i*i<=Max; i++) {  

        ll ref = Min / (i*i);

        if(Min % (i*i) != 0/* 안 나눠 떨어지면 */) ref++;

        while(ref * i*i <= Max) {
            answer[ref * i*i -Min+1] = true;
            ref++;
        }
    }

    for(ll i=1; i<=Max-Min+1; i++) {
        if(answer[i] == false)
            sum++;
    }

    cout << sum << "\n";

    return 0;
}