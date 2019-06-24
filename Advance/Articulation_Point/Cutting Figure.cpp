/**	epsileer 07 June 2019  10:39:01  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> PII;
#define PB push_back
#define MP make_pair
#define F first
#define S second

vector<int> gp[3000], visited(3000), low(3000);
set<int> ans;
int timer = 0, root = 1, c = 0, has = 0;

void dfs(int u, int p = -1){
	visited[u] = low[u] = ++timer;
	for(auto v: gp[u]){
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
	char square[n][m];
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>square[i][j];
			if(square[i][j] == '#')
				has++;
		}
	}

	if(has <= 2){
		cout<<-1;
		return;
	}

	int count = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			count++;
			if(square[i][j] != '#') continue;
			root = count;
			if((i-1 >= 0) && square[i-1][j] == '#')
				gp[count].PB(count-m);
			if((i+1 < n) && square[i+1][j] == '#')
				gp[count].PB(count+m);
			if((j+1 < m) && square[i][j+1] == '#')
				gp[count].PB(count+1);
			if((j-1 >= 0) && square[i][j-1] == '#')
				gp[count].PB(count-1);
		}
	}

	dfs(root);
	if(c >= 2)
		ans.insert(1);
	if(!ans.empty())
		cout<<1;
	else
		cout<<2;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n,m; cin>>n>>m;
    solve(n, m);
return 0;
}