// 1774 우주신과의 교감
#include <bits/stdc++.h>
#define MAX 1001

using namespace std;

struct NODE
{
    int x;
    int y;
    int num;
};

struct EDGE
{
    int first; 
    int second;
    long double len;
};

int V, E, num_of_edge;
long double sum;

int parent[MAX];
NODE points[MAX];
vector<EDGE> DIST;

EDGE make_EDGE(NODE a, NODE b);
int find(int x);
bool merge(int a, int b);
int comp(EDGE a, EDGE b);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> V >> E;

    for(int i=1; i<=V; i++) {
        points[i].num = i;
        cin>>points[i].x>>points[i].y;
        parent[i] = i;
    }

    for(int i=0, from, to; i<E; i++) {
        cin>>from>>to;
        merge(from, to);
    }

    for(int i=1; i<V; i++) {
        for(int j=i+1; j<=V; j++) {
            if(find(i)!=find(j))
                DIST.push_back(make_EDGE(points[i], points[j]));
        }
    }

    sort(DIST.begin(), DIST.end(), comp);

    for(int i=0, a, b; num_of_edge < V-1; i++)
        if(merge(DIST[i].first, DIST[i].second)) sum += DIST[i].len;

    printf("%.2Lf\n", sum);

    return 0;
}

EDGE make_EDGE(NODE a, NODE b)
{
    EDGE e;

    e.first = a.num;
    e.second = b.num;
    e.len = (long double)sqrt(pow(a.x-b.x, 2)+pow(a.y-b.y, 2));

    return e;
}

int find(int x)
{
    if(x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

bool merge(int a, int b)
{
    a = find(a);
    b = find(b);

    if(a == b) return false;
    num_of_edge++;
    parent[a] = b; return true;
}

int comp(EDGE a, EDGE b)
{
    return a.len<b.len;
}