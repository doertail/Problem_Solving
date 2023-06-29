// 12852: 1로 만들기 2
#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);

queue<pair<int, int>> Q;
int arr[3000001];

int main(void){
    FAST_IO
    int N;
    cin >> N;

    Q.push({1, 0});
    arr[1] = 0;
    if(N == 1){
        cout << 0 <<"\n";
        cout << 1 <<"\n";
        return 0;
    }
    while(arr[N] == 0){
        pair<int, int> frt = Q.front(); Q.pop();
        if(frt.first >= N) continue;

        if(!arr[frt.first+1]){
            arr[frt.first+1] = frt.second+1;
            Q.push({frt.first+1, frt.second+1});
        }
        if(!arr[frt.first*2]){
            arr[frt.first*2] = frt.second+1;
            Q.push({frt.first*2, frt.second+1});
        }
        if(!arr[frt.first*3]){
            arr[frt.first*3] = frt.second+1;
            Q.push({frt.first*3, frt.second+1});
        }
    }
    cout << arr[N]<<"\n";
    vector<int> vec;
    int temp = N;
    while(temp != 1){
        vec.push_back(temp);

        if(arr[temp-1] == arr[temp] -1)
            temp = temp-1;
        else if(temp%2 == 0 && arr[temp/2] == arr[temp]-1)
            temp = temp/2;
        else if(arr[temp/3] == arr[temp]-1)
            temp = temp/3;
    }
    
    for(int n:vec){
        cout << n <<' ';
    }
    cout << 1 <<"\n";
    
    return 0;
}
