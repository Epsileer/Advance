/**	epsileer 29 May 2019  15:13:19  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define fi first
#define se second

struct poll{
	ll dist, last, vertex, vi;
	poll(ll a, ll b, ll c, ll d){
		dist = a;
		last = b;
		vertex = c;
		vi = d;
	}
};

struct comp{
	bool operator()(poll const &x, poll const &y){
		if(x.dist > y.dist)
			return true;
		else if(x.dist == y.dist)
			return x.last > y.last;
		return false;
	}
};

vector<pair<ll,ll>> gp[30000];
vector<poll> node;
ll n,m,ans1=0,ans2=0; 

void clr(){
	node.clear();
	for(ll i=0;i<n;i++){
		node.push_back(poll(1e15,1e15,i,0));
		gp[i].clear();
	}
	node[0].dist = 0;
	node[0].last = 0;
	node[0].vi = 1;
}

void dijkstra(){
	priority_queue<poll, vector<poll>, comp> pq;
	pq.push(node[0]);

	while(!pq.empty()){
		poll p = pq.top(); pq.pop();
		node[p.vertex].vi = 1;
		for(auto v: gp[p.vertex]){
			if(!node[v.fi].vi && v.se + p.dist < node[v.fi].dist){
				node[v.fi].dist = v.se + p.dist;
				node[v.fi].last = v.se;
				pq.push( poll( node[v.fi].dist, v.se, v.fi, 0 ) );
			}
			else if( !node[v.fi].vi && ( v.se + p.dist == node[v.fi].dist &&  node[v.fi].last > v.se) ){
				pq.push( poll( node[v.fi].dist, v.se, v.fi, 0 ) );
			}
		}
	}
	for(int i=0;i<n;i++){
		if(node[i].last == 1e15){
			ans1 = -1;
			break;
		}
		else{
			ans1 += node[i].last;
		}
	}
}

void prims(){
	priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
	pq.push(make_pair(0,0));
	vector<int> visited(n,0);
	visited[0] = 1;
	int count = 0;

	while(!pq.empty()){
		pair<int,int> p = pq.top(); pq.pop();
		visited[p.se] = 1;
		ans2 += p.fi;
		count ++;
		if(count == n)
			break;
		for(auto v: gp[p.se]){
			if(!visited[v.fi]){
				pq.push(make_pair(v.se, v.fi));
			}
		}
	}
}

void solve(){
	cin>>n>>m;
	clr();
	for(ll i=0;i<m;i++){
		ll u,v,w; cin>>u>>v>>w;
		gp[u].push_back(make_pair(v,w));
		gp[v].push_back(make_pair(u,w));
	}
	ans1 = 0; ans2 = 0;
	dijkstra();
	prims();

	if(ans1 == ans2)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--)
    	solve();
return 0;
}