#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;
int Ans;
string temp;
bool isMinus;
int main(void){
    FAST_IO
    string str;
    cin >> str;
    for(char c:str){
        if(isMinus == true && c == '-'){
            Ans -= stoi(temp);
            temp.clear();
        }
        else if(isMinus == true && c == '+'){
            Ans -= stoi(temp);
            temp.clear();
        }
        else if(isMinus == false && c == '-'){
            Ans += stoi(temp);
            temp.clear();
            isMinus = true;
        }
        else if(isMinus == false && c == '+'){
            Ans += stoi(temp);
            temp.clear();
            isMinus = false;   
        }
        else
            temp.push_back(c);
        
    }
    
    if(isMinus == true)
        Ans -= stoi(temp);
    else
        Ans += stoi(temp);

    cout << Ans;

    return 0;
}