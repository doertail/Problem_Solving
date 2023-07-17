// 11003: 최솟값 찾기
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define _pair pair<int, int>
using namespace std;
struct comp{
	bool operator()(_pair a, _pair b){
		return a.first>b.first;
	}
};

int main(void){
    FAST_IO
    
    int N, L;
    cin >> N >> L;

    vector<int> vec;
    
    for(int i=0; i<N; i++){
        int num; cin >> num;
        vec.push_back(num);
    }
    priority_queue<_pair, vector<_pair>, comp> pq;
    if(L==1){
        for(int n: vec)
            cout << n <<' ';
        return 0;
    }
    vec.insert(vec.begin(), 0);
    pq.push({vec[1],1});
    cout << vec[1] <<' ';
        
    for(int i=2; i<= N; i++){
        while(pq.top().second < i-L+1)
            pq.pop();
        pq.push({vec[i], i});

        cout << pq.top().first <<' ';
    }

    return 0;
}
