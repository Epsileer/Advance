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

vector<LL> gp[200000],gp2[200000], visited(200000), comp(200000), in(200000);
LL component = 0;
stack<LL> st;
set<LL> gp3[200000];

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
		for(auto j: gp2[i]){
			if(comp[i] == comp[j])
				continue;
			if(gp3[comp[i]].find(comp[j]) == gp3[comp[i]].end()){
				in[comp[j]]++;
				gp3[comp[i]].insert(comp[j]);
			}
		}
	}
	LL count = 0, c;
	for(int i=1;i<=component;i++){
		if(in[i] == 0){
			count++;
			c = i;
		}
	}

	if(count == 1){
		count = 0;
		for(int i=1;i<=n;i++)
			if(comp[i] == c)
				count++;
		cout<<count<<endl;
		for(int i=1;i<=n;i++)
			if(comp[i] == c)
				cout<<i<<" ";
	}
	else
		cout<<0;

}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
  	LL t=1;
  	while(t--)
    	solve();
return 0;
}