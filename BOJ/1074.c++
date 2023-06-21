// 1074: Z
#include <bits/stdc++.h>
#define ll long long
#define condition ios_base::sync_with_stdio(0); cin.tie(NULL);

using namespace std;

ll func(int N, ll x, ll y);

int main(void){
    condition
    int N;
    ll r, c;
    cin >> N >> r >> c;

    cout << func(N, r, c)<<"\n";

    return 0;
}

ll func(int N, ll x, ll y){ // x행, y열
    if(N == 1){
        if(x == 0){
            if(y == 0)
                return 0;
            else
                return 1;
        }

        else{
            if(y == 0)
                return 2;
            else
                return 3;
        }
    }

    ll bound = 1 << (N-1);
    ll ref = (1<<(N-1))*(1<<(N-1));

    if(x < bound){
        if(y < bound)
            return func(N-1, x, y);
        else    
            return ref + func(N-1, x, y-bound);
    }   
    else{
        if(y < bound)
            return ref*2 + func(N-1, x-bound, y);
        else
            return ref*3 + func(N-1, x-bound, y-bound);    
    }
}