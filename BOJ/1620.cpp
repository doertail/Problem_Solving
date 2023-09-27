#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int main(void){
    FAST_IO
    map<int, string> ismap;
    map<string, int> simap;
    int N, M;
    cin >> N >> M;

    for(int i=1; i<=N; i++){
        string str;
        cin >> str;
        ismap.insert({i, str});
        simap.insert({str, i});
    }
    while(M--){
        string str;
        cin >> str;
        // simap dont have str as key
        if(simap.find(str) == simap.end())
            cout << ismap[stoi(str)] << '\n';
        
        else
            cout << simap[str] << '\n';
        
    }
    return 0;
}