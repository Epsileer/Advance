/**	epsileer 08 June 2019  16:31:14  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> PII;
#define PB push_back
#define MP make_pair
#define F first
#define S second



void solve(){
	int n,m; cin>>n>>m;
	vector<int> gp[n+1], indeg(n+1), ans;
	set<int> minHeap;

	for(int i=0;i<m;i++){
		int u,v; cin>>u>>v;
		gp[u].PB(v);
		indeg[v]++;
	}
	for(int i=1;i<=n;i++){
		if(!indeg[i])
			minHeap.insert(i);
	}

	while(!minHeap.empty()){
		int u = *minHeap.begin();
		minHeap.erase(minHeap.begin());
		ans.PB(u);
		for(auto v: gp[u]){
			indeg[v]--;
			if(!indeg[v])
				minHeap.insert(v);
		}
	}

	if(ans.size()!=n)
		cout<<"Sandro fails.";
	else{
		for(auto i: ans)
			cout<<i<<" ";
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
  	int t=1;
  	while(t--)
    	solve();
return 0;
}