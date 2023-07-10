// [Number]: [Name]
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
using namespace std;

vector<pair> vec;
int N;
int max_of_broken;
void func(int n, int sum);

int main(void){
    FAST_IO
    cin >> N;

    for(int i=0; i<N; i++){
        int n1, n2;
        cin >> n1 >> n2;
        vec.push_back({n1, n2});
    }
    func(0, 0);

    cout << max_of_broken <<"\n";

    return 0;
}
// 내구도, 무게
void func(int n, int sum)
{
    bool flag = false;
    if(n == N){ // 맨 마지막 계란까지 침
        max_of_broken = max(sum, max_of_broken);
        return;
    } 
    if(vec[n].first <= 0){ // 든 계란이 깨져있음
        func(n+1, sum);
        return;
    }    
    for(int i=0; i<N; i++){
        int broken_eggs = 0;
        if(i == n)  continue; // 나 자신이랑 부딪히기 x
        if(vec[i].first <= 0) // 부딪혀질 계란이 이미 깨져있음
            continue;
        flag = true;

        vec[i].first -= vec[n].second;
        if(vec[i].first<=0) broken_eggs ++;

        vec[n].first -= vec[i].second;
        if(vec[n].first<=0) broken_eggs ++;

        func(n+1, sum+broken_eggs);

        vec[i].first += vec[n].second;
        vec[n].first += vec[i].second;
    }
    // 한 번도 못 깬 경우!
    if(!flag) func(n+1, sum);
}