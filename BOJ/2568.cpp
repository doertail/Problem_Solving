#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
#define MAX 1000005
using namespace std;
pair a[MAX];
int n;
vector<int> vec;
vector<int> Index;

int main(void){
    FAST_IO
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> a[i].first >> a[i].second;
    sort(a, a+n);
    vec.push_back(a[0].second);
    Index.push_back(1);
    
    for(int i=1; i<n; i++){
        if(vec.back() < a[i].second){
            vec.push_back(a[i].second);
            // Index[i] = vec.size();
            Index.push_back(vec.size());
        }
        else{
            int idx = lower_bound(vec.begin(), vec.end(), a[i].second)-vec.begin();
            vec[idx] = a[i].second;
            // Index[i] = idx+1;
            Index.push_back(idx+1);
        }
        // cout << Index[i] << '\n';
    }
    stack<int> Ans;

    // for(int n : Index)
    //     cout << n <<'\n';

    int lis = *max_element(Index.begin(), Index.end());
    cout << n - lis << '\n';
    for(int i=n-1; i>=0; i--){
        if(Index[i] != lis)
            continue;
        Ans.push(a[i].first);
        lis--;
    }
    
    for(int i=0; i<n; i++){
        if(Ans.empty() || a[i].first != Ans.top()){
            cout << a[i].first <<'\n';
        }
        else{
            Ans.pop();
        }
        
    }
    // while(!Ans.empty()){
    //     cout << Ans.top() << ' ';
    //     Ans.pop();
    // }
    return 0;
}