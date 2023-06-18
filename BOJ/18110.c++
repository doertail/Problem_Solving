// 18110: solved.ac
#include <bits/stdc++.h>
#define ll long long
#define MAX 300001

using namespace std;

int arr[MAX];

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    ll N;
    cin >> N;

    if(N==0){
        cout << 0; 
        return 0;
    }

    ll cut = round(N * 0.15);

    int sum = 0;

    for(int i=0; i<N; i++)
        cin >> arr[i];

    sort(arr, arr+N);
    
    for(int i=cut; i < N-cut; i++)
        sum += arr[i];

    cout << round((double)sum/((double)N- 2*cut)) << "\n";

    return 0;
}