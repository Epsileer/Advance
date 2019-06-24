/**	epsileer 08 June 2019  11:02:37  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> PII;
#define PB push_back
#define MP make_pair
#define F first
#define S second

vector<LL> gp[200000],gp2[200000], visited(200000), comp(200000);
LL component = 0;
stack<LL> st;
set<LL> gp3[200000];
vector<PII> comp_cost(20000);

void dfs(LL u){
	visited[u] = 1;
	for(auto v: gp[u]){
		if(!visited[v])
			dfs(v);
	}
	st.push(u);
}

void dfs2(LL u){
	comp[u] = component;
	visited[u] = 0;
	for(auto v: gp2[u]){
		if(visited[v])
			dfs2(v);
	}
}

void dfs3(LL u){
	visited[u] = 1;
	for(auto v: gp3[u]){
		if(!visited[v]){
			dfs3(v);
			comp_cost[u].S = max(comp_cost[u].S, comp_cost[v].F + comp_cost[v].S);
		}
	}
}

void solve(){
	LL n,m; cin>>n>>m;
	vector<LL> cost(n+1);

	for(LL i=1;i<=n;i++) cin>>cost[i];

	for(LL i=0;i<m;i++){
		LL u,v; cin>>u>>v;
		gp[u].PB(v);
		gp2[v].PB(u);
	}

	for(LL i=1;i<=n;i++){
		if(!visited[i]){
			dfs(i);
		}
	}

	while(!st.empty()){
		LL i = st.top(); st.pop();
		if(visited[i]){
			component++;
			dfs2(i);
		}
	}

	for(LL i=1;i<=n;i++){
		comp_cost[comp[i]].F += cost[i];
	}
	for(LL i=1;i<=component;i++)
		comp_cost[i].S = 0;

	for(LL i=1;i<=n;i++){
		for(auto j: gp2[i]){
			if(comp[i] == comp[j])
				continue;
			gp3[comp[i]].insert(comp[j]);
		}
	}

	for(LL i=component;i>=1;i--){
		for(auto j: gp3[i])
			comp_cost[j].S = max(comp_cost[j].S, comp_cost[i].F + comp_cost[i].S);
	}

	// for(LL i=1;i<=component;i++)
	// 	if(!visited[i])
	// 		dfs3(i);

	for(LL i=1;i<=n;i++)
		cout<<comp_cost[comp[i]].F+comp_cost[comp[i]].S<<" ";

}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
  	LL t=1;
  	while(t--)
    	solve();
return 0;
}