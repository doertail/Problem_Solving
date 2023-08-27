// Number: Name
#include <bits/stdc++.h>
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(NULL);
#define ll long long
#define pp pair<pair<int,int>, pair<int, int>>
// #define pair pair<int, int>
using namespace std;
pp a[100005];
bool comp(const pp& a, const pp& b){
    pair<int, int> as, ae, bs, be;
    as = a.first; ae = a.second;
    bs = b.first; be = b.second;

    if(as.first == bs.first){
        if(as.second == bs.second){
            if(ae.first == be.first)
                return ae.second > be.second;
            return ae.first > be.first;
        }
        return as.second < bs.second;
    }
    return as.first < bs.first;
}

// bool month[12];
int main(void){
    FAST_IO  
    int N;
    cin >> N;
    int sm, sd, fm, fd;
    for(int i=0; i<N; i++){
        cin >> sm >> sd >> fm >> fd;
        a[i] = {{sm,sd}, {fm, fd}};
    }

    sort(a, a+N, comp);

    // for(int i=0; i<N; i++)
        // cout << a[i].first.first << ' ' << a[i].first.second << ' ' << a[i].second.first <<' '<< a[i].second.second <<'\n';

    int ans=1;
    pair<int, int> tmp = {0, 0};
    int idx;
    // 첫 꽃 정하기
    for(idx=0; idx<N; idx++){
        pair<int, int> s, f;
        s = a[idx].first; f = a[idx].second;
        
        if(s.first > 3 || (s.first==3 &&s.second>1)) // 3월 이후에 피면 컷!
            break;
        if(tmp.first < f.first || (tmp.first == f.first && tmp.second < f.second))
            tmp = f;
    }
    if(tmp.first < 3){
        cout << 0;
        return 0;
    }
        // cout << tmp.first << tmp.second << '\n';
        
        
    for(int i=idx; i<N; i++){
        if(tmp.first > 11 ) 
            break;
    // cout << tmp.first << tmp.second << '\n';
    // cout << ans <<'\n';
        pair<int, int> s = a[i].first, f = a[i].second;
        if(s.first > 11 || f.first < 3)
            continue;

        if(tmp.first < s.first || (tmp.first == s.first && tmp.second < s.second)){
            cout << 0;
            return 0;
        }

        if(tmp.first > f.first || (tmp.first == f.first && tmp.second > f.second))
            continue;

        bool flag = false;
        pair<int, int> ntmp = tmp;
        for(int j=i+1; j<N; j++){
            pair<int, int> ns = a[j].first, nf = a[j].second; 
            
            if(ntmp.first < ns.first || (ntmp.first == ns.first && ntmp.second < ns.second)){
                break;
            }
            if(flag){
                if(tmp.first < nf.first || (tmp.first == nf.first && tmp.second <= nf.second)){
                    tmp = nf;
                    flag = true;
                    i=j;
                }    
            }
            else{
                if(f.first < nf.first || (f.first == nf.first && f.second <= nf.second)){
                    tmp = nf;
                    flag = true;
                    i=j;
                }
            }
        }
        if(!flag){
            tmp = f;
            ans++;
        }
        else
            ans++;
    }
    
    if( tmp.first > 11 ) 
        cout << ans;
    else
        cout << 0;

    return 0;
}