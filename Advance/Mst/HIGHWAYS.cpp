/**	epsileer 04 June 2019  11:56:42  **/	
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
	LL n,m,s,d; cin>>n>>m>>s>>d;
	vector<PII> gp[n+1];
	vector<LL> visited(n+1), dist(n+1, 1e15);

	for(LL i=0;i<m;i++){
		LL u,v,w; cin>>u>>v>>w;
		gp[u].PB(MP(w,v));
		gp[v].PB(MP(w,u));
	}

	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push(MP(0,s));
	dist[s] = 0;

	while(!pq.empty()){
		auto u = pq.top(); pq.pop();
		if(!visited[u.S]){
			visited[u.S] = 1;
		}
		else
			continue;
		for(auto v: gp[u.S]){
			if(!visited[v.S] && dist[u.S] + v.F < dist[v.S]){
				dist[v.S] = dist[u.S] + v.F;
				pq.push(MP(dist[v.S], v.S));
			}
		}
	}

	if(dist[d] == 1e15)
		cout<<"NONE"<<endl;
	else
		cout<<dist[d]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    LL t;cin>>t;
    while(t--)
    	solve();
return 0;
}