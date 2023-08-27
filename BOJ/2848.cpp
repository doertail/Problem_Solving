#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

vector<int> edge[30];
int inDegree[30];
bool used[30];
int existNum;
int main(void){
    FAST_IO
    string words[105];
    int N; cin >> N; 

    for(int n=0; n<N; n++){
        cin >> words[n];
        for(int i=0; i<words[n].size(); i++){
            if(!used[words[n][i] -'a']){
                existNum++;
                used[words[n][i] -'a'] = true;
            }
        }
    }
    for(int n=0; n<N-1; n++){
        int size = min(words[n].size(), words[n+1].size());
        for(int i=0; i<size; i++){
            if(words[n][i] != words[n+1][i]){
                int from = words[n][i]-'a';
                int to = words[n+1][i] - 'a'; 
                edge[from].push_back(to);
                inDegree[to]++;
                break;
            }
            if(i == size-1 && words[n].size() > words[n+1].size()){
                cout << "!";
                return 0;
            }
        }
    }

    queue<int> Q;
    for(int i=0; i<26; i++){
        if(!inDegree[i] && used[i])
            Q.push(i);
    }
    vector<int> Ans;
    bool flag = 0;
    for(int i=0; i<existNum; i++){
        if(Q.size() > 1){
            flag = 1;
            // break; // 이거 있으면 틀림
        }
        else if(Q.empty()){
            cout << "!";
            return 0;
        }
        int node = Q.front(); Q.pop();
        Ans.push_back(node);
        for(int c: edge[node]){
            if(--inDegree[c] == 0)
                Q.push(c);
        }
    }

    if(flag == 1)
        cout << "?";

    else{
        for(char c: Ans)
            cout << char(c+'a');
    }

    return 0;
}