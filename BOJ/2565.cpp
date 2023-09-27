#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
#define MAX 1000005
#define mINF -1000000005
using namespace std;
pair a[MAX];
int n;
vector<int> vec;

int main(void){
    FAST_IO
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a+n);

    vec.push_back(a[0].second);
    for(int i=1; i<n; i++){
        if(vec.back() < a[i].second)
            vec.push_back(a[i].second);
        else{
            vec[lower_bound(vec.begin(), vec.end(), a[i].second)-vec.begin()] = a[i].second;
        }
    }
    // for(int n:vec)
    //     cout << n << '\n';
    cout << n - vec.size();

    return 0;
}