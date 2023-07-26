// 10825: 국영수
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define tuple tuple<string, int, int, int>
using namespace std;

bool comp(const tuple& t1, const tuple& t2){
    if(get<1>(t1) > get<1>(t2))
        return true;
    else if(get<1>(t1) < get<1>(t2))
        return false;
    else{
        if(get<2>(t1) < get<2>(t2))
            return true;
        else if(get<2>(t1) > get<2>(t2))
            return false;
        else{
            if(get<3>(t1) > get<3>(t2))
                return true;
            else if(get<3>(t1) < get<3>(t2))
                return false;
            else{
                return get<0>(t1) < get<0>(t2);
            }
        }
    }
}

int main(void){
    FAST_IO
    int N;
    cin >> N;
    vector<tuple> vec;
    while(N--){
        string str;
        int n1, n2, n3;
        cin >> str >> n1 >> n2 >> n3;
        vec.push_back({str, n1, n2, n3});
    }
    sort(vec.begin(), vec.end(), comp);

    for(tuple t:vec)
        cout << get<0>(t) << '\n';
    
    return 0;
}