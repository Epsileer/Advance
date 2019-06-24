/**	epsileer 04 June 2019  11:25:31  **/	
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
	LL n; cin>>n;
	map<string, LL> mp;
	vector<PII> gp[20000];
	vector<LL> visited(20000);
	for(LL i=1;i<=n;i++){
		string s; cin>>s;
		mp[s] = i;
		LL p; cin>>p;
		for(LL j=1;j<=p;j++){
			LL v,w; cin>>v>>w;
			gp[i].PB(MP(w,v));
		}
	}

	priority_queue<PII, vector<PII>, greater<PII>> pq;
	pq.push(MP(0,1));
	LL ans = 0, count = 0;

	while(!pq.empty()){
		auto u = pq.top(); pq.pop();
		if(!visited[u.S]){
			visited[u.S] = 1;
			count++;
			ans += u.F;
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