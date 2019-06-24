/**	epsileer 31 May 2019  22:26:25  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
#define PB push_back
#define MP make_pair
#define F first
#define S second

void solve(){
	int n; cin>>n;
	map<string, int> mp;
	vector<pair<int,int>> gp[20000];
	for(int i=1;i<=n;i++){
		string s; cin>>s; 
		mp[s] = i;
		int m; cin>>m;
		for(int j=1;j<=m;j++){
			int v,w; cin>>v>>w;
			gp[i].PB(MP(w, v));
			gp[v].PB(MP(w, i));
		}
	}

	int q; cin>>q;

	while(q--){
		string s1,s2; cin>>s1>>s2;
		int s = mp[s1], f = mp[s2];
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
		vector<int> visited(n+1,0),dist(n+1,INT_MAX);
		dist[s] = 0;
		pq.push(MP(0, s));
		while(!pq.empty()){
			pair<int,int> u = pq.top(); pq.pop();
			visited[u.S] = 1;
			for(auto v: gp[u.S]){
				if(!visited[v.S] && dist[u.S]+v.F < dist[v.S]){
					dist[v.S] = dist[u.S] + v.F;
					pq.push(MP(dist[v.S], v.S));
				}
			}
		}
		cout<<dist[f]<<endl;
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    	solve();
return 0;
}