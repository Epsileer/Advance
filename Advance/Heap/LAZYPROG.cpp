/**	epsileer 10 May 2019  14:21:02  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

struct point
{
	ld r,a,b,d;
	point(ld w, ld x, ld y, ld z){
		r = w;
		a = x;
		b = y;
		d = z;
	}
};

struct cmp
{
	bool operator()(point const &x, point const &y){
		return x.r < y.r;
	}
};

void solve(){
	priority_queue<point, vector<point>, cmp> pq;
	ld n; cin>>n;
	ld a,b,d,ans=0.00;
	while(n--){
		cin>>a>>b>>d;
		pq.push(point((ld)b/a, a, b, d));
	}
	ld day = 0.00;
	while(!pq.empty()){
		point p = pq.top();
		p.b -= min(p.b, max((ld)0, p.d - day));
		day += p.b;
		ans += (ld)p.b/p.a;
		pq.pop();
	}
	cout<<setprecision(3)<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    	solve();
return 0;
}