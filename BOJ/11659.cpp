// 11659: 구간 합 구하기 4
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define MAX 100002
using namespace std;

ll a[MAX];
ll d[MAX];
int main(void){
    FAST_IO
    int N, M;
    cin >> N >> M;
    for(int i=1; i<N+1; i++)
        cin >> a[i];
    d[1] = a[1];
    for(int i=2; i<N+1; i++)
        d[i] = d[i-1] + a[i];
    while(M--){
        int a, b;
        cin >> a >> b;
        cout << d[b] - d[a-1] << '\n';
    }

    return 0;
}
