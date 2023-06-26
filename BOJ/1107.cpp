// 1107: 리모컨
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int LEN, INTEGER_OF_TARGET, dif, minnum;
char number[7]; // 5 0 0 0 0 0
bool button[10]; // 0 ~ 9 // 10(잘못 찍을까봐!)
string TARGET;

void push_number(int i);
void solution(int i);

int main(void){
    FAST_IO

    cin >> TARGET;
    LEN = TARGET.length();
    INTEGER_OF_TARGET = stoi(TARGET);

    fill(button, button + 10, true);

    int number_of_broken;
    cin >> number_of_broken;
    
    for(int i=0; i<number_of_broken; i++){
        int n;
        cin >> n;
        button[n] = false;
    }

    if(number_of_broken == 10){
        cout << abs(INTEGER_OF_TARGET - 100) <<"\n";
        return 0;
    }

    minnum = 500000;

    solution(0);
    
    cout << min(abs(INTEGER_OF_TARGET - 100), minnum) << "\n";

    return 0;
}

void solution(int i){
    if(i == LEN+1)
        return;
    for(int n=0; n<10; n++){
        if(button[n]){
            number[i] = (char)n + '0';
            push_number(i);
            solution(i+1);
        }
    }   
}

void push_number(int i){
    string str;
    bool flag = false;
    
    for(int index=0; index<=i; index++)
        str += number[index];
    
    // cout << "[DEBUG]" << str << "\n";
    
    for(char c: str){
        if(c != '0'){
            flag = true;
            break;
        }
    }

    if(!flag) // 다 0!
        dif = abs(stoi(str) - INTEGER_OF_TARGET) + 1;
    else
        dif = abs(stoi(str) - INTEGER_OF_TARGET) + i+1;

    if(dif > minnum)
        return;

    minnum = dif;

    return;
}