// 15686: 치킨 배달
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
using namespace std;
int board[52][52];
int L, M;
vector<pair> vec;
vector<pair> home;

int main(void){
    FAST_IO
    
    cin >> L >> M;
    for(int i=1; i<=L; i++){
        for(int j=1; j<=L; j++){
            cin >> board[i][j];
            if(board[i][j]==2)
                vec.push_back({i, j});
            else if(board[i][j]==1)
                home.push_back({i, j});
        }
    }

    int* arr = new int[vec.size()];
    fill(arr, arr+vec.size(), 1);
    fill(arr, arr+M, 0);

    int sum=(1<<12);
    do{
        vector<pair> _vec;
        for(int i=0; i<vec.size(); i++){
            if(arr[i]==0)
                _vec.push_back(vec[i]); // 치킨집 고르기!
        }

        int temp_sum = 0;
        for(pair h:home){
            int temp= (1<<10);
            int x = h.first; int y = h.second;
            for(pair c:_vec){
                temp = min(temp, abs(x-c.first)+abs(y-c.second));
            }
            temp_sum += temp;
        }
        sum = min(sum, temp_sum);
    }while(next_permutation(arr, arr+vec.size()));
    
    cout << sum << "\n";

    return 0;
}