// B: 끝말잇기
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
vector<string> vec;
int main(void){
    FAST_IO
    int N; cin >> N;
    int idx;
    while(N--){
        string str;
        cin >> str;
        if(str == "?")
            idx = vec.size();
        vec.push_back(str);
    }
    cin >> N;
    while(N--)
    {   
        bool flag = true;
        string str;
        cin >> str;
        // 앞 놈
        if(idx != 0){
            if(vec[idx-1].back() != str[0])
                continue;
        }
        if(idx != vec.size()-1){
            if(vec[idx+1][0] != str.back())
                continue;
        }
        for(string sstr:vec){
            if(sstr == str)
                flag = false;
        }
        if(flag)
            cout << str;
    }
    

    return 0;
}