#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector <ll> tree_x(500000,0);vector <ll> tree_y(500000,0);vector <ll> tree_z(500000,0);
vector <ll> lazy_x(500000,0);vector <ll> lazy_y(500000,0);vector <ll> lazy_z(500000,0);
 
void clr(){
    for(int i=0;i<500000;i++){
        tree_x[i] = 0;
        tree_y[i] = 0;
        tree_z[i] = 0;
        lazy_x[i] = 0;
        lazy_y[i] = 0;
        lazy_z[i] = 0;
    }
}
 
void update_x(ll start, ll end, ll v, ll l, ll r)
{
    if(lazy_x[v] != 0)
    {
        tree_x[v] = lazy_x[v];
        if(start != end){
            ll mid = (start+end)/2;
            lazy_x[2*v] = abs((mid-start+1) - lazy_x[v]);
            lazy_x[2*v+1] = abs((end-(mid+1)+1) - lazy_x[v]);
        }
        lazy_x[v] = 0;
    }
    if(r < start || l > end)
        return;
    if(l<=start && r>=end)
    {
        tree_x[v] = abs((end-start+1) - tree_x[v]);
        if(start != end)
        {
            ll mid = (start+end)/2;
            lazy_x[2*v] = abs((mid-start+1) - tree_x[v]);
            lazy_x[2*v+1] = abs((end-(mid+1)+1) - tree_x[v]);
        }
        return;
    }
    ll mid = (start+end)/2;
    update_x(start,mid,2*v,l,r);
    update_x(mid+1,end,2*v+1,l,r);
    tree_x[v] = tree_x[2*v]+tree_x[2*v+1];
}
 
void update_y(ll start, ll end, ll v, ll l, ll r)
{
    if(lazy_y[v] != 0)
    {
        tree_y[v] = lazy_y[v];
        if(start != end){
            ll mid = (start+end)/2;
            lazy_y[2*v] = abs((mid-start+1) - lazy_y[v]);
            lazy_y[2*v+1] = abs((end-(mid+1)+1) - lazy_y[v]);
        }
        lazy_y[v] = 0;
    }
    if(r < start || l > end)
        return;
    if(l<=start && r>=end)
    {
        tree_y[v] = abs((end-start+1) - tree_y[v]);
        if(start != end)
        {
            ll mid = (start+end)/2;
            lazy_y[2*v] = abs((mid-start+1) - tree_y[v]);
            lazy_y[2*v+1] = abs((end-(mid+1)+1) - tree_y[v]);
        }
        return;
    }
    ll mid = (start+end)/2;
    update_y(start,mid,2*v,l,r);
    update_y(mid+1,end,2*v+1,l,r);
    tree_y[v] = tree_y[2*v]+tree_y[2*v+1];
}
 
void update_z(ll start, ll end, ll v, ll l, ll r)
{
    if(lazy_z[v] != 0)
    {
        tree_z[v] = lazy_z[v];
        if(start != end){
            ll mid = (start+end)/2;
            lazy_z[2*v] = abs((mid-start+1) - lazy_z[v]);
            lazy_z[2*v+1] = abs((end-(mid+1)+1) - lazy_z[v]);
        }
        lazy_z[v] = 0;
    }
    if(r < start || l > end)
        return;
    if(l<=start && r>=end)
    {
        tree_z[v] = abs((end-start+1) - tree_z[v]);
        if(start != end)
        {
            ll mid = (start+end)/2;
            lazy_z[2*v] = abs((mid-start+1) - tree_z[v]);
            lazy_z[2*v+1] = abs((end-(mid+1)+1) - tree_z[v]);
        }
        return;
    }
    ll mid = (start+end)/2;
    update_z(start,mid,2*v,l,r);
    update_z(mid+1,end,2*v+1,l,r);
    tree_z[v] = tree_z[2*v]+tree_z[2*v+1];
}
 
ll query_x(ll start, ll end, ll v, ll l, ll r)
{
    if(lazy_x[v] != 0)
    {
        tree_x[v] = lazy_x[v];
        if(start != end)
        {
            ll mid = (start + end)/2;
            lazy_x[2*v] = abs((mid-start+1) - lazy_x[v]);
            lazy_x[2*v+1] = abs((end-(mid+1)+1) - lazy_x[v]);
        }
        lazy_x[v] = 0;
    }
    if(r<start || l>end)
        return 0;
    if(l<=start && r>=end)
        return tree_x[v];
    ll mid = (start + end)/2;
    return (query_x(start,mid,2*v,l,r) + query_x(mid+1,end,2*v+1,l,r));
}
 
ll query_y(ll start, ll end, ll v, ll l, ll r)
{
    if(lazy_y[v] != 0)
    {
        tree_y[v] = lazy_y[v];
        if(start != end)
        {
            ll mid = (start + end)/2;
            lazy_y[2*v] = abs((mid-start+1) - lazy_y[v]);
            lazy_y[2*v+1] = abs((end-(mid+1)+1) - lazy_y[v]);
        }
        lazy_y[v] = 0;
    }
    if(r<start || l>end)
        return 0;
    if(l<=start && r>=end)
        return tree_y[v];
    ll mid = (start + end)/2;
    return (query_y(start,mid,2*v,l,r) + query_y(mid+1,end,2*v+1,l,r));
}
 
ll query_z(ll start, ll end, ll v, ll l, ll r)
{
    if(lazy_z[v] != 0)
    {
        tree_z[v] = lazy_z[v];
        if(start != end)
        {
            ll mid = (start + end)/2;
            lazy_z[2*v] = abs((mid-start+1) - lazy_z[v]);
            lazy_z[2*v+1] = abs((end-(mid+1)+1) - lazy_z[v]);
        }
        lazy_z[v] = 0;
    }
    if(r<start || l>end)
        return 0;
    if(l<=start && r>=end)
        return tree_z[v];
    ll mid = (start + end)/2;
    return (query_z(start,mid,2*v,l,r) + query_z(mid+1,end,2*v+1,l,r));
}
 
int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--)
    {
        clr();
        ll x,y,z,q;cin>>x>>y>>z>>q;
        x--;y--;z--;
        for(int i=1;i<=q;i++)
        {
            ll a;cin>>a;
            if(a == 0){
                ll c,d;cin>>c>>d;
                update_x(0,x,1,c,d);
            }
            else if(a == 1){
                ll c,d;cin>>c>>d;
                update_y(0,y,1,c,d);
            }
            else if(a == 2){
                ll c,d;cin>>c>>d;
                update_z(0,z,1,c,d);
            }
            else if(a == 3)
            {
                ll x1,y1,z1,x2,y2,z2;cin>>x1>>y1>>z1>>x2>>y2>>z2;
                ll r1,r2,r3,g1,g2,g3;
                r1 = query_x(0,x,1,x1,x2);
                r2 = query_y(0,y,1,y1,y2);
                r3 = query_z(0,z,1,z1,z2);
                g1 = abs(x2-x1+1-r1);
                g2 = abs(y2-y1+1-r2);
                g3 = abs(z2-z1+1-r3);
                cout<<r1*r2*r3 + r1*g2*g3 + g1*r2*g3 + g1*g2*r3<<endl;
            }
        }
 
    }
return 0;
}