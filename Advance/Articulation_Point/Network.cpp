/**	epsileer 06 June 2019  23:00:42  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> PII;
#define PB push_back
#define MP make_pair
#define F first
#define S second

vector<int> gp[200], visited(200), low(200);
set<int> ans;
int timer = 0, c = 0, root;

void dfs(int u, int p = -1){
	visited[u] = low[u] = ++timer;
	for(auto v: gp[u]){
		if(v == p) continue;
		if(visited[v]){
			low[u] = min(low[u], visited[v]);
		}
		else{
			dfs(v,u);
			low[u] = min(low[u], low[v]);
			if(visited[u] <= low[v] && u != root){
				ans.insert(u);
			}
			if(u == root)
				c++;
		}
	}
}

void solve(int n){
	cin.ignore();
	for(int i=1;i<=n;i++){
		gp[i].clear();
		visited[i] = 0;
		low[i] = 0;
	}
	ans.clear();
	c = 0;
	timer = 0;

	string s;
    while (getline(cin, s), s != "0")
    {
        stringstream ss(s);
        int u, v;
        ss >> u;
        while (ss >> v)
        {
            gp[u].PB(v);
            gp[v].PB(u);
        }
    }

    for(int i=1;i<=n;i++){
    	if(!visited[i]){
    		root = i;
    		c = 0;
    		dfs(i);
    		if(c >= 2) ans.insert(1);
    	}
    }
    cout<<ans.size()<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    while(cin>>t && t)
    	solve(t);
return 0;
}