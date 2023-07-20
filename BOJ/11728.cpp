// 11728: 배열 합치기
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int main(void){
    FAST_IO
    int arr_A[1000001], arr_B[1000001];
    
    int len_a, len_b;
    cin >> len_a >> len_b;

    for(int i=0; i<len_a; i++)
        cin >> arr_A[i];
    for(int i=0; i<len_b; i++)
        cin >> arr_B[i];

    int llen = len_a + len_b;
    int idx_a = 0;
    int idx_b = 0;

    for(int i=0; i<llen; i++){
        if(idx_a >= len_a)
            cout << arr_B[idx_b++] << ' ';
        else if(idx_b >= len_b)
            cout << arr_A[idx_a++] << ' ';

        else if(arr_A[idx_a] < arr_B[idx_b])
            cout << arr_A[idx_a++] <<' ';
        else
            cout << arr_B[idx_b++] <<' ';   
    }
    
    return 0;
}