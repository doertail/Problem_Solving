// 10814: 나이순 정렬
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);

using namespace std;
bool comp(pair<int, string> a, pair<int, string> b){
    return a.first < b.first;
}
int main(void){
    FAST_IO
    int TC;
    cin >> TC;
    vector<pair<int, string>> vec;

    for(int i=0; i<TC; i++){
        int age; string name;
        cin >> age >> name;
        vec.push_back({age, name});
    }
    
    stable_sort(vec.begin(), vec.end(), comp);
    
    for(pair<int, string> p:vec)
        cout << p.first <<' ' << p.second<<"\n";

    return 0;
}


/*
sort VS stable_sort
sort는 퀵소트, 힙소트 등의 알고리즘을 사용. 순서가 보장 안됨!
stable_sort는 머지소트를 사용하여 순서를 보장해줌.

*/