/**	epsileer 11 May 2019  11:58:11  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

struct point
{	
	int c,p;

	point(int x, int y){
		c = x;
		p = y;
	}
};

vector<point> ds;

int find_set(int x){
	if(ds[x].p == x)
		return x;
	return ds[x].p = find_set(ds[x].p);
}

void solve(){

	int n,m; cin>>n>>m;

	vector<pair<int,int>> edge(m);

	for(int i=0;i<m;i++){
		cin>>edge[i].first>>edge[i].second;
		--edge[i].first; --edge[i].second;
	}

	for(int i=0;i<n;i++){
		int x; cin>>x;
		if(x < 0)
			ds.push_back(point(INT_MAX, i));
		else
			ds.push_back(point(x, i));
	}

	for(int i=0;i<m;i++){
		int x = edge[i].first;
		int y = edge[i].second;
		if(find_set(x) != find_set(y)){
			if(ds[find_set(x)].c < ds[find_set(y)].c)
				ds[find_set(y)].p = ds[find_set(x)].p;
			else
				ds[find_set(x)].p = ds[find_set(y)].p;
		}
	}

	set<int> st;

	for(int i=0;i<n;i++){
		st.insert(find_set(i));
	}

	int cost = 0;

	if(st.size()==1)
		cost = 0;
	else{
		int mn = INT_MAX;
		for(auto i: st){
			if(ds[i].c == INT_MAX){
				cost = -1;
				break;
			}
			if(ds[i].c < mn)
				mn = ds[i].c;
			cost += ds[i].c;
		}

		if(cost != -1)
			cost += mn*(st.size()-2);
	}

	cout<<cost;
	
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    // int t;cin>>t;
    // while(t--)
    	solve();
return 0;
}