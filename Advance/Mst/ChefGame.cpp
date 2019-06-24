/**	epsileer 05 June 2019  23:06:47  **/	
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
	LL n,d; cin>>n>>d;
	vector<vector<LL>> node(n, vector<LL>(d));
	vector<PII> gp[n];

	for(LL i=0;i<n;i++){
		for(LL j=0;j<d;j++)
			cin>>node[i][j];
	}

	for(LL i=0;i<n;i++){
		for(LL j=i+1;j<n;j++){
			LL dist = 0;
			for(LL k=0;k<d;k++){
				dist += (node[i][k]-node[j][k]) * (node[i][k]-node[j][k]);
			}
			gp[i].PB(MP(dist, j));
			gp[j].PB(MP(dist, i));
		}
	}

	LL ans = 1, count = 0;
	vector<LL> visited(n);
	priority_queue<PII> pq;
	pq.push(MP(1,0));

	while(!pq.empty()){
		auto u = pq.top(); pq.pop();
		if(!visited[u.S] && u.F != 0){
			u.F %= 747474747;
			ans *= u.F;
			ans %= 747474747;
			visited[u.S] = 1;
			count ++;
			if(count == n)
				break;
		}
		else
			continue;
		for(auto v: gp[u.S]){
			if(!visited[v.S]){
				pq.push(MP(v.F, v.S));
			}
		}
	}

	cout<<ans<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    LL t;cin>>t;
    while(t--)
    	solve();
return 0;
}