// 16991: 외판원 순회 3
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define INF 96544321
#define pair pair<int, int>
using namespace std;
double a[18][18];
double d[18][1<<16]; // 현재 노드 번호와 방문 여부
double Min = INT_MAX;
int refBit, n;
vector<pair> vec;
// void TSP(int curNode, int curBit);
double TSP(int curNode, int curBit);
int main(void){
    FAST_IO
    cout << setprecision(20);
    cin >> n;
    refBit = (1<<n)-1;

    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        vec.push_back({x, y});
    }

    for(int i=0; i<n-1; i++){
        int x = vec[i].first;
        int y = vec[i].second;
        for(int j=i+1; j<n; j++){
            int nx = vec[j].first;
            int ny = vec[j].second;
            double len = sqrt((nx-x)*(nx-x) + (ny-y)*(ny-y));
            a[i][j] = len;
            a[j][i] = len;
        }
    }

    for(int i=0; i<n; i++)
        fill(d[i], d[i]+(1<<n), -1);


    // cout << Min+1;
    cout << TSP(0, 1);

    return 0;
}

// void TSP(int curNode, int curBit){
//         // cout << curNode << ' ' <<  curBit <<'\n';
//         // cout << d[curNode][curBit] +1 << "\n\n";
//     if(curBit == refBit){
//         if(a[curNode][0] == 0)
//             return;
//         Min = min(Min, d[curNode][curBit]+a[curNode][0]);
//         // cout << "Min: " <<  Min <<'\n';
//         return; 
//     }

//     for(int i=0; i<n; i++){
//         if((curBit&(1<<i))) // 이미 방문함!
//             continue;
//         if(a[curNode][i] == 0) // 방문이 불가!
//             continue;

//         int newBit = curBit|(1<<i);
//         int newLen = d[curNode][curBit] + a[curNode][i];
//         // 이미 방문한 경로인데, 지금까지의 경로가 더 오래걸림
//         if(d[i][newBit] != -1 && d[i][newBit] <= newLen)
//             continue;
        
//         d[i][newBit] = newLen;

//         TSP(i, newBit);
//     }
// }
double TSP(int curNode, int curBit){
    if(curBit == refBit){
        if(a[curNode][0] == 0)
            return INF;
        return a[curNode][0]; 
    }

    if (d[curNode][curBit] != -1)   return d[curNode][curBit];
    d[curNode][curBit] = INF;

    for(int i=0; i<n; i++){
        if((curBit&(1<<i))) // 이미 방문함!
            continue;
        if(a[curNode][i] == 0) // 방문이 불가!
            continue;

        int newBit = curBit|(1<<i);
        d[curNode][curBit] = min(d[curNode][curBit], TSP(i, newBit) + a[curNode][i]);
    }
    return d[curNode][curBit];
}