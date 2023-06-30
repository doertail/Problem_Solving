#include<iostream>
#include<algorithm>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);

using namespace std;

int main(void){
    FAST_IO
    
    int N, M;
    cin >> N >> M;

    int *arr = new int[N];
    for(int i=0; i<N; i++)
        cin >> arr[i];

    sort(arr, arr+N);

    do{
        for(int i=0; i<M; i++)
            cout << arr[i] <<' ';
        
        cout <<"\n";
    reverse(arr + M, arr+N); // 중요!!
    }while(next_permutation(arr, arr+N));

    return 0;
}

// 참고: https://ansohxxn.github.io/algorithm/permutation/
// BOJ 15654: N과 M (5)

/*
Q. 왜 reverse를 하는가?:
A. 가령 {1, 2, 3, 4}
에서 4P2을 위해서 next_permutation을 사용 한다면, 
1 2 3 4
1 2 4 3
..
이런 식으로 (n-r)에 해당하는 2!개 만큼  중복이 발생한다.
1 2 3 4
다음에 바로
1 3 2 4
가 되도록 그 뒤를 아예 바꾸는 것!
*/