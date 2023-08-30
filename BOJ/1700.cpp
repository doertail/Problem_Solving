#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

// 전기용품들이 켜져있는지 기록 ..
int used[102];
queue<int> lastChosen[102];
int main(void){
    FAST_IO
    int n, Ans = 0;
    int N, K;
    cin >> N >> K;
    // 물건들이 어떤 순서로 들어오는지 기록
    int Sche[102];
    // lastChosen[1] = T, 1번 물건이 가장 마지막에 쓰이는 시간이 T이다.
    // int lastChosen[102]; 
    
    for(int i=1; i<=K; i++){
        cin >> Sche[i];
        // lastChosen[Sche[i]] = i;
        lastChosen[Sche[i]].push(i);
    }

    int plug[105];
    // cout << plug.size();
    for(int i=1; i<=K; i++){
        // for(int k = 1; k<=3; k++)
            // cout << "Ans:" << Ans << " | " << plug[1] <<' ' << plug[2] << ' ' << plug[3] <<'\n';
        int n = Sche[i];
        // 이미 n이 꽂혀있음
        if(used[n])
                continue;
        // 꽉 참
        if(used[0] == N){
            // 어떤거 뽑을지 결정 ..
            int idx, plugIdx, MAX=0;
            for(int j=1; j<= N; j++){
                // 이제 다시는 plug[j](j번째에 꽃힌 것)를 안 씀!!

                // if(lastChosen[plug[j]].empty()){
                //         idx = plug[j];
                //         plugIdx = j;
                //         continue;
                // }
                bool flag = false;
                while(lastChosen[plug[j]].front() < i){
                    lastChosen[plug[j]].pop();
                    if(lastChosen[plug[j]].empty()){
                        idx = plug[j];
                        plugIdx = j;
                        flag = true;
                        break;
                    }
                }
                if(flag)    
                    break;
                // if(lastChosen[plug[j]].front() < i){
                //     idx = plug[j];
                //     plugIdx = j;
                //     break;
                // }

                if(MAX < lastChosen[plug[j]].front()){
                    MAX = lastChosen[plug[j]].front();
                    idx = plug[j];
                    plugIdx = j;
                }
            }
            Ans++;
            // 원래 있던거 used에 지우고
            used[idx] = 0;
            // 새로 쓰는거 기록
            used[n] = 1;
            plug[plugIdx] = n;
        }
        // 플러그 꽂을 수 있음.
        else{
            used[0]++;
            used[n] = 1;
            plug[used[0]] = n;
        }
    }
    
    cout << Ans;
    return 0;
}