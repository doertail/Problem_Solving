// 11729: 하노이 탑 이동 순서
#include <bits/stdc++.h>
#define ll long long
#define condition ios_base::sync_with_stdio(0); cin.tie(NULL);

using namespace std;
void hanoi(int a, int b, int n);

int main(void){
    condition
    int num;
    cin >> num;
    cout << (1<<num) -1 << '\n';
    hanoi(1, 3, num);

    return 0;
}

void hanoi(int a, int b, int n){
    if(n == 1){
        cout << a << ' ' << b << '\n';
        return;
    }
    hanoi(a, 6 - a- b, n-1);
    cout << a << ' ' << b << '\n';
    hanoi(6-a-b, b, n-1);
}