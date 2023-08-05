// 14002: 가장 긴 증가하는 부분 수열 4
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int a[1001];
int d[1001];
int id[1001];
vector<int> vec;
int main(void){
    FAST_IO
    int idx;
    int n; cin >> n;
    fill(d, d+n, 1);
    fill(id, id+n, -1);

    for(int i=0; i<n; i++)
        cin >> a[i];

    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(a[j] >= a[i])
                continue;
            if(d[i] < d[j] + 1){
                d[i] = d[j] + 1;
                id[i] = j;
            }
        }
    }

    int num = *max_element(d, d+n);
    cout << num << '\n';
    
    for(int i=n-1; i>=0; i--){
        if(num != d[i])
            continue;
        idx = i;
        break;
    }

    while(1){
        vec.insert(vec.begin(), a[idx]);
        if(id[idx] == -1)
            break;
        idx = id[idx];
    }

    for(int n:vec)
        cout << n <<' ';    

    return 0;
}