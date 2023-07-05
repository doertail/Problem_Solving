// 15665: N과 M (11)
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

void solution();
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


    solution();

    return 0;
}

void solution(){
    if(ptr.size() == M){
        for(int n:ptr)
            cout << n <<' ';
        cout << '\n';
        return;
    }

    for(int j=0; j<vec.size(); j++){
        ptr.push_back(vec[j]);
        solution();
        ptr.pop_back();
    }
}