// 11054: 가장 긴 바이토닉 부분 수열
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int a[1001];
int d1[1001];
int d2[1001];

int main(void){
    FAST_IO
    int N; cin >> N;
    fill(d1, d1+1001, 1);
    fill(d2, d2+1001, 1); 
    for(int i=0; i<N; i++)
        cin >> a[i];
    for(int i=0; i<N; i++){
        for(int j=0; j<i; j++){
            if(a[j] >= a[i])
                continue;
            if(d1[i] < d1[j]+1)
                d1[i] = d1[j] + 1;
        }
    }
    for(int i=N-1; i>=0; i--){
        for(int j=N-1; j>i; j--){
            if(a[i] <= a[j])
                continue;
            if(d2[i] < d2[j]+1)
                d2[i] = d2[j] + 1;
        }
    }
    int MAX = 0;
    for(int i=0; i<N; i++)
        MAX = max(d1[i]+d2[i], MAX);
    cout << MAX -1 <<'\n';

    return 0;
}