// 1431: 시리얼 번호
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

bool cmp(const string& a, const string& b);
int sum_number(string str);

int main(void){
    FAST_IO

    int N;
    cin >> N;

    vector<string> vec;

    for(int i=0; i<N; i++){
        string str;
        cin >> str;
        vec.push_back(str);
    }

    sort(vec.begin(), vec.end(), cmp);
    
    for(string str: vec)
        cout << str <<'\n';

    return 0;
}

bool cmp(const string& a, const string& b){
    if(a.length() < b.length()) 
        return true;

    else if(a.length() == b.length()){
        if(sum_number(a) < sum_number(b)) return true;
        else if(sum_number(a) == sum_number(b)){
            if(a < b)
                return true;
            else
                return false;
        } 
        else
            return false;
    }
    else
        return false;
}

int sum_number(string str){
    int ret=0;
    
    for(char c:str){
        if(c >= '0' && c <='9')
            ret += (int)c - (int)'0';
    }
    return ret;
}