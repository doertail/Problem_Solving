// 6603: 로또
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int main(void){
    FAST_IO
    while(1){
        int n;
        cin >> n;

        if(!n) break;

        vector <int> vec;

        for(int i=0; i<n; i++){
            int num;
            cin >> num;
            vec.push_back(num);
        }

        int arr[13];
        fill(arr, arr+6, 0); // 0만 뽑음!
        fill(arr+6, arr+n, 1);

        do{
            for(int i=0; i<n; i++){
                if(arr[i] == 0)
                    cout << vec[i] <<' ';
            }
                cout << "\n";
        }while(next_permutation(arr, arr+n));
        // 조합 구현

        cout <<"\n";
    }
    
    return 0;
}