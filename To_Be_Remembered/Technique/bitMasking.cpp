// 신호등의 색깔을 비트마스킹으로
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
int arr[1<<3]; // 0:red, 1: blue, 2:green
int main(void){
    FAST_IO
    /*
    0 -> 1
    1 -> 2
    2 -> 4
    */
    cout << (1|2|4); // 7
    
    return 0;
}