// 15654: N과 M (6)
#include <bits/stdc++.h>

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);

#ifdef ONLINE_JUDGE
#define DEBUG
#endif

using namespace std;

int main(void){
    FAST_IO
    
    int N, M;

    cin >> N >> M;

    int *arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];

    sort(arr, arr+N);
    
    int *ref = new int[N];
    fill(ref, ref+N, 1);

    for(int i=0; i<M ;i++)
        ref[i] = 0;

    do{
        for(int i=0; i<N; i++){
            if(ref[i]==0)
                cout << arr[i] <<' ';
        }
        cout <<"\n";
    }while(next_permutation(ref, ref+N));

    return 0;
}
