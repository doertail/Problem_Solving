// 15688: 수 정렬하기 5
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int main(void){
    FAST_IO

    int N; cin >> N;
    int arr[1000001];
    for(int i=0; i<N; i++)
        cin >> arr[i];
    
    sort(arr, arr+N, less<int>());

    for(int i=0; i<N; i++)
        cout << arr[i] << "\n";
    
    return 0;
}
