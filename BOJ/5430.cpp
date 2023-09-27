#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int main(void){
    FAST_IO
    int T; cin >> T;
    while(T--){
        string str; cin >> str;
        int n; cin >> n;
        string arr; cin >> arr;
        deque<int> ans;
        string tmp;
        for(char c:arr){
            if(c == '[' || c == ']' || c == ','){
                if(!tmp.empty()) ans.push_back(stoi(tmp));
                tmp.clear();
                continue;
            }
            tmp.push_back(c);
        }
        bool is_rev = false;
        bool flag = true;
        for(char c:str){
            if(c == 'R'){
                is_rev = !is_rev;
            }
            else{
                if(is_rev){
                    if(ans.empty()){
                        cout << "error\n";
                        flag=false;
                        break;
                    }
                    ans.pop_back();
                }
                else{
                    if(ans.empty()){
                        cout << "error\n";
                        flag = false;
                        break;
                    }
                    ans.pop_front();
                }
            }
        }
        if(!flag)
            continue;
        cout << '[';
        if(is_rev){
            while(1){
                if(ans.empty())
                    break;
                cout << ans.back();
                ans.pop_back();
                if(ans.empty())
                    break;
                cout <<',';
            }
        }
        else{
            while(1){
                if(ans.empty())
                    break;
                cout << ans.front();
                ans.pop_front();
                if(ans.empty())
                    break;
                cout << ',';
            }   
        }
        cout << ']' << '\n';
    }
    return 0;
}