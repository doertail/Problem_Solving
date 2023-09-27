#include <bits/stdc++.h>
// similar to 1202 
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
using namespace std;
// priority_queue<int> pq; // 내림차순
priority_queue<int, vector<int>, greater<int>> pq; // 오름차순
int main(void){
    FAST_IO
    int N, M, K;
    cin >> N >> M >> K;
    vector<int> vec;
    for(int i=0; i<M; i++){
        int n; cin >> n;
        vec.push_back(n);
    }
    // sort(vec.begin(), vec.end()); // 오름차순
    sort(vec.begin(), vec.end(), greater()); // 내림차순

    int idx = 0;
    while(K--){
        int n;
        cin >> n;
        for(int i=idx; i<M; i++){
            if(vec[i] <= n)
                break;
            pq.push(vec[i]);
            idx = i;
        }
        cout << n << ": " << pq.size() << ' ' << idx << '\n';
        cout << pq.top() << '\n';
        pq.pop();
    }
    
    return 0;
}
// // 2 3 4 5 7 8 9

// 9 8 7 5 4 3 2
// 4 | 5 7 8 9
// 1 | 2 3 4 7 8 9
// 1 | 3 4 7 8 9
// 3 | 4 7 8 9
// 8 | 7 8 9

