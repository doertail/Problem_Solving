// 6198: 옥상 정원 꾸미기
#include <bits/stdc++.h>
#define pair pair<int, int>
#define ll long long
#define MAX 1000000000
using namespace std;

pair arr[80002]; // .first: 높이, .second:
ll sum;

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N;
    cin >> N;

    for(int i=1; i<=N; i++) {
        cin >> arr[i].first;
        arr[i].second = MAX;
    }
    
    arr[N+1].first = MAX;
    arr[N+1].second = N+1;

    for(int i=N; i>0; i--){ // 맨 뒤부터 탐색
        int j = i+1; 

        while(j != N+1){
            if(arr[i].first <= arr[j].first) // 왼쪽(기준 i 빌딩의 높이)가 더 작아!
                break;

            else
                j = arr[j].second;
        }
        arr[i].second = j;
        sum += arr[i].second-i-1;
    }

    cout << sum << "\n";

    return 0;
}