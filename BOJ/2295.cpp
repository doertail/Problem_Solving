#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
using namespace std;

int main(void){
    FAST_IO
    int N; cin >> N;
    vector<int> U;
    while(N--){
        int n; cin >> n;
        U.push_back(n);
    }
    sort(U.begin(), U.end());
    vector<int> two;
    N = U.size();
    for(int i=0; i<N-1; i++)
        for(int j=i; j<N; j++)
            two.push_back(U[i]+U[j]);

    sort(two.begin(), two.end());

    for(int k=N-1; k>=0; k--){
        for(int l=0; l<N; l++){
            if(binary_search(two.begin(), two.end(), U[k]- U[l])){
                cout << U[k];
                return 0;
            }
        }
    }
    return 0;
}