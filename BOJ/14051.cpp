// 14501: 퇴사 ㄱ-
#include <bits/stdc++.h>
#define ll long long
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

ll d[1500002];
pair<int, int> a[1500002];

int main(void){
    FAST_IO
    int N; cin >> N;

    for(int i=1; i<=N; i++){
        int t, p;
        cin >> t >> p;
        a[i] = {t, p};
        d[i] = p;
    }

    for(int i=N; i>0; i--){
        if(a[i].first + i > N+1)
            d[i] = d[i+1];
        else
            d[i] = max(d[i+a[i].first]+a[i].second, d[i+1]);
    }
    cout << *max_element(d+1, d+N+1);

    return 0;
}