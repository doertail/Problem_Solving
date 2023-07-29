// 11656: 접미사 배열
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int main(void){
    FAST_IO
    string str;
    cin >> str;

    vector<string> vec;
    int len = str.length();
    for(int i=0; i<len; i++){
        vec.push_back(str);
        str.erase(str.begin());
    }
    sort(vec.begin(), vec.end());

    for(string str: vec)
        cout << str << '\n';

    return 0;
}