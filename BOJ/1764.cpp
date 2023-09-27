#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
using namespace std;

int main(void){
    FAST_IO
    int N, M;
    cin >> N >> M;
    set<string> set;
    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        set.insert(str);
    }
    vector<string> ans;
    for(int i=0; i<M; i++){
        string str;
        cin >> str;
        if(set.find(str) != set.end())
            ans.push_back(str);
    }
    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for(string str:ans)
        cout << str << '\n';
    return 0;
}