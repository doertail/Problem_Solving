// 4334: 평균은 넘겠지
#include <bits/stdc++.h>

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);

#ifdef ONLINE_JUDGE
#define DEBUG
#endif

using namespace std;

int main(void){
    FAST_IO
    
    int TC;
    cin >> TC;

    while(TC--){
        int NumOfStu;
        cin >> NumOfStu;
        double num = NumOfStu;
        double sum = 0;
        int goat=0;
        vector<int> vec;
        while(NumOfStu--){
            int score;
            cin >> score;
            vec.push_back(score);
            sum += score;
        }
        int mean = sum / num;

        for(int n: vec){
            if(n > mean)
                goat++;
        }
        cout << fixed;
        cout.precision(3);
        cout << (goat / num)*100 <<"%\n";
    }
    
    return 0;
}
