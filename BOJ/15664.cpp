// 15664: N과 M (10)
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int main(void){
    FAST_IO
    
    int N, M;
    cin >> N >> M;

    int *arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];

    sort(arr, arr+N);

    do{
        int cnt = arr[0];
        bool flag = true;
        for(int i=0; i<M; i++){
            if(cnt > arr[i]) flag = false;
            cnt = arr[i];
        }
        if(flag){
            for(int i=0; i<M; i++)
                cout << arr[i] <<' ';
            
            cout <<"\n";
        }
        reverse(arr + M, arr+N);
    }while(next_permutation(arr, arr+N));

    return 0;
}