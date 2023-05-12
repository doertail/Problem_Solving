// 9466 텀 프로젝트
#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int T;
    cin >> T;

    while(T--) {
        int arr[100001];
        int sum = 0;

        int stu_nums;
        cin >> stu_nums;

        for(int i = 1; i <= stu_nums; i++)
            cin >> arr[i];

        for(int i=1; i<= stu_nums; i++) {
            queue<int> g_Q; // 없애는 용
            queue<int> que; // 기록 용

            if(arr[i] == -1) continue; // 탐색 기완료
                
            g_Q.push(i); que.push(i);

            while(1) {
                int temp = g_Q.front(); g_Q.pop();
                if(arr[temp] == -1) {
                    while(!que.empty()) { // 아싸
                        if(que.front() == temp) break;
                        sum += 1;
                        que.pop();
                    }
                    break;
                }

                else { // 처음 접근함
                    g_Q.push(arr[temp]); que.push(arr[temp]);
                    arr[temp] = -1;
                }
            }
        }
        cout << sum << "\n";   
    }
    
    return 0;   
}