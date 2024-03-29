#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef pair<ll,ll> pii;
typedef pair<pii,pii> D;

#define MaxN 100001
#define mp make_pair

vector<pii> decr[MaxN],incr[MaxN];
int _decr[MaxN],_incr[MaxN];
ll shortest[MaxN];
void solve()
{
	priority_queue<D> Q;
	ll x,y,wt, key,j,v;
	int src,snk,N,M;
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)	decr[i].clear(),incr[i].clear(),_decr[i] =0,_incr[i] = 0,shortest[i] = 1LL<<60;
	for(int i=1;i<=M;i++){
		scanf("%lld%lld%lld",&x,&y,&wt);
		decr[x].push_back(mp(-wt,y));
		decr[y].push_back(mp(-wt,x));
		incr[x].push_back(mp(wt,y));
		incr[y].push_back(mp(wt,x));
	}
	scanf("%d%d",&src,&snk);
	for(int i=1;i<=N;i++){
		sort(decr[i].begin(),decr[i].end());
		sort(incr[i].begin(),incr[i].end());
	}
	//Every Entry is key,steps,incroming edge wt,vertex
	Q.push(mp(mp(0,0),mp(0,src)));
	while(!Q.empty()){	
		D front = Q.top();
		Q.pop();
		v = front.second.second;
		wt = front.second.first;
		key = -front.first.first;
		shortest[v] = min(key,shortest[v]);
		if( front.first.second & 1){
			for(j= _incr[v];j<incr[v].size();j++){
				if ( wt > incr[v][j].first ){
					Q.push(mp(mp(-(key+incr[v][j].first),0),mp(incr[v][j].first,incr[v][j].second)));
				}
				else	break;
			}
			_incr[v] = j;	
		}
		else{
			for(j = _decr[v];j<decr[v].size();j++){
				if ( wt < -(decr[v][j].first) ){
					Q.push(mp(mp(-(key-decr[v][j].first),1),mp(-decr[v][j].first,decr[v][j].second)));
				}
                else    break;
			}
			_decr[v] = j;
		}
		if( shortest[snk] != (1LL<<60) )	break;
	}
	if(shortest[snk] != (1LL<<60))	printf("%lld\n",shortest[snk]);
	else	printf("No Solution\n");
}

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)	solve();
	return 0;
}