/**	epsileer 28 May 2019  09:41:30  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> gp[20000],visited(20000);

void dfs(int u){
	visited[u] = 1;
	visited[19999]++;
	for(auto v: gp[u]){
		if(!visited[v])
			dfs(v);
	}
}

void solve(){
	int n,m; cin>>n>>m;
	bool flag = true;
	if(m != n-1)
		flag = false;
	for(int i=0;i<m;i++){
		int x,y; cin>>x>>y; --x; --y;
		gp[x].push_back(y);
		gp[y].push_back(x);
	}
	if(flag){
		dfs(0);
		if(visited[19999]==n)
			cout<<"YES";
		else
			cout<<"NO";
	}
	else
		cout<<"NO";
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    // int t;cin>>t;
    // while(t--)
    	solve();
return 0;
}