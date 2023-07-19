// 13335: 트럭
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
using namespace std;

int main(void){
    FAST_IO
    int n, w, L;
    cin >> n >> w >> L;

    vector<pair> trucks; // (무게, 위치)

    for(int i=0; i<n; i++){
        int weight;
        cin >> weight;
        trucks.push_back({weight, i+w});
    }

    int finished_idx = -1; // 어디까지 완료됐니?
    int temp_weight=0; // 다리 위 무게
    int temp_number=0; // 다리 위 개수
    int temp_index=-1;    // 어디까지 넣었니?
    int time=0;

    while(1){
        if(finished_idx == n - 1)
            break;

        time += 1;

        if(temp_weight + trucks[temp_index+1].first > L || temp_number+1 > w || temp_index == n-1){
            for(int i=finished_idx+1; i <= temp_index; i++)
                trucks[i].second--;

            if(trucks[finished_idx+1].second == -1){
                temp_weight -= trucks[finished_idx+1].first;
                temp_number--;
                finished_idx++;

                if(temp_index == n-1 || temp_weight+trucks[temp_index+1].first > L || temp_number+1 > w)
                    continue;
                temp_index++;
                trucks[temp_index].second--; 
                temp_weight += trucks[temp_index].first;
                temp_number++;
                for(int i = temp_index+1; i<n; i++)
                    trucks[i].second--;
            }
        }
        else{
            temp_index++;
            temp_weight += trucks[temp_index].first;
            temp_number++;
            for(int i = finished_idx+1; i<n; i++)
                trucks[i].second--;

            if(trucks[finished_idx+1].second == -1){
                temp_weight -= trucks[finished_idx+1].first;
                temp_number--;
                finished_idx++;
            }
        }
    }
    cout << time << "\n";

    return 0;
}