/**	epsileer 07 June 2019  01:29:11  **/	
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
int timer = 0, root, c, test = 0;

void clr(int n){
	for(int i=0;i<n;i++){
		gp[i].clear();
		visited[i] = 0;
		low[i] = 0;
	}
	timer = 0;
	ans.clear();
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
			if(visited[u] <= low[v] && u != root)
				ans.insert(u);
			if(u == root)
				c++;
		}
	}
}


void solve(int n){
	clr(n);
	
	map<string, int> mp;
	map<int, string> mps;
	for(int i=0;i<n;i++){
		string s; cin>>s;
		mp[s] = i;
		mps[i] = s;
	}

	int m; cin>>m;

	for(int i=0;i<m;i++){
		string s1,s2; cin>>s1>>s2;
		int u = mp[s1], v = mp[s2];
		gp[u].PB(v);
		gp[v].PB(u);
	}

	for(int i=0;i<n;i++){
		if(!visited[i]){
			root = i;
			c = 0;
			dfs(i);
			if(c >= 2)
				ans.insert(i);
		}
	}

	cout<<"City map #"<<test<<": "<<ans.size()<<" camera(s) found"<<endl;
	for(auto i: ans)
		cout<<mps[i]<<endl;
	cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;
    while(cin>>t && t)
    	solve(t);
return 0;
}