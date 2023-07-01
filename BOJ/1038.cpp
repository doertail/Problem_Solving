// 1038: 감소하는 수
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
using namespace std;

vector<ll> vec;
ll next(string str);
int main(void){
    FAST_IO
    
    int N;
    cin >> N;

    if(N < 10){
        cout << N <<"\n";
        return 0;
    }    
    if(N > 1022){
        cout << "-1\n";
        return 0;
    }
    ll index = 10;

    for(ll i=0; i<=10; i++)
        vec.push_back(i);

    while(1){
        if(vec.size() == N+1)
            break;
        string str = to_string(index);
        index = next(str);
        vec.push_back(index);
    }

    cout << vec[N] << "\n";
    return 0;
}

ll next(string str){
    int index = str.length()-1; // inital index: 맨 마지막 숫자
    while(1){
        if(index == 0){
            if(str[0] == '9'){ // ex 9876 => 43210
                string new_string = "";
                for(int i=str.length(); i>=0; i--)
                    new_string += to_string(i);
                
                return stoll(new_string);
            }
            else{ // 5432 => 6210 6543 => 7210 10 20
                for(int i=1; i<str.length(); i++)
                    str[i] = str[i] - str[str.length()-1]+'0';
                
                str[0] = str[0] + 1;

                return stoll(str);
            }
        }
        if(str[index] + 1 == str[index-1]){
            index--;
            continue;
        }

        else{  // 421 -> 430
            for(int i=index+1; i<str.length(); i++)
                    str[i] = str[i] - str[str.length()-1]+'0';
            str[index] = str[index] + 1;
            return stoll(str);
        }
    }    
}