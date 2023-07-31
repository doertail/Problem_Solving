// 17281: ⚾
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
using namespace std;

int arr[51][10]; // [i이닝]의 [j번 타자]
int playball(int inning);
int MAX;
int tmpHitter;
vector<int> v = {2, 3, 4, 5 ,6 ,7, 8, 9}; // 1번타자는 4번으로 ㄱ

int main(void){
    FAST_IO
    int N; cin >> N;
    for(int n=1; n<=N; n++){ // 이닝
        for(int i=1; i<=9; i++)
            cin >> arr[n][i];
    }
        // backtracking
        do{
            v.insert(v.begin()+3, 1);
            int tmpScore=0;
            tmpHitter = 0;
            for(int n=1; n<=N; n++)
                tmpScore += playball(n);
            MAX = max(MAX, tmpScore);
            v.erase(v.begin()+3);
        }while(next_permutation(v.begin(), v.begin()+8));
    
    cout << MAX <<'\n';

    return 0;
}

int playball(int inning){
    int score=0;
    int base[6] = {0, 0, 0, 0, 0, 0};
    int outCount = 0;
    while(outCount != 3){
        if(arr[inning][v[tmpHitter]] == 0)
            outCount++;
        else if(arr[inning][v[tmpHitter]] == 1){
            for(int i=2; i>=0; i--){
                if(base[i]){
                    base[i]--;
                    base[i+1]++;
                }
            }
            base[0]++; 
        }
        else if(arr[inning][v[tmpHitter]] == 2){
            for(int i=2; i>=0; i--){
                if(base[i]){
                    base[i]--;
                    base[i+2]++;
                }
            }
            base[1]++;
        }
        else if(arr[inning][v[tmpHitter]] == 3){
            for(int i=2; i>=0; i--){
                if(base[i]){
                    base[i]--;
                    base[i+3]++;
                }
            }
            base[2]++;
        }
        else if(arr[inning][v[tmpHitter]] == 4){
            for(int i=2; i>=0; i--){
                if(base[i]){
                    base[i]--;
                    score++;
                }
            }
            score++;
        }

        // 루 청산
        for(int i=3; i<6; i++){
            if(base[i]){
                base[i]--;
                score++;
            }
        }

        if(++tmpHitter == 9){
            tmpHitter = 0;
        }
    }

    return score;
}