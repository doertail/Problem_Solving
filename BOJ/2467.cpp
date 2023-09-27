#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, ll>
#define MAX 100005
using namespace std;
int n;
int a[MAX];
ll ans[3]; // idx1 idx2 dist
int binarySearch(){
    ll Min = 9876543210;
    int st = 0;
    int en = n-1;
    ll val1 = 0;
    ll val2 = 0;
    while(st < en){
        int sum = a[st] + a[en];
        if(abs(sum) < Min){
            Min = abs(sum);
            val1 = a[st];
            val2 = a[en];
        }
        if(sum <= 0)
            st++;
        
        else
            en--;
    }   
    cout << val1 << ' ' << val2; 
    return 0;
}

int main(void){
    FAST_IO
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    binarySearch();
    sort(ans, ans+2);
    // cout << a[ans[0]] << ' ' << a[ans[1]];
    // cout << '\n' << ans[2];
    return 0;
}