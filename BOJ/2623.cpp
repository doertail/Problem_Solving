// Number: Name
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
#define MAX 1002
using namespace std;

vector<int> edge[MAX];
int inDegree[MAX];
vector<int> ans;
queue<int> Q;

int main(void){
    FAST_IO
    int N, M;
    cin >> N >> M;

    while(M--){
        int numOfSinger;
        cin >> numOfSinger;
        vector<int> tmparr;
        while(numOfSinger--){
            int n;
            cin >> n;
            tmparr.push_back(n);
        }
        numOfSinger = tmparr.size();
        for(int i=0; i<numOfSinger-1; i++){
            for(int j=i+1; j<numOfSinger; j++){
                edge[tmparr[i]].push_back(tmparr[j]);
                inDegree[tmparr[j]]++;
            }
        }
    }

    // topo sort
    // init
    for(int i=1; i<=N; i++){
        if(!inDegree[i])
            Q.push(i);
    }

    while(!Q.empty()){
        int node = Q.front(); Q.pop();
        ans.push_back(node);
        for(int num: edge[node]){
            inDegree[num]--;
            if(!inDegree[num])
                Q.push(num);
        }
    }   

    if(ans.size() == N){
        for(int n:ans){
            cout << n <<'\n';
        }
    }
    else
        cout << 0;
    return 0;
}