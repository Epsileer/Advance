/**	epsileer 29 May 2019  21:27:01  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define PB push_back
#define MP make_pair
#define F first
#define S second

vector<pair<LL,LL>> gp[300000];
vector<LL> visited(300000),dist(300000,1e15);
int n, m; 

LL dijkstra(){
	dist[0] = 0;
	priority_queue<pair<LL,LL>, vector<pair<LL,LL>>, greater<pair<LL,LL>>> pq;
	pq.push(MP(0,0));
	while(!pq.empty()){
		pair<LL,LL> p = pq.top(); pq.pop();
		if(visited[p.S])
			continue;
		visited[p.S] = 1;
		for(auto v: gp[p.S]){
			if(v.S + dist[p.S] < dist[v.F]){
				dist[v.F] = v.S + dist[p.S];
				pq.push(MP(dist[v.F], v.F));
			}
		}
	}
	return dist[2*n+1];
}

void solve(){
	cin >> n >> m;
	vector< LL > h(n), c(n);
	for(int i = 0; i < n; i++){
		cin >> h[i];
	}
	for(int i = 0; i < n; i++){
		cin >> c[i];
		gp[i+1].PB(MP(n+i+1, c[i]));
		gp[n+i+1].PB(MP(i+1, c[i]));
	}
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		if(h[u-1] <= h[v-1]){
			gp[u].PB(MP(v,0));
		}
		if(h[u-1] >= h[v-1]){
			gp[u+n].PB(MP(v+n,0));
		}

		if(h[v-1] <= h[u-1]){
			gp[v].PB(MP(u,0));
		}

		if(h[v-1] >= h[u-1]){
			gp[v+n].PB(MP(u+n,0));
		}
	}
	gp[0].PB(MP(1,c[0]));
	gp[0].PB(MP(n+1,c[0]));
	gp[n].PB(MP(2*n+1,0));
	gp[2*n].PB(MP(2*n+1,0));

	LL ans = dijkstra();

	if(ans != 1e15)
		cout<<ans;
	else
		cout<<-1;

}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    // int t;cin>>t;
    // while(t--)
    	solve();
return 0;
}