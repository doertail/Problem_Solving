#include <bits/stdc++.h>

using namespace std;

priority_queue<int, vector<int>, less<int>> pq1;
priority_queue<int, vector<int>, greater<int>> pq2;
void push_number(priority_queue<int, vector<int>, greater<int>> pq, int len);

int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int sum =0;
    int len;
    cin >> len;

    push_number(pq1, len);
    push_number(pq2, len);
    
    
    for(int i=0; i<len; i++)
    {
        sum += pq1.top() * pq2.top();
        pq1.pop();
        pq2.pop();
    }

    cout << sum <<"\n";
}

void push_number(priority_queue<int, vector<int>, greater<int>> pq, int len)
{
    int n;

    for(int i=0; i<len; i++)
    {
        cin >> n;
        pq.push(n);
    }
}
