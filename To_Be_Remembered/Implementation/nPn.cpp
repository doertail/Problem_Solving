#include<iostream>
#include<algorithm>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);

using namespace std;

int main(void){
    FAST_IO
    
    int N;
    cin >> N;

    int *arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];

    sort(arr, arr+N);

    do{
        for(int i=0; i<N; i++)
            cout << arr[i] <<' ';
        cout <<"\n";
    }while(next_permutation(arr, arr+N));

    return 0;
}

// 참고: https://ansohxxn.github.io/algorithm/permutation/
// BOJ 15654: N과 N (6)