// 1795: 암호 만들기
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

#define DEBUG
#ifdef ONLINE_JUDGE
#endif

char arr[15];
int main(void){
    FAST_IO
    int L, C;

    cin >> L >> C;
    for(int i=0; i<C; i++){
        cin >> arr[i];
    }
    sort(arr, arr+C);
    
    int* ref = new int[C];

    fill(ref, ref+L, 0);
    fill(ref+L, ref+C, 1);
    // 6C4 = 6! / 2! 4!
    do{
        vector<char> vec;
        for(int i=0; i<C; i++){
            if(!ref[i])
                vec.push_back(arr[i]);
        }
        int num_of_mouem=0;
        for(char c:vec){
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                num_of_mouem++;
        }
        // cout << num_of_mouem <<"\n\n";

        if(num_of_mouem >= 1 && L - num_of_mouem >= 2){
            for(char c: vec)
                cout << c;
            cout <<"\n";
        }
        else
            continue;;
    }while(next_permutation(ref, ref+C));

    return 0;
}
