#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, bool>
using namespace std;
int main(void){
    FAST_IO
    int N, M;
    string str;
    cin >> N >> M;
    cin >> str;
    int ans=0;
    for(int i=0; i<M; i++){
        if(str[i] != 'I')
            continue;
        int Pn = 0;
        while(i < M){
            if(str[i+1] != 'O')
                break;
            i++;
            if(str[i+1] != 'I')
                break;
            i++;
            Pn++;
        }
        if(Pn>=N)
            ans += Pn - N +1;
    }

    cout << ans;

    return 0;
}