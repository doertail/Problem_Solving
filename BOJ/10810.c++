// 10810: 공 넣기
#include <bits/stdc++.h>
#define condition ios_base::sync_with_stdio(0); cin.tie(NULL);

using namespace std;
int arr[101];

int main(void){
    condition
    int N, M;
    cin >> N >> M;
    int i, j, k;

    while(M--){
        cin >> i >> j >> k;
        for(int n = i; n <= j; n++)
            arr[n] = k;
    }

    for(int i=1; i<= N; i++)
        cout << arr[i] <<' ';

    cout <<"\n";

    return 0;
}