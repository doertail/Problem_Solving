#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define MAX 105
#define INF 100000005
using namespace std;

int g[MAX][MAX];
int f[MAX][MAX];
int main(void){
    FAST_IO

    int V, E;
    cin >> V >> E;
    for(int i=0; i<E; i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(!g[a][b])
            g[a][b] = c;
        else
            g[a][b] = min(g[a][b], c);
    }
    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            if(i == j)
                f[i][j] = 0;
            else if(g[i][j])
                f[i][j] = g[i][j];
            else
                f[i][j] = INF;   
        }
    }

    for(int k=1; k<=V; k++)
        for(int i=1; i<=V; i++)
            for(int j=1; j<=V; j++)
                f[i][j] = min(f[i][j], f[i][k]+f[k][j]);

    for(int i=1; i<=V; i++){
        for(int j=1; j<=V; j++){
            if(f[i][j] == INF)
                cout << 0 <<' ';
            else
                cout << f[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}