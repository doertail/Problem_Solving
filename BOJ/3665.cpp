#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define MAX 505
using namespace std;
// 그래프 구현
// vector<int> edge[MAX];
bool graph[MAX][MAX];
// inDegree 표시
int inDegree[MAX];
// ranking 순위
int linearRank[MAX]; 

int main(void){
    FAST_IO
    int T; cin >> T;
    while(T--){
        int N; cin >> N;
        fill(inDegree+1, inDegree+N+1, 0);
        memset(graph, 0, sizeof(graph));

        for(int i=1; i<= N; i++)
            cin >> linearRank[i]; // i등은 num팀
        
        for(int i=1; i<=N; i++){
            for(int j=i+1; j<=N; j++){
                graph[linearRank[i]][linearRank[j]] = true;
                inDegree[linearRank[j]]++;
            }
        }
        // 그래프 구현
        int M; cin >> M;
        while(M--){
            int a, b;
            cin >> a >> b;   
            if(graph[a][b]){
                inDegree[a]++;
                inDegree[b]--;
                graph[a][b] = false;
                graph[b][a] = true;
            }
            else{
                inDegree[a]--;
                inDegree[b]++;
                graph[a][b] = true;
                graph[b][a] = false;
            }
        }
        // init
        queue<int> Q;
        for(int i=1; i<=N; i++){
            if(inDegree[i])
                continue;
            Q.push(i);
            break;
        }
        // 위상정렬
        vector<int> ans;
        while(!Q.empty()){
            int node = Q.front(); Q.pop();
            for(int j=1; j<=N; j++){
                if(graph[node][j]){
                    inDegree[j]--;
                    if(!inDegree[j])
                        Q.push(j);
                }
            }
            ans.push_back(node);
        }

        if(ans.size() != N)
            cout << "IMPOSSIBLE\n";
        else{
            for(int n:ans)
                cout << n << ' ';
            cout << '\n';
        }
    }    
    return 0;
}

// 왜 인접리스트 아니라 인접배열?
// 연결 여부 찾기 쉬움
// 그냥 차수를 내림차순 정렬해도 ㄱㅊ