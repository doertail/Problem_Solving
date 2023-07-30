// 17298: 오큰수
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define MAX 1000001
#define pair pair<int, int>
using namespace std;
int N;
int arr[MAX];
int ans[MAX];
stack<pair> stk; // .first: 수, .second: index

int main(void){
    FAST_IO
    cin >> N;

    for(int i=0; i<N; i++)
        cin >> arr[i];
    
    fill(ans, ans+1000001, -1);

    for(int i=0; i<N; i++){
        // 스택 비어있으면 바로 push
        if(stk.empty()){
            stk.push({arr[i], i});
            continue;
        }

        while(stk.top().first < arr[i]){
            ans[stk.top().second] = arr[i]; // arr[index]에 해당하는 오큰수 발견!
            stk.pop();
            if(stk.empty())
                break;
        }
        stk.push({arr[i],i});
    }

    // 답 출력
    for(int i=0; i<N; i++)   
        cout << ans[i] <<' ';

    return 0;
}