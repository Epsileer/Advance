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

bool cmp(PII x, PII y){
	if(x.F < y.F)
		return true;
	else if(x.F == y.F && x.S < y.S)
		return true;
	return false;
}

void solve(){
	LL n; cin>>n;
	vector<LL> gp[n+1], indeg(n+1), ans;
	set<LL> minHeap;
	LL mat[n+1][n+1],cnt=0;

	for(LL i=1;i<=n;i++){
		string s; cin>>s; 
		for(LL j=0;j<n;j++){
			LL x = s[j]-'0'; mat[i][j+1] = x;
			if(x){
				gp[i].PB(j+1);
				indeg[j+1]++;
				cnt++;
			}
		}
	}
	for(LL i=1;i<=n;i++){
		if(!indeg[i])
			minHeap.insert(i);
	}

	while(!minHeap.empty()){
		LL u = *minHeap.begin();
		minHeap.erase(minHeap.begin());
		ans.PB(u);
		for(auto v: gp[u]){
			indeg[v]--;
			if(!indeg[v])
				minHeap.insert(v);
		}
	}

	vector<PII> answer;

	for(LL i=0;i<n;i++){
		for(LL j=i+1;j<n;j++){
			if(!mat[ans[i]][ans[j]]){
				answer.PB(MP(ans[i], ans[j]));
			}
		}
	}

	sort(answer.begin(), answer.end(), cmp);
	cout<<answer.size()<<endl;
	for(auto i: answer)
		cout<<i.F<<" "<<i.S<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
  	LL t=1;
  	while(t--)
    	solve();
return 0;
}