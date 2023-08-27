#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
using namespace std;
vector<int> h, l, rf;
int main(void){
    FAST_IO
    int N, M, L;
    cin >> N >> M >> L;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        h.push_back(num);
    }
    sort(h.begin(), h.end());
    h.push_back(L);
    h.insert(h.begin(), 0);

    for(int i=1; i<h.size(); i++)
        l.push_back(h[i]-h[i-1]);
    
    sort(l.begin(), l.end(), greater());
    rf = vector(l);

    for(int n:l)
        cout << n <<' ';

    while(M != 0){
        
    }
    return 0;
}