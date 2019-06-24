/**	epsileer 04 June 2019  10:28:39  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> PII;
#define PB push_back
#define MP make_pair
#define F first
#define S second

vector<LL> p(100000),size(100000,1);

void clr(LL n){
	for(LL i=1;i<=n;i++){
		size[i] = 1;
	}
}

LL find_set(LL x){
	if(p[x] == x) return x;
	return p[x] = find_set(p[x]);
}

void solve(){
	LL n; cin>>n;
	clr(n);
	for(LL i=1;i<=n;i++) p[i] = i;
	vector<PII> edge; edge.PB(MP(0,0));
	for(LL i=0;i<n-1;i++){
		LL u,v; cin>>u>>v;
		edge.PB(MP(u,v));
	}
	vector<LL> nt(n+1);
	LL q; cin>>q;
	stack<PII> st;
	for(LL i=0;i<q;i++){
		char ch; cin>>ch;
		if(ch == 'Q')
			st.push(MP(0,0));
		else{
			LL x; cin>>x;
			nt[x] = 1;
			st.push(MP(1,x));
		}
	}

	LL ans = n*(n-1)/2;

	for(LL i=1;i<=n-1;i++){
		if(!nt[i]){
			LL x = find_set(edge[i].F), y = find_set(edge[i].S);
			ans += size[x]*(size[x]-1)/2;
			ans += size[y]*(size[y]-1)/2;
			p[y] = x;
			size[x] += size[y];
			ans -= size[x]*(size[x]-1)/2;
		}
	}

	stack<LL> answer;

	while(!st.empty()){
		auto t = st.top(); st.pop();
		if(t.F){
			LL i=t.S;
			LL x = find_set(edge[i].F), y = find_set(edge[i].S);
			ans += size[x]*(size[x]-1)/2;
			ans += size[y]*(size[y]-1)/2;
			p[y] = x;
			size[x] += size[y];
			ans -= size[x]*(size[x]-1)/2;
		}
		else{
			answer.push(ans);
		}
	}

	while(!answer.empty()){
		cout<<answer.top()<<endl;
		answer.pop();
	}

	cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    LL t;cin>>t;
    while(t--)
    	solve();
return 0;
}