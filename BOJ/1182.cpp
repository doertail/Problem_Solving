// 1182: 부분수열의 합
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);

using namespace std;

int N, S;
int num, sum;
int arr[40];

void solution(int i, bool flag);

int main(void){
    FAST_IO
    cin >> N >> S;
    for(int i=0; i<N; i++)
        cin >> arr[i];

    solution(0, true);
    solution(0, false);

    cout << num <<"\n";

    return 0;
}

void solution(int i, bool flag){
    if(i == N)
        return;

    if(flag){
        sum += arr[i];
        if(sum == S)
            num++;
        
        solution(i+1, true);
        solution(i+1, false);    
        sum -= arr[i];
        return;
    }
    else{
        solution(i+1, true);
        solution(i+1, false);
        return;
    }
        
}
