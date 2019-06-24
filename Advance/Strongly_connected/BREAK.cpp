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

vector<LL> gp[200000],gp2[200000], visited(200000), comp(200000), comp_cost(200000);
LL component = 0;
stack<LL> st;
set<LL> gp3[200000];

void clr(LL n){
	for(LL i=1;i<=n;i++){
		gp[i].clear();
		gp2[i].clear();
		gp3[i].clear();
		comp[i] = 0;
		comp_cost[i] = 0;
		component = 0;
		visited[i] = 0;
	}
}

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

void solve(){
	LL n,m; cin>>n>>m;

	clr(n);

	vector<LL> cost(n+1);

	for(LL i=1;i<=n;i++) cost[i] = 1;

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
		comp_cost[comp[i]] += cost[i];
	}

	for(LL i=1;i<=n;i++){
		for(auto j: gp[i]){
			if(comp[i] == comp[j])
				continue;
			gp3[comp[i]].insert(comp[j]);
		}
	}

	for(LL i=1;i<=component;i++){
		for(auto j: gp3[i]){
			comp_cost[j] += comp_cost[i];
		}
	}
	LL mx = 1;
	for(LL i=1;i<=component;i++){
		if(comp_cost[i] > comp_cost[mx])
			mx = i;
	}

	for(LL i=1;i<=n;i++){
		if(comp_cost[comp[i]] == comp_cost[mx])
			cout<<i<<" ";
	}
	cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
  	LL t=1; cin>>t;
  	while(t--)
    	solve();
return 0;
}