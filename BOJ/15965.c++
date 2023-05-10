// 15965 K번재 소수
#include <bits/stdc++.h>
#define ll long long 
#define MAX 10000001

using namespace std;
bool arr[MAX+1];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll N;
    cin >> N;

    for(ll i=2; i*i <= MAX; i++) {
        if(arr[i] == false) {
            for(int j=2; i*j <= MAX; j++) {
                arr[i*j] = true;
            }
        }
    }

    ll num = 0;

    for(ll i=2; i<=MAX; i++) {
        if(arr[i]==false)
            num ++; // K번재 소수

        if(num == N) {
            cout << i <<"\n";
            break;
        }   
    }
    
    return 0;
}