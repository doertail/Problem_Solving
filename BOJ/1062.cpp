// 1062: 가르침
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
string w[51];

int main(void){
    FAST_IO
    int num = 1<<('a'-'a') | 1<<('n'-'a') | 1<<('t'-'a') | 1<<('i'-'a') | 1<<('c'-'a');
    int MAX=0, arr[26], N, K; 
    cin >> N >> K;    

    for(int i=0; i<N; i++)
        cin >> w[i];
    
    fill(arr, arr+26, 1);
    fill(arr, arr+K, 0);

    do{
        int ref = 0, tmp = 0;
        for(int i=0; i<26; i++){
            if(arr[i]==0)
                ref = ref|(1<<i);
        }
        if((ref & num) != num)
            continue;

        for(int i=0; i<N; i++){
            bool flag = true;
            
            for(int j=4; j<w[i].length()-4; j++){
                if((ref & (1<<(w[i][j]-'a'))) != (1<<(w[i][j]-'a'))){
                    flag = false;
                    break;
                }
            }
            if(flag) tmp++;
        }
        MAX = max(tmp, MAX);
    }while(next_permutation(arr, arr+26));
    
    cout << MAX;

    return 0;
}