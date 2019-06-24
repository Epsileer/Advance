/**	epsileer 28 May 2019  10:11:29  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> gp[2000000],visited(2000000),dist(2000000);

void clr(){
	for(int i=0;i<2000000;i++){
		gp[i].clear();
		visited[i] = 0;
	}
}

int bfs(int s){
	for(int i=0;i<2000000;i++){
		visited[i] = 0;
		dist[i] = 0;
	}
	queue<int> q; q.push(s);
	while(!q.empty()){
		int u = q.front();
		visited[u] = 1;
		q.pop();
		for(auto v: gp[u]){
			if(!visited[v]){
				visited[v] = 1;
				dist[v] = dist[u] + 1;
				q.push(v);
			}
		}
	}
	int mx = 0;
	for(int i=0;i<2000000;i++){
		if(dist[mx] < dist[i])
			mx = i;
	}
	return mx;
}

void solve(){
	clr();
	int n,m,s=0; cin>>m>>n;
	vector< vector<char> > mtr(n,vector<char>(m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>mtr[i][j];
		}
	}
	int c = 0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			c++;
			if(mtr[i][j]=='.'){
				if(s == 0)
					s = c;
				if((i-1)>=0){
					if(mtr[i-1][j]=='.'){
						gp[c].push_back(c-m);
					}
				}
				if((i+1)<n){
					if(mtr[i+1][j]=='.'){
						gp[c].push_back(c+m);
					}
				}
				if((j-1)>=0){
					if(mtr[i][j-1]=='.'){
						gp[c].push_back(c-1);
					}
				}
				if((j+1)<m){
					if(mtr[i][j+1]=='.'){
						gp[c].push_back(c+1);
					}
				}
			}
		}
	}

	cout<<"Maximum rope length is "<<dist[bfs(bfs(s))]<<endl;

}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    	solve();
return 0;
}