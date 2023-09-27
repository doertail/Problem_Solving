#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
#define tuple tuple<int, int, int>
#define MAX 100005
using namespace std;

//
// record node's parnet idx
int parent[MAX];
// Find the parent node
int findPrt(int idx){
    if(parent[idx] == idx)
        return idx;

    parent[idx] = findPrt(parent[idx]);

    return parent[idx];
}
// make one set
void unite(int a, int b){
    int roota = findPrt(a);
    int rootb = findPrt(b);

    if(roota < rootb)
        parent[rootb] = roota;
    else
        parent[roota] = rootb;
}
// do have idx a, b same parents?
bool isSame(int a, int b){
    return findPrt(a) == findPrt(b);
}
//

vector<pair> arrx;
vector<pair> arry;
vector<pair> arrz;
vector<tuple> dist; // distance, idxa, idxb
int Ans;
int numOfEdge;
int main(void){
    FAST_IO
    int V;
    cin >> V;
    for(int i=0; i<V; i++){
        int x, y, z;
        cin >> x >> y >> z;
        arrx.push_back({x, i});
        arry.push_back({y, i});
        arrz.push_back({z, i});
        parent[i] = i;
    }
    sort(arrx.begin(), arrx.end());
    sort(arry.begin(), arry.end());
    sort(arrz.begin(), arrz.end());
    for(int i=0; i<V-1; i++){
        dist.push_back({abs(arrx[i].first-arrx[i+1].first), arrx[i].second, arrx[i+1].second});
        dist.push_back({abs(arry[i].first-arry[i+1].first), arry[i].second, arry[i+1].second});
        dist.push_back({abs(arrz[i].first-arrz[i+1].first), arrz[i].second, arrz[i+1].second});
    }
    sort(dist.begin(), dist.end());
    // int idx=0;
    for(tuple t:dist){
        int cost, a, b;
        tie(cost, a, b) = t;
        // cout << a << b << "\n";
        if(isSame(a, b))
            continue;
        // cout << idx++ <<'\n';
        
        unite(a, b);
        Ans += cost;
        numOfEdge++;
        if(numOfEdge == V-1)
            break;
    }
    cout << Ans;
    return 0;
}