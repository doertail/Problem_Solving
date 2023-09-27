#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
#define MAX 1000005
#define mINF -1000000005
using namespace std;
int a[MAX];
int n;
vector<int> vec;
int main(void){
    FAST_IO
    int T; cin >> T;
    while(T--){
        vec.clear();
        cin >> n;
        for(int i=0; i<n; i++)
            cin >> a[i];
        
        // sort(a, a+n);
        vec.push_back(a[0]);
        for(int i=1; i<n; i++){
            if(vec.back() < a[i])
                vec.push_back(a[i]);
            else{
                vec[lower_bound(vec.begin(), vec.end(), a[i])-vec.begin()] = a[i];
            }
        }
        // for(int n:vec)
        //     cout << n << '\n';
        cout << vec.size() << '\n';
    }
    return 0;
}