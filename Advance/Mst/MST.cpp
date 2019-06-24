/**	epsileer 04 June 2019  01:54:50  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> PII;
#define PB push_back
#define MP make_pair
#define F first
#define S second

void solve(){
	LL n,m; cin>>n>>m;
	vector<pair<LL,LL>> gp[n+1];
	for(LL i=0;i<m;i++){
		LL u,v,w; cin>>u>>v>>w;
		gp[u].PB(MP(w,v));
		gp[v].PB(MP(w,u));
	}
	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push(MP(0,1));
	vector<LL> visited(n+1);
	LL ans = 0,count = 0;
	while(!pq.empty()){
		auto u = pq.top(); pq.pop();
		if(!visited[u.S]){
			visited[u.S] = 1;
			ans += u.F;
			count++;
			if(count == n)
				break;
		}
		else
			continue;
		for(auto v: gp[u.S]){
			if(!visited[v.S]){
				pq.push(MP(v.F, v.S));
			}
		}
	}

	cout<<ans;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    // LL t;cin>>t;
    // while(t--)
    	solve();
return 0;
}