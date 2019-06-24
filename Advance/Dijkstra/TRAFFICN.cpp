/**	epsileer 01 June 2019  01:27:21  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define PB push_back
#define MP make_pair
#define F first
#define S second

void solve(){
	LL n,m,k,s,t; cin>>n>>m>>k>>s>>t;
	vector<pair<LL,LL>> gp[n+1];
	vector<pair<LL,LL>> gp2[n+1];
	for(LL i=0;i<m;i++){
		LL u,v,w; cin>>u>>v>>w;
		gp[u].PB(MP(w,v));
		gp2[v].PB(MP(w,u));
	}

	priority_queue<pair<LL,LL>, vector<pair<LL,LL>>, greater<pair<LL,LL>>> pq;
	vector<LL> visited(n+1,0), visited2(n+1,0), dist(n+1,1e15), dist2(n+1,1e15);
	pq.push(MP(0,s));
	dist[s] = 0;
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

	pq.push(MP(0,t));
	dist2[t] = 0;
	while(!pq.empty()){
		pair<LL,LL> u = pq.top(); pq.pop();
		visited2[u.S] = 1;
		for(auto v: gp2[u.S]){
			if(!visited2[v.S] && dist2[u.S]+v.F < dist2[v.S]){
				dist2[v.S] = dist2[u.S] + v.F;
				pq.push(MP(dist2[v.S], v.S));
			}
		}
	}

	LL ans = dist[t];

	for(int q=1;q<=k;q++){
		LL u,v,w; cin>>u>>v>>w;
		if(dist[u]+w < dist[v]){
			ans = min(ans, dist[u]+w+dist2[v]);
		}
		if(dist[v]+w < dist[u]){
			ans = min(ans, dist[v]+w+dist2[u]);
		}
	}

	if(ans != 1e15)
		cout<<ans<<endl;
	else
		cout<<-1<<endl;

}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    LL t;cin>>t;
    while(t--)
    	solve();
return 0;
}	