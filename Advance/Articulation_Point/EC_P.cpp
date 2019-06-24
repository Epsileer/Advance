/**	epsileer 07 June 2019  03:58:37  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> PII;
#define PB push_back
#define MP make_pair
#define F first
#define S second

vector<int> gp[1000], visited(1000), low(1000);
vector<PII> ans;
int root, timer = 0, test = 0;

void clr(int n){
	for(int i=0;i<=n;i++){
		gp[i].clear();
		visited[i] = 0;
		low[i] = 0;
	}
	ans.clear();
	timer = 0;
	test++;
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
			if(visited[u] < low[v])
				ans.PB(MP(min(u,v),max(u,v)));
		}
	}
}

bool comp(PII x, PII y){
	if(x.F < y.F)
		return true;
	if(x.F == y.F)
		return x.S < y.S;
	return false;
}

void solve(){
	int n,m; cin>>n>>m;
	clr(n);

	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		gp[u].PB(v);
		gp[v].PB(u);
	}

	for(int i=1;i<=n;i++){
		if(!visited[i])
			dfs(i);
	}

	cout<<"Caso #"<<test<<endl;
	if(ans.size() == 0){
		cout<<"Sin bloqueos"<<endl;
		return;
	}
	sort(ans.begin(), ans.end(), comp);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)
		cout<<ans[i].F<<" "<<ans[i].S<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    	solve();
return 0;
}