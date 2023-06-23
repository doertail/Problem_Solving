#include <bits/stdc++.h>
#define ll long long

using namespace std;

priority_queue<ll, vector<ll>, greater<ll>> pq;

int N_prime, wanted, sum;
int arr[100];

map<ll, bool>visited;

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N_prime >> wanted;
    
    for(int i=0; i<N_prime; i++){
        cin >> arr[i];
        pq.push(arr[i]);
        visited[arr[i]] = true;
    }

    int max = arr[N_prime-1];
    ll top, val;

    while(1){
        top = pq.top(); pq.pop();
        sum ++;

        if(sum == wanted){
            cout << top <<"\n";
            return 0;
        }
        
        for(int i=0; i<N_prime; i++){
            int num = arr[i];
            val = top * num;

            if(pq.size() > wanted && val > max) continue;
            if(visited[val]) continue;

            pq.push(val);
            visited[val] = true; 

            if(val > max) max = val;
        }
    }
    
    return 0;
}