#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
#define MAX 1000005
using namespace std;
int a[MAX];
int n;
vector<int> vec;
vector<int> Index;

int main(void){
    FAST_IO
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i];
    
    vec.push_back(a[0]);
    Index.push_back(1);
    
    for(int i=1; i<n; i++){
        if(vec.back() < a[i]){
            vec.push_back(a[i]);
            // Index[i] = vec.size();
            Index.push_back(vec.size());
        }
        else{
            int idx = lower_bound(vec.begin(), vec.end(), a[i])-vec.begin();
            vec[idx] = a[i];
            // Index[i] = idx+1;
            Index.push_back(idx+1);
        }
        // cout << Index[i] << '\n';
    }
    stack<int> Ans;

    // for(int n : Index)
    //     cout << n <<'\n';

    int lis = *max_element(Index.begin(), Index.end());
    cout << lis << '\n';
    for(int i=n-1; i>=0; i--){
        if(Index[i] != lis)
            continue;
        Ans.push(a[i]);
        lis--;
    }
    
    while(!Ans.empty()){
        cout << Ans.top() << ' ';
        Ans.pop();
    }
    return 0;
}