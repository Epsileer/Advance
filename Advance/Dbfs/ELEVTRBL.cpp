/**	epsileer 28 May 2019  16:54:12  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> gp[2000000],visited(2000000),dist(2000000);

int bfs(int s, int g){
	queue<int> q; q.push(s);
	while(!q.empty()){
		int u = q.front(); q.pop();
		visited[u] = true;
		for(auto v: gp[u]){
			if(!visited[v]){
				visited[v] = 1;
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
	return dist[g];
}

void solve(){
	int f,s,g,u,d; cin>>f>>s>>g>>u>>d;
	for(int i=1;i<=f;i++){
		if(i+u <= f){
			gp[i].push_back(i+u);
		}
		if(i-d >= 1){
			gp[i].push_back(i-d);
		}
	}

	if(s==g)
		cout<<0;
	else{
		int x = bfs(s,g);
		if(x == 0){
			cout<<"use the stairs";
		}
		else
			cout<<x;
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    // int t;cin>>t;
    // while(t--)
    	solve();
return 0;
}