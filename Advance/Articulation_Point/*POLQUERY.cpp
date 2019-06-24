/**	epsileer 07 June 2019  06:20:07  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> PII;
#define PB push_back
#define MP make_pair
#define F first
#define S second

vector<int> gp[200000], visited(200000), low(200000), articulation_point(200000);
int timer=0, c = 0, root = 1;
map<LL,LL> mp;

void dfs(int u, int p = -1){
	visited[u] = low[u] = ++timer;
	for(auto v: gp[u]){
		if(visited[v]){
			low[u] = min(low[u], visited[v]);
		}
		else{
			dfs(v, u);
			low[u] = min(low[u], low[v]);
			cout<<u<<" "<<v<<" .. "<<visited[u]<<" :::::::: "<<low[v]<<endl;
			if(visited[u] < low[v]){
				cout<<1<<endl;
				int x,y; x = min(u,v); y = max(u,v);
				mp[x*1000000+y] = 1;
			}
			if(visited[u] <= low[v] && u != root){
				cout<<2<<endl;
				articulation_point[u] = 1;
			}
			if(u == root)
				c++;
		}
	}
}

bool isbridge(int g1, int g2){
	if(g1 > g2)
		swap(g1,g2);
	if(mp.find(g1*1000000+g2) != mp.end())
		return true;
	else
		return false;
}

void solve(int n, int m){
	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		gp[u].PB(v);
		gp[v].PB(u);
	}

	dfs(1);
	if(c >= 2)
		articulation_point[1] = 1;

	for(int i=1;i<=n;i++)
		cout<<articulation_point[i]<<" ";
	cout<<endl;

	int q; cin>>q;

	while(q--){
		int type; cin>>type;
		if(type == 1){
			int u,v,g1,g2; cin>>u>>v>>g1>>g2;
			if(isbridge(g1, g2))
				cout<<"da"<<endl;
			else
				cout<<"ne"<<endl;
		}
		else{
			int u,v,c; cin>>u>>v>>c;
			if(articulation_point[c])
				cout<<"da"<<endl;
			else
				cout<<"ne"<<endl;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m; cin>>n>>m;
    solve(n, m);
return 0;
}