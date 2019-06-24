/**	epsileer 28 May 2019  09:48:10  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> gp[20000],visited(20000),dist(20000);

void clr(){
	for(int i=0;i<20000;i++){
		visited[i] = 0;
		dist[i] = 0;
	}
}

int bfs(int s){
	clr();
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u = q.front();
		q.pop();
		for(auto v: gp[u]){
			if(!visited[v]){
				visited[v] = 1;
				dist[v] = dist[u]+1;
				q.push(v);
			}
		}
	}
	int mx=0;
	for(int i=0;i<20000;i++)
		if(dist[mx] < dist[i])
			mx = i;
	return mx;
}

void solve(){
	int n; cin>>n;
	for(int i=0;i<n-1;i++){
		int x,y; cin>>x>>y; --x; --y;
		gp[x].push_back(y);
		gp[y].push_back(x);
	}
	cout<<dist[bfs(bfs(0))];
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    // int t;cin>>t;
    // while(t--)
    	solve();
return 0;
}