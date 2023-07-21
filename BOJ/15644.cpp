// 13460: 구슬 탈출 3
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define pair pair<int, int>
using namespace std;

int N, M, ANS=11;
char board[11][11];
pair Hole;
pair move(pair color, int dir, pair other);
void solve(pair red, pair blue, int n=1);
vector<char> vec;
vector<char> vec_ans;
int main(void){
    FAST_IO
    pair Red, Blue;
    cin >> N >> M;
    for(int i=0; i<N; i++){
        for(int j=0; j<M; j++){
            cin >> board[i][j];
            if(board[i][j] == 'B'){
                Blue = {i, j};
                board[i][j] = '.';
            }
            else if(board[i][j] == 'R'){
                Red = {i, j};
                board[i][j] = '.';
            }
            else if(board[i][j] == 'O')
                Hole = {i, j};
        }
    }

    solve(Red, Blue);

    if(ANS == 11){
        cout << -1 << '\n';
        return 0;
    }
    else 
        cout << ANS <<"\n";

    for(char c:vec_ans)
        cout << c;

    return 0;
}

void solve(pair Red, pair Blue, int n){
    if(n > 10)
        return;
    
    pair Rtemp = Red; pair Btemp = Blue;
    if(Rtemp.second > Btemp.second){
        vec.push_back('R');
        Rtemp = move(Rtemp, 0, Btemp);
        Btemp = move(Btemp, 0, Rtemp);
    }
    else{
        vec.push_back('R');
        Btemp = move(Btemp, 0, Rtemp);
        Rtemp = move(Rtemp, 0, Btemp);
    }
    if(Rtemp != Red || Btemp != Blue){
        if(Btemp != Hole){
            if(Rtemp == Hole){
                ANS = min(ANS, n);
                if(ANS == n){
                    vec_ans.clear();
                    for(char c:vec)
                        vec_ans.push_back(c);
                    vec.pop_back();
                    return;
                }
            }
            else
                solve(Rtemp, Btemp, n+1);
        }
    }
    vec.pop_back();
    
    Rtemp = Red; Btemp = Blue;
    if(Rtemp.second < Btemp.second){
        vec.push_back('L');
        Rtemp = move(Rtemp, 1, Btemp);
        Btemp = move(Btemp, 1, Rtemp);
    }
    else{
        vec.push_back('L');
        Btemp = move(Btemp, 1, Rtemp);
        Rtemp = move(Rtemp, 1, Btemp);
    }
    if(Rtemp != Red || Btemp != Blue){
        if(Btemp != Hole){
            if(Rtemp == Hole){
                ANS = min(ANS, n);
                if(ANS == n){
                    vec_ans.clear();
                    for(char c:vec)
                        vec_ans.push_back(c);
                vec.pop_back();
                return;
                }
            }
            else
                solve(Rtemp, Btemp, n+1);
        }
    }
    vec.pop_back();

    Rtemp = Red; Btemp = Blue;
    if(Rtemp.first > Btemp.first){
        vec.push_back('D');
        Rtemp = move(Rtemp, 2, Btemp);
        Btemp = move(Btemp, 2, Rtemp);
    }
    else{
        vec.push_back('D');
        Btemp = move(Btemp, 2, Rtemp);
        Rtemp = move(Rtemp, 2, Btemp);
    }
    if(Rtemp != Red || Btemp != Blue){
        if(Btemp != Hole){
            if(Rtemp == Hole){
                ANS = min(ANS, n);
                if(ANS == n){
                    vec_ans.clear();
                    for(char c:vec)
                        vec_ans.push_back(c);
                vec.pop_back();
                return;
                }
            }
            else
                solve(Rtemp, Btemp, n+1);
        }
    }
    vec.pop_back();
    
    Rtemp = Red; Btemp = Blue;
    if(Rtemp.first < Btemp.first){
        vec.push_back('U');
        Rtemp = move(Rtemp, 3, Btemp);
        Btemp = move(Btemp, 3, Rtemp);
    }
    else{
        vec.push_back('U');
        Btemp = move(Btemp, 3, Rtemp);
        Rtemp = move(Rtemp, 3, Btemp);
    }
    if(Rtemp != Red || Btemp != Blue){
        if(Btemp != Hole){
            if(Rtemp == Hole){
                ANS = min(ANS, n);
                if(ANS == n){
                    vec_ans.clear();
                    for(char c:vec)
                        vec_ans.push_back(c);
                    vec.pop_back();
                    return;
                }
            }
            else
                solve(Rtemp, Btemp, n+1);
        }
    }
    vec.pop_back();
}
pair move(pair color, int dir, pair other){
    if(dir == 0){
        int x = color.first; int y = color.second;
        for(int j=y+1; j<M; j++){
            if(x == other.first && j == other.second){
                if(other == Hole)
                    return {x, j};
                else return {x, j-1};
            }
            else if(board[x][j] == '.')
                continue;
            else if(board[x][j] == 'O')
                return {x, j};
            else if(board[x][j] == '#')
                return {x, j-1};
        }
    }
    else if(dir == 1){
        int x = color.first; int y = color.second;
        for(int j=y-1; j>=0; j--){
            if(x == other.first && j == other.second){
                if(other == Hole)
                    return {x, j};
                else
                    return {x, j+1};
            }
            else if(board[x][j] == '.')
                continue;
            else if(board[x][j] == 'O')
                return {x, j};
            else if(board[x][j] == '#')
                return {x, j+1};
        }
    } 
    else if(dir == 2){
        int x = color.first; int y = color.second;
        for(int i=x+1; i<N; i++){
            if(i == other.first && y == other.second){
                if(other == Hole)
                    return {i, y};
                else    
                    return {i-1, y};
            }
            else if(board[i][y] == '.')
                continue;
            else if(board[i][y] == 'O')
                return {i, y};
            else if(board[i][y] == '#')
                return {i-1, y};
        }
    }
    else{
        int x = color.first; int y = color.second;
        for(int i=x-1; i>=0; i--){
            if(i == other.first && y == other.second){
                if(other == Hole)
                    return {i, y};
                else 
                    return {i+1, y};
            }
            else if(board[i][y] == '.')
                continue;
            else if(board[i][y] == 'O')
                return {i, y};
            else if(board[i][y] == '#')
                return {i+1, y};
        }
    }
}