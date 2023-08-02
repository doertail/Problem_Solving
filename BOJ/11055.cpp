// 11055: 가장 큰 증가하는 부분 수열
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int a[1001];
int d[1001];
int main(void){
    FAST_IO
    
    int N; cin >> N;
    for(int i=0; i<N; i++){
        cin >> a[i];
        d[i] = a[i];
    }
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(a[j] >= a[i])
                continue;
            if(d[i] < d[j] + a[i])
                d[i] = d[j] + a[i];
        }
    }

    cout << *max_element(d, d+N);

    return 0;
}