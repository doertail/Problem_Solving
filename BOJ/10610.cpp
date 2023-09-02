#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
using namespace std;

// 10^14 = 100조
// 범위 내에서의 소수 판정법
// Sieve of Eratosthenes
vector<int> sieve(int n){
    vector<int> primes;
    vector<bool> state(n+1, true);
    state[1] = false;
    for(int i=2; i*i<=n; i++){
        if(!state[i]) continue;
        for(int j=i*i; j<=n; j+=i)
            state[j] = false;
    }
    for(int i=2; i<=n; i++)
        if(state[i]) primes.push_back(i);
    return primes;
}

int main(void){
    FAST_IO
    vector<bool> state(100000000000000, true);
    cout << "hi!";
    // int A, B; cin >> A >> B;


    
    return 0;
}