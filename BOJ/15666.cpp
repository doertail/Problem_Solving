// 15666: N과 M (12)
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

void solution(int i);
vector<int> vec;
vector<int> ptr;
int N, M;

int main(void){
    FAST_IO
    
    cin >> N >> M;

    for(int i=0; i<N; i++){
        int n;
        cin >> n;
        vec.push_back(n);
    }

    sort(vec.begin(), vec.end());

    for(int i=1; i<vec.size(); i++) // 중복 제거
        if(vec[i-1] == vec[i])
            vec.erase(vec.begin() + i);
    if(vec[0] == vec[1])
        vec.erase(vec.begin()+1);

    solution(0);

    return 0;
}

void solution(int i){
    if(ptr.size() == M){
        for(int n:ptr)
            cout << n <<' ';
        cout << '\n';
        return;
    }

    for(int j=i; j<vec.size(); j++){
        ptr.push_back(vec[j]);
        solution(j);
        ptr.pop_back();
    }
}