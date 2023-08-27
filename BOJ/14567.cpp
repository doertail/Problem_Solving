// Number: Name
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
#define MAX 1002
using namespace std;
vector<int> edge[MAX];
int inDegree[MAX];
queue<int> Q;
int ans[MAX];

int main(void){
    FAST_IO

    int N, M;
    cin >> N >> M;
    while(M--){
        int A, B;
        cin >> A >> B;
        // 그래프 구현
        edge[A].push_back(B);
        inDegree[B]++;
    }
    // init: inDegree가 0인 node를 찾음
    for(int i=1; i<=N; i++){
        if(!inDegree[i]){ // 들어오는 edge가 없을 경우 Q에 추가.
            Q.push(i);
            ans[i] = 1;
        }
    }
    while(!Q.empty()){
        int node = Q.front(); Q.pop();
        for(int num: edge[node]){
            inDegree[num]--;
            if(!inDegree[num]){
                Q.push(num);
                ans[num] = ans[node]+1;
            }
        }
    }
    for(int i=1; i<=N; i++)
        cout << ans[i] << ' ';
        
    return 0;
}