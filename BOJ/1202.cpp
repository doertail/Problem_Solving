#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
#define MAX 300005
using namespace std;
vector<pair> jwr;
// 무게, 가격
vector<int> bag;
// 무게
priority_queue<int> pq;
ll Ans;

int main(void){
    FAST_IO
    int N, K; cin >> N >> K;
    for(int i=0; i<N; i++){
        int num1, num2;
        cin >> num1 >> num2;
        jwr.push_back({num1, num2});
    }
    
    for(int i=0; i<K; i++){
        int num; cin >> num;
        bag.push_back(num);
    }

    sort(jwr.begin(), jwr.end());
    sort(bag.begin(), bag.end());
    // cout << bag[1] <<'\n';
    int idx = 0;

    for(int i=0; i<K; i++){
        while(idx < N && bag[i] >= jwr[idx].first){
            pq.push(jwr[idx].second);
            // cout << jwr[idx].second << '\n';
            idx++;
        }
        // cout <<"idx: " << idx <<'\n';
        // cout << pq.size() << '\n';
        if(pq.empty())
            continue;
        Ans += pq.top();
        pq.pop();
    }

    cout << Ans;

    return 0;
}
// 그리디.