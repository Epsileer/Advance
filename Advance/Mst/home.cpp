/**
 *   author: Shubham Srivastava
 *   created: 04 June 2019  19:09:57
**/
#include <bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long double ld;
 
ll parent[100005];
ll find_parent(ll x)
{
    if(x == parent[x])
        return x;
    return parent[x] = find_parent(parent[x]);
}
 
int main(){
    // ios_base::sync_with_stdio(false); 
    // cin.tie(NULL);
    ll t;scanf("%d",&t);
    while(t--)
    {
        ll n;scanf("%d",&n);
        vector < pair <ll,ll> > v;
        vector < pair <char,ll> > query;
        vector <ll> r;
        for(int i=0;i<=n;i++)
            parent[i] = i;
        for(int i=0;i<n-1;i++)
        {
            ll a,b;
            scanf("%d %d",&a,&b);
            a--;b--;
            v.push_back({a,b});
        }
        ll q;scanf("%d",&q);
        while(q--)
        {
            char c;
            cin>>c;
            if(c == 'Q'){
                query.push_back({c,-1});
            }
            else{
                ll index;
                scanf("%d",&index);
                index--;
                r.push_back(index);
                query.push_back({c,index});
            }
        }
        sort(r.begin(),r.end());
        int count = 0;
        for(int i=0;i<n-1;i++)
        {
            if(i == r[count]){
                count++;
                continue;
            }
            else
            {
                ll a,b;
                a = v[i].first;
                b = v[i].second;
                ll x,y;
                x = find_parent(a);
                y = find_parent(b);
                parent[x] = y;
            }
        }
        ll counti[n+1];
        vector <ll> ans;
        for(int i=0;i<=n;i++)
            counti[i] = 0;
        for(int i=0;i<n;i++)
            counti[parent[i]]+=1;
        ll sum=0;
        for(int j=0;j<n;j++)
            if(counti[j])
                sum += (counti[j]*(counti[j]-1))/2;
        for(int i=query.size()-1;i>=0;i--)
        {
            if(query[i].first == 'Q')
            {
                ll ansi = (n*(n-1))/2 - sum;
                ans.push_back(ansi);
            }
            else if(query[i].first == 'R')
            {
                ll a,b;
                a = v[query[i].second].first;
                b = v[query[i].second].second;
                ll x,y;
                x = find_parent(a);
                y = find_parent(b);
                if(x != y)
                {
                    ll c,d,newe;
                    c = (counti[x]*(counti[x]-1))/2;
                    d = (counti[y]*(counti[y]-1))/2;
                    parent[x] = y;
                    counti[y] += counti[x];
                    counti[x] = 0;
                    newe = (counti[y]*(counti[y]-1))/2;
                    sum = sum - c - d + newe;
                }
            }
        }
        for(int j=ans.size()-1;j>=0;j--)
            printf("%d\n",ans[j]);
        printf("\n");
    }   
return 0;
}  