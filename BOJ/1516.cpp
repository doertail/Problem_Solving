#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define MAX 502
using namespace std;
// 그래프 구현
vector<int> edge[MAX];
// inDegree 표시
int inDegree[MAX];
// while 문에서 돌릴 때 사용
queue<int> Q;
// 정답 모아놓는 배열
int Ref[MAX];
int Time[MAX];
int main(void){
    FAST_IO

    int N;
    cin >> N;

    for(int i=1; i<= N; i++){
        cin >> Ref[i];
        // 그래프 구현
        while(1){
            int node; cin >> node;
            if(node == -1)
                break;
        // A에서 B로 가는 edge 표현
            edge[node].push_back(i);
        // B로 들어오는 edge 개수 표tl
            inDegree[i]++;
        }
    }

    // init: inDegree가 0인 node를 찾음
    for(int i=1; i<=N; i++){
        if(!inDegree[i]){ // 들어오는 edge가 없을 경우 Q에 추가.
            Q.push(i);
            Time[i] = Ref[i];
        }
    }

    // 반복문 돌리면서 toposort
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
    for(int i=1; i<=N; i++)
        cout << Time[i] << '\n';
    // cout << *max_element(Time, Time+N)<< '\n';
    
        
    return 0;
}