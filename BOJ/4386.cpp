#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
#define tuple tuple<int, int, int>
#define MAX 100005
using namespace std;
struct Comp{
    bool operator()(const tuple& a, const tuple& b){
        return get<0>(a) > get<0>(b);
    }
};
priority_queue<tuple, vector<tuple>, Comp> pq;
vector<pair> g[MAX];
tuple m[MAX];
int EdgeNum;
ll Ans;
bool visited[MAX];
int dis(const tuple& a, const tuple& b){
    int x1, y1, z1, x2, y2, z2;
    tie(x1, y1, z1) = a;
    tie(x2, y2, z2) = b;
    return min({abs(x2-x1), abs(y2-y1), abs(z2-z1)});
}
int main(void){
    FAST_IO
    int V;
    cin >> V;
    // 간선 입력
    for(int i=0; i<V; i++){
        int x, y, z;
        cin >> x >> y >> z;
        m[i] = {x, y, z};
    }
    sort(m, m+V);
    
    for(int i=0; i<V-1; i++){
        for(int j=i+1; j<V; j++){
            int val = dis(m[i], m[j]);
            g[i].push_back({j, val});
            g[j].push_back({i, val});
        }
    }
    // init
    visited[1] = true;
    for(pair p: g[1]){
        int n2, v;
        tie(n2, v) = p;
        pq.push({v, 1, n2});
    }

    while(EdgeNum != V-1){
        int v, n1, n2;
        tie(v, n1, n2) = pq.top();
        pq.pop();
        if(visited[n2])
            continue;
        visited[n2] = true;
        for(pair p: g[n2]){
            int n; int v;
            tie(n, v) = p;
            if(visited[n])
                continue;
            pq.push({v, n2, n});
        }
        EdgeNum++;
        Ans += v;
    }
    cout << fixed;
    cout.precision(2);
    cout << Ans ;

    return 0;
}