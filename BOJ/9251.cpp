#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

int LCS[MAX][MAX];

int main(void) 
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    string a, b;
    cin >> a >> b;

    int a_size = a.length();
    int b_size = b.length();

    for (int i = 1; i <= a_size; i++)
        for (int j = 1; j <= b_size; j++){
            if (a[i-1] == b[j-1]) LCS[i][j] = LCS[i-1][j-1] + 1;
            else LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
        }

    cout << LCS[a_size][b_size] << '\n';
    
    return 0;   
}

