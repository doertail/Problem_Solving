// 14889: 스타트와 링크
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

#define DEBUG
#ifdef ONLINE_JUDGE
#endif

int board[20][20], arr[20], N;
int ANS = (1<<30);
int comb0[20];
vector<int> comb1;
vector<int> comb2;
int solve(vector<int>);
int main(void){
    FAST_IO
    cin >> N;
    
    for(int i=0; i<N; i++)
        for(int j=0; j<N; j++)
            cin >> board[i][j];

    for(int i=0; i<N; i++)
        arr[i] = i;

    fill(comb0, comb0+N/2, 0);
    fill(comb0+N/2, comb0+N, 1);

    do{
        comb1.clear(); comb2.clear();
        for(int i=0; i<N; i++){
            if(comb0[i])
                comb1.push_back(arr[i]);
            else
                comb2.push_back(arr[i]);
        }   
        ANS = min(ANS, abs(solve(comb1)-solve(comb2)));
    }while(next_permutation(comb0, comb0+N)); 
    
    cout << ANS;

    return 0;
}


int solve(vector<int> vec){
    int ret=0;
    for(int i=0; i<N/2-1; i++){
        for(int j=i+1; j<N/2; j++){
            ret += board[arr[vec[i]]][arr[vec[j]]];
            ret += board[arr[vec[j]]][arr[vec[i]]];
        }
    }
    return ret;
}

