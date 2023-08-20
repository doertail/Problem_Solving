// Number: Name
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
int a[100005];
int main(void){
    FAST_IO
    int N; cin >> N;
    for(int i=0; i<N; i++)
        cin >> a[i];
    
    sort(a, a+N);
    // cout << a[0];
    int ans = 0;
    int num = N; // 몇 개를 보는가?

    for(int num = N; num >0; num--){
        ans = max(a[N-num] * num ,ans);
    }
    
    cout << ans;
    return 0;
}


// 7 13 15 20
// 30 / 3 10