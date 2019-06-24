/**	epsileer 07 June 2019  04:15:20  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> PII;
#define PB push_back
#define MP make_pair
#define F first
#define S second

vector<int> gp[20000], visited(20000), low(20000);
set<int> ans;
int timer,c,root=1;

void clr(int n){
	for(int i=1;i<=n;i++){
		gp[i].clear();
		visited[i] = 0;
		low[i] = 0;
	}
	ans.clear();
	timer = 0;
	c = 0;
}

void dfs(int u, int p = -1){
	visited[u] = low[u] = ++timer;
	for(auto v: gp[u]){
		if(v == p) continue;
		if(visited[v]){
			low[u] = min(low[u], visited[v]);
		}
		else{
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			if(visited[u] <= low[v] && u != root)
				ans.insert(u);
			if(u == root)
				c++;
		}
	}
}

void solve(int n, int m){
	clr(n);
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		gp[u].PB(v);
		gp[v].PB(u);
	}
	dfs(1);
	if(c >= 2)
		ans.insert(1);
	cout<<ans.size()<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m;
    while(cin>>n>>m && (n || m))
    	solve(n, m);
return 0;
}