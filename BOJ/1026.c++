#include <bits/stdc++.h>

using namespace std;
priority_queue<int, vector<int>, less<int>> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);

    int len, sum = 0;
    cin >> len;
    int n;

    for(int i=0; i<len; i++)
    {
        cin >> n;
        pq1.push(n);
    }

    for(int i=0; i<len; i++)
    {
        cin >> n;
        pq2.push(n);
    }

    for(int i=0; i<len; i++)
    {
        sum += pq1.top() * pq2.top();
        pq1.pop();
        pq2.pop();
    }

    cout << sum <<"\n";
}