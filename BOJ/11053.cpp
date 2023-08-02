// 11055: 가장  증가하는 부분 수열
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int a[1001];
int d[1001];
int main(void){
    FAST_IO
    fill(d, d+1001, 1);

    int n; cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<n; i++){
        int num = a[i];
        for(int j=0; j<i; j++){
            if(num <= a[j])
                continue;
            if(d[i] < d[j] + 1)
                d[i] = d[j] + 1;
        }
    }
    cout << *max_element(d, d+n);

    return 0;
}