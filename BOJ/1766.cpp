// Number: Name
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
#define MAX 32002
using namespace std;

// vector<int> inDegree[MAX];
vector<int> edge[MAX]; // 엣지 저장
int inDegree[MAX];
priority_queue<int, vector<int>, greater<int>> pq;
// vector<int> ans;
bool finished[MAX];
int main(void){
    FAST_IO
    int N, M;
    cin >> N >> M;
    // 그래프 기록
    while(M--){
        // A번 문제를 B번 문제보다 먼저 풀어야함
        int A, B;
        cin >> A >> B;
        edge[A].push_back(B);
        // inDegree[B].push_back(A);
        inDegree[B]++;
    }
    int idx = 1;
    for(int i=1; i<=N; i++){
        if(finished[i] || inDegree[i])
            continue;
        // finished[i] = true;
        // cout<< "없는 애들: " << i << '\n';
        pq.push(i);
    }

    while(1){
        // cout << idx++ << "번째 루프\n";
        // for(int i=1; i<=N; i++)
        //     cout << i << "번째 " << inDegree[i] <<'\n';
        if(pq.empty())
            return 0;
        // cout << pq.top();
        int node = pq.top(); pq.pop();
        // finished[node] = true;
        // ans.push_back(node);
    cout << node << ' ';
        for(int outNode: edge[node]){
            inDegree[outNode]--;
            if(!inDegree[outNode])
                pq.push(outNode);
        }
    }


    return 0;
}