// 1003: 피보나치 함수
#include <bits/stdc++.h>
#define ll long long
using namespace std;

pair<ll, ll> arr[41];

int main(void) 
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int testcase, num;
    cin >> testcase;

    arr[0] = {1, 0};
    arr[1] = {0, 1};

    for(int i=2; i<41; i++)
        arr[i] = {arr[i-1].first + arr[i-2].first, arr[i-1].second + arr[i-2].second};


    while(testcase--){
        cin >> num;
        cout << arr[num].first <<' '<< arr[num].second <<"\n";
    }
    
    return 0;
}