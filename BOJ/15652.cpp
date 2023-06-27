// 15652: N과 M (4)
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);

int arr[10];

void func(int k);

using namespace std;
int M, N;

int main(void){
    FAST_IO
    cin >> N >> M;

    func(0);
    
    return 0;
}

void func(int k){
    if(k == M){
        for(int i=0; i<10; i++){
            if(arr[i] == 0)
                continue;
            cout << arr[i] <<' ';
        }
        cout <<'\n';
        return;
    }
    else{
        int i = 1;

        if(k != 0)
            i = arr[k-1];

        for(; i<=N; i++){
            arr[k] = i;
            func(k+1);
            arr[k] = 0;
        }
    }
}