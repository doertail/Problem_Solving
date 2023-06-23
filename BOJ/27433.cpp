// 27433: 팩토리얼 2
#include <bits/stdc++.h>
#define condition ios_base::sync_with_stdio(0); cin.tie(NULL);

using namespace std;

long long solution(int N);

int main(void){
    condition
    int N;
    cin >> N;
    
    cout << solution(N) <<"\n";
    return 0;
}

long long solution(int N){
    if(N==0)
        return 1;
    
    return N * solution(N-1);
}
