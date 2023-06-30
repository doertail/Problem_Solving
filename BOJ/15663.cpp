// 15663: N과 M (9)
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
        for(int i=0; i<M; i++)
            cout << arr[i] <<' ';
        
        cout <<"\n";
        reverse(arr + M, arr+N); // 중요!!
    }while(next_permutation(arr, arr+N));

    return 0;
}