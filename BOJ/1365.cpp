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
int lower_idx(int target, int len){
    int st = 0;
    int en = len;
    while(st < en){
        int mid = (st+en)/2;
        if(a[mid] >= target)    en = mid;
        else st = mid+1;
    }
    return st;
}

int main(void){
    FAST_IO
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
    cout << n - vec.size();

    return 0;
}