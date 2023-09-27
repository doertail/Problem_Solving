#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pair pair<int, int>
using namespace std;

int main(void){
    FAST_IO
    int N;
    cin >> N;
    cout << '\n';
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    while(N--){
        int n;
        cin >> n;
        if(n)
            pq.push(n);
        else{
            if(pq.empty())
                cout << 0 <<'\n';
            else{
                cout << pq.top() <<'\n';
                pq.pop();
            }
        }

    }
    
    return 0;
}