// 27960 : 사격내기 
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
int main(void){
    FAST_IO
    int n1, n2; cin >> n1 >> n2;
    cout << (n1 | n2) - (n1 & n2);
    
    return 0;
}