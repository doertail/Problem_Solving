#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
using namespace std;
int gcd(int a, int b){
    if(a==0) return b;
    return gcd(b%a, a);
}
int lcm(int a, int b){
    return a / gcd(a, b) * b;
}
int solve(int M, int N, int X, int Y){
    if(M == X)
        X = 0;
    if(Y == N)
        Y = 0;
    int LCM = lcm(M, N);

    if(X == 0 && Y == 0)
        return LCM;
    for(int i=X; i<=LCM; i+= M){
        if(i%N == Y){
            return i;
        }
    }   
    return -1;
}
int main(void){
    FAST_IO
    int T; cin >> T;
    while(T--){
        int M, N, X, Y;
        cin >> M >> N >> X >> Y;
        cout << solve(M, N, X, Y) << '\n';
    }
    
    return 0;
}