// 14891: 톱니바퀴
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

deque<char> topni1;
deque<char> topni2;
deque<char> topni3;
deque<char> topni4;

bool flag1;
bool flag2;
bool flag3;
bool flag4;

void pushD(int num);
void rotate(int num, int direction);

int main(void){
    FAST_IO

    // 입력
    pushD(1);pushD(2);
    pushD(3);pushD(4);

    int n_rotate;
    cin >> n_rotate;

    // 회전 시키기
    for(int i=0; i<n_rotate; i++){
        flag1=false;flag2=false;
        flag3=false;flag4=false;

        int number, direction;
        cin >> number >> direction;
        rotate(number, direction);
    }

    // 최종 결과!
    int sum = 0;

    if(topni1[0]=='1') sum += 1; 
    if(topni2[0]=='1') sum += 2;
    if(topni3[0]=='1') sum += 4;
    if(topni4[0]=='1') sum += 8;

    cout << sum << "\n";

    return 0;
}

void pushD(int num){   
    if(num == 1){
        for(int i=0; i<8; i++){
            char num;
            cin >> num;
            topni1.push_back(num);
        }
    }
    else if(num == 2){
        for(int i=0; i<8; i++){
            char num;
            cin >> num;
            topni2.push_back(num);
        }
    }
    else if(num == 3){
        for(int i=0; i<8; i++){
            char num;
            cin >> num;
            topni3.push_back(num);
        }
    }
    else{
        for(int i=0; i<8; i++){
            char num;
            cin >> num;
            topni4.push_back(num);
        }
    }
}
void rotate(int num, int direction){ // 2 <-> 6 // 1이면 시계, -1이 반시계
    if(num == 1 ){
        flag1=true;
        if(flag2 == false && topni1[2] != topni2[6]){
            flag2 = true; rotate(2, direction * -1);   
        }
        flag2 = true;
        if(direction == 1){
            char temp = topni1[7]; topni1.pop_back();
            topni1.push_front(temp);
        }
        else{
            char temp = topni1[0]; topni1.pop_front();
            topni1.push_back(temp);
        }
    }
    else if(num == 2){
        flag2=true;
        if(flag1 == false && topni1[2] != topni2[6]){
            flag1 = true; rotate(1, direction * -1);   
        }
        flag1 = true;
        if(flag3 == false && topni2[2] != topni3[6]){
            flag3 = true; rotate(3, direction * -1);   
        }
        flag3 = true;
        if(direction == 1){
            char temp = topni2[7]; topni2.pop_back();
            topni2.push_front(temp);
        }
        else{
            char temp = topni2[0]; topni2.pop_front();
            topni2.push_back(temp);
        }
    }
    else if(num == 3){
        flag3 = true;
        if(flag2 == false && topni2[2] != topni3[6]){
            flag2 = true; rotate(2, direction * -1);   
        }
        flag2=true;
        if(flag4 == false && topni3[2] != topni4[6]){
            flag4 = true; rotate(4, direction * -1);   
        }
        flag4=true;
        if(direction == 1){
            char temp = topni3[7]; topni3.pop_back();
            topni3.push_front(temp);
        }
        else{
            char temp = topni3[0]; topni3.pop_front();
            topni3.push_back(temp);
        }
    }
    else { // num == 4
        flag4=true;
        if(flag3 == false && topni3[2] != topni4[6]){
            flag3 = true; rotate(3, direction * -1);   
        }
        flag3=true;
        if(direction == 1){
            char temp = topni4[7]; topni4.pop_back();
            topni4.push_front(temp);
        }
        else{
            char temp = topni4[0]; topni4.pop_front();
            topni4.push_back(temp);
        }
    }
}