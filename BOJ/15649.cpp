// 15649: N과 M
#include <bits/stdc++.h>

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);

int n, m;
int arr[10];
bool isused[10];

using namespace std;

void func(int k);

int main(void){
    FAST_IO
    
    cin >> n >> m;
    func(0);
    
    return 0;
}

void func(int k){
    if(k == m){
        for(int i=0; i<m; i++)
            cout << arr[i] <<' ';
        cout <<"\n";
        return;
    }

    for(int i=1; i<= n; i++){
        if(!isused[i]){
            arr[k] = i;
            isused[i] = 1;
            func(k+1);
            isused[i] = 0;
        }
    }
}