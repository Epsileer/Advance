/**	epsileer 04 June 2019  16:27:36  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> PII;
#define PB push_back
#define MP make_pair
#define F first
#define S second

LL find_set(LL x, vector<LL> p){
	if(p[x] == x) return x;
	return p[x] = find_set(p[x], p);
}

void solve(){
	LL n,m; cin>>n>>m;
	vector<LL> mode(n+1);
	vector<pair<LL,PII>> edge; 
	for(LL i=1;i<=n;i++) cin>>mode[i];
	for(LL i=0;i<m;i++){
		LL u,v,w; cin>>u>>v>>w;
		edge.PB(MP(w,MP(u,v)));
	}
	sort(edge.begin(), edge.end());

	vector<LL> p; p.PB(0);
	LL ans = 0;

	for(LL i=1;i<=n;i++) p.PB(i);

	for(LL i=0;i<m;i++){
		LL u,v,w; u = edge[i].S.F; v = edge[i].S.S; w = edge[i].F;
		LL su = find_set(u, p);
		LL sv = find_set(v, p);

		if(su == sv)
			continue;

		else if(mode[u]==1 && mode[v]==1)
			continue;

		else if(mode[u]==0 && mode[v]==0){
			if(mode[su]==1 && mode[sv]==1)
				continue;
			else if(mode[su] == 1){
				p[sv] = su;
			}
			else if(mode[sv] == 1)
				p[su] = sv;
			else
				p[su] = sv;
			ans += w;
		}

		else if(mode[u]==1 && mode[v]==0){
			if(mode[sv] == 0){
				p[sv] = u;
				ans += w;
			}
		}

		else if(mode[u]==0 && mode[v]==1){
			if(mode[su] == 0){
				p[su] = v;
				ans += w;
			}
		}
	}

	bool flag = true;
	for(int i=1;i<=n;i++){
		if(mode[find_set(i,p)] == 0)
			flag = false;
	}

	if(flag)
		cout<<ans<<endl;
	else
		cout<<"impossible"<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    LL t;cin>>t;
    while(t--)
    	solve();
return 0;
}