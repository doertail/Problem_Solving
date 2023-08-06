// A: 양말 짝 맞추기
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
int a[10];
int main(void){
    FAST_IO
    for(int i=0; i<5; i++){
        int num; cin >> num;
        a[num]++ ;
    }

    for(int i=0; i<10; i++){
        if(a[i] % 2 == 1)
            cout << i <<'\n';
    }

    return 0;
}