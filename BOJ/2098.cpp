// 2098: 외판원 순회
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define INF 96544321
using namespace std;
int a[18][18];
int d[18][1<<16]; // 현재 노드 번호와 방문 여부
int Min = INT_MAX;
int refBit, n;
// void TSP(int curNode, int curBit);
int TSP(int curNode, int curBit);
int main(void){
    FAST_IO
    cin >> n;
    refBit = (1<<n)-1;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            cin >> a[i][j];
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
int TSP(int curNode, int curBit){
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