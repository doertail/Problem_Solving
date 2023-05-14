// 2608: 로마숫자
#include <bits/stdc++.h>

using namespace std;

string str1, str2;

int arabiatoRoman(string str);
string romantoArabia(int num);

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    cin >> str1 >> str2;

    int arabia = arabiatoRoman(str1)+ arabiatoRoman(str2);
    string rom = romantoArabia(arabia);

    cout << arabia << "\n" << rom<<"\n";
    
    return 0;   
}

int arabiatoRoman(string str)
{
    int len = str.length();
    int sum = 0;

    for(int i=0; i< len; i++) {
        if(str[i] == 'I') {
            if((i == len-1) || str[i+1] == 'I')
                sum += 1;
            else {
                if(str[i+1] == 'V') {
                    sum += 4; 
                    i++;
                }
                else if(str[i+1] == 'X') {
                    sum += 9;
                    i++;
                }
            }
        }
        else if(str[i] == 'V')
            sum += 5;
        else if(str[i] == 'X') {
            if(i == len-1)
                sum += 10;
            else {
                if(str[i+1] == 'L') {
                    sum += 40; 
                    i++;
                }
                else if(str[i+1] == 'C') {
                    sum += 90;
                    i++;
                }
                else
                    sum += 10;
            }
        }
        else if(str[i] == 'L')
            sum += 50;
        else if(str[i] == 'C') {
            if(i == len-1)
                sum += 100;
            else {
                if(str[i+1] == 'D') {
                    sum += 400; 
                    i++;
                }
                else if(str[i+1] == 'M') {
                    sum += 900;
                    i++;
                }
                else
                    sum += 100;
            }
        }
        else if(str[i] == 'D')
            sum += 500;
        else
            sum += 1000;
    }

    return sum;
}

string romantoArabia(int num) {
    string str = "";
    while(num >= 1) {
        if(num >= 1000) {
            int div = num / 1000;
            for(int i=0; i< div; i++)
                str += "M";
            num -= 1000 * div;
        }
        else if(num >= 900) {
            str += "CM";
            num -= 900;
        }
        else if(num >= 500) {
            str += 'D';
            num -= 500;
        }
        else if(num >= 400) {
            str += "CD";
            num -= 400;
        }
        else if(num >= 100) {
            int div = num / 100;
            for(int i=0; i< div; i++)
                str += 'C';
            num -= 100 * div;
        }
        else if(num >= 90) {
            str += "XC";
            num -= 90;
        }
        else if(num >= 50) {
            str += 'L';
            num -= 50;
        }
        else if(num >= 40) {
            str += "XL";
            num -= 40;
        }
        else if(num >= 10) {
            int div = num / 10;
            for(int i=0; i< div; i++)
                str += "X";
            num -= 10 * div;
        }
        else if(num >= 9) {
            str += "IX";
            num -= 9;
        }
        else if(num >= 5) {
            str += 'V';
            num -= 5;
        }
        else if(num >= 4) {
            str += "IV";
            num -= 4;
        }
        else {
            int div = num / 1;
            for(int i=0; i< div; i++)
                str += "I";
            num -= 1 * div;
        }
    }
    
    return str;
}
