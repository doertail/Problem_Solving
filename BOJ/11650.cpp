// 11650: 좌표 정렬하기
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
using namespace std;

bool cmp(const pair& a, const pair& b){
    if(a.first < b.first)
        return true;
    else if(a.first > b.first)
        return false;
    else
        return a.second < b.second;
}
int main(void){
    FAST_IO

    int N;
    cin >> N;

    vector<pair> vec;

    while(N--){
        int x, y;
        cin >> x >> y;
        vec.push_back({x, y});
    }

    sort(vec.begin(), vec.end(), cmp);
    
    for(pair p: vec)
        cout << p.first << ' ' << p.second <<'\n';

    return 0;
}