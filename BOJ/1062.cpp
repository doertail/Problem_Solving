// 1062: 가르침
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
string w[51];
bool is_readable(string str, int num);
int main(void){
    FAST_IO
    int N, K, ANS=0, arr[26], num, tmp; 
    // ref: a, c, i, n, t를 갖고있음.
    int ref = 1<<('a'-'a') | 1<<('c'-'a') | 1<<('i'-'a') | 1<<('n'-'a') | 1<<('t'-'a');
    
    cin >> N >> K;    

    for(int i=0; i<N; i++)
        cin >> w[i];
    
    fill(arr, arr+26, 1);
    fill(arr, arr+K, 0);

    do{
        num = 0, tmp = 0;
        for(int i=0; i<26; i++){
            if(arr[i] == 0)
                num = num|(1<<i); // arr에서 0인거를 비트로 인식하고, num에 기록.
        }

        if((num & ref) != ref) // num이 a, c, i, n, t를 가지고 있는지를 체크. 없으면 다음!
            continue;

        for(int i=0; i<N; i++){
            if(is_readable(w[i], num))
                tmp++;
        }
        ANS = max(tmp, ANS);
    }while(next_permutation(arr, arr+26));
    
    cout << ANS;

    return 0;
}
// 단어 읽을 수 있는지 체크.
bool is_readable(string str, int num){
    for(char c: str){
        if((num & (1<<(c-'a'))) != (1<<(c-'a'))) // string에 있는 문자가 num에 없음.
            return false;
    }
    return true;
}
