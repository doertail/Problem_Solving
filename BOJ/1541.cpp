// 위상 정렬 가구현
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define MAX 10005
using namespace std;

// 그래프 구현
vector<int> edge[MAX];
// inDegree 표시
int inDegree[MAX];
// while 문에서 돌릴 때 사용
queue<int> Q;
// 정답 모아놓는 배열
int ans[MAX];

int main(void){
    FAST_IO

    int N, M;
    cin >> N >> M;
    while(M--){
        
    }

    while(M--){
        int A, B;
        cin >> A >> B;
        // 그래프 구현
        // A에서 B로 가는 edge 표현
        edge[A].push_back(B);
        // B로 들어오는 edge 개수 표새
        inDegree[B]++;
    }

    // init: inDegree가 0인 node를 찾음
    for(int i=1; i<=N; i++){
        if(!inDegree[i]){ // 들어오는 edge가 없을 경우 Q에 추가.
            Q.push(i);
            ans[i] = 1;
        }
    }
    // 반복문 돌리면서 toposort
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

    /* dp 활용한 topo sort
    while(!Q.empty()){
        int node = Q.front(); Q.pop();
        for(int num: edge[node]){
            inDegree[num]--;
            Time[num] = max(Time[num], Ref[num]+Time[node]);
            if(!inDegree[num]){
                Q.push(num);
            }
        }
    }
    */
    for(int i=1; i<=N; i++)
        cout << ans[i] << ' ';
        
    return 0;
}
