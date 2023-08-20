// Number: Name
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
#define ll long long
#define X first
#define Y second

using namespace std;
pair a[105];
int d[100005];
int main(void){
    FAST_IO
    int N, K;
    cin >> N >> K;
    for(int i=0; i<N; i++)
        cin >> a[i].X >> a[i].Y;
    sort(a, a+N);
    // cout << a[1].X;

    // for(int i=1; i<=K; i++){
    //     for(int idx=0; idx<N; idx++){
    //         // if(a[idx].X > i)
    //         //     break;
    //         // cout << i << idx <<'\n';
    //         d[i] = max(d[i], d[i-a[idx].X] + a[idx].Y);
    //     }
    // }

    for(int i=0; i<N; i++){
        for(int j= K; j >= a[i].X; j--){
            d[j] = max(d[j], d[j-a[i].X]+a[i].Y);
        }
    }
    cout << d[K];

    return 0;
}
// 1 1
// 1 10
// 2 4
// 4 3
// 8 9