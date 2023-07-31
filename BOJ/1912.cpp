// 1912: 얀속합
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int arr[100002];
int d[100002];
int Ans = INT_MIN;
int main(void){
    FAST_IO
    int n; cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];

    for(int i=1; i<=n; i++){
        d[i] = max(d[i-1] + arr[i], arr[i]);
        Ans = max(Ans, d[i]);        
    }

    cout << Ans <<'\n';

    return 0;
}
