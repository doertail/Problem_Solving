// 16953: A -> B
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
using namespace std;

bool flag;
ll A, B;

void soultion(ll num, int n);

int main(void){
    FAST_IO
    cin >> A >> B;
    soultion(A, 1);

    if(!flag)
        cout << "-1\n";

    return 0;
}

void soultion(ll num, int n){
    if(num > B)
        return;
    else if(num == B){
        cout << n <<"\n";
        flag = true;
        exit(0);
    }
    
    soultion(num *2, n+1);
    soultion(num * 10 + 1, n+1);
}