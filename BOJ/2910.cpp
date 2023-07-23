// 2910: 빈도 정렬
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
#define tuple tuple<int, int, int>
using namespace std;

vector<pair> vec1;
vector<tuple> vec2;

bool comp(const tuple& a, const tuple& b){
    if(get<2>(a) > get<2>(b))
        return true;
    else if(get<2>(a) < get<2>(b))
        return false;
    else{
        if(get<1>(a) < get<1>(b))
            return true;
        else 
            return false;
    }
}

int main(void){
    FAST_IO
    int N;
    int C;
    cin >> N >> C;
    
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        vec1.push_back({num, i});
    }

    stable_sort(vec1.begin(), vec1.end());

    int temp = vec1[0].first;
    int cnt = 1;
    int num = vec1[0].second;
    for(int i=1; i<N; i++){
        if(temp == vec1[i].first){
            cnt++;
        }
        else{
            vec2.push_back({temp, num, cnt});
            num = vec1[i].second;
            cnt = 1;
            temp = vec1[i].first;
        }
    }
    vec2.push_back({vec1.back().first, num, cnt});

    
    
    sort(vec2.begin(), vec2.end(), comp);

    for(int i=0; i<vec2.size(); i++){
        for(int j=0; j < get<2>(vec2[i]); j++)
            cout << get<0>(vec2[i]) <<' ';
    }

    return 0;
}