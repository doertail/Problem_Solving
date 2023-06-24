// 2447: 별 찍기 10
#include <bits/stdc++.h>

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);

#ifdef ONLINE_JUDGE
#define DEBUG
#endif

using namespace std;

void func(int N);

int main(void){
    FAST_IO
    
    int k;
    cin >> k;

    func(k);

    
    return 0;
}

void func(int N){
    if(N == 1){
        cout << "*";
        return;
    }

    for(int i=0; i<N; i++){
        
    }
}