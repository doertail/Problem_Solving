// 14888: 연산자 끼워넣기
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int nums[101], _operator[4];
int N, MAX = -1*(1<<30), MIN = (1<<30);
vector<char> vec; // + + - *
void solve(int* arr);
int main(void){
    FAST_IO
    cin >> N;
    for(int i=0; i<N; i++)
        cin >> nums[i];
    for(int i=0; i<4; i++)
        cin >> _operator[i];
    for(int i=0; i<_operator[0]; i++)
        vec.push_back('+');
    for(int i=0; i<_operator[1]; i++)
        vec.push_back('-');
    for(int i=0; i<_operator[2]; i++)
        vec.push_back('*');
    for(int i=0; i<_operator[3]; i++)
        vec.push_back('/');

    int* arr = new int[N-1]; 
    for(int i=0; i<N-1; i++)
        arr[i] = i;

    do{
        solve(arr);
    }while(next_permutation(arr, arr+N-1));
    
    cout << MAX << '\n' << MIN << '\n';
    return 0;
}

void solve(int* arr){
    int temp = nums[0];
    for(int i=0; i<N-1; i++){
        if(vec[arr[i]] == '+')
            temp = temp + nums[i+1];
        else if(vec[arr[i]] == '-')
            temp = temp - nums[i+1];
        else if(vec[arr[i]] == '*')
            temp = temp * nums[i+1];
        else if(vec[arr[i]] == '/')
            temp = temp / nums[i+1];
    }

    MAX = max(MAX, temp);
    MIN = min(MIN, temp);
}