/**	epsileer 03 June 2019  17:31:43  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define PB push_back
#define MP make_pair
#define F first
#define S second

void solve(){
	LL n,e,t,m; cin>>n>>e>>t>>m;
	vector<pair<LL,LL>> gp[100000];
	vector<LL> visited(n+1),dist(n+1,1e15);
	for(LL i=0;i<m;i++){
		LL u,v,w; cin>>u>>v>>w;
		gp[v].PB(MP(w,u));
	}
	dist[e] = 0;
	priority_queue<pair<LL,LL>, vector<pair<LL,LL>>, greater<pair<LL,LL>>> pq;
	pq.push(MP(0,e));
	while(!pq.empty()){
		pair<LL,LL> u = pq.top(); pq.pop();
		visited[u.S] = 1;
		for(auto v: gp[u.S]){
			if(!visited[v.S] && dist[u.S]+v.F < dist[v.S]){
				dist[v.S] = dist[u.S] + v.F;
				pq.push(MP(dist[v.S], v.S));
			}
		}
	}
	LL ans = 0;
	for(LL i=1;i<=n;i++){
		if(dist[i] <= t)
			ans ++;
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