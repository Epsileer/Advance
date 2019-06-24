/**	epsileer 10 June 2019  22:58:21  **/	
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
	int n; cin>>n;
	string s[n];
	vector<int> gp[26], ans, indeg(26);

	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=1;i<n;i++){
		int a,b; a=b=0;
		bool flag = true;
		while(a<s[i].size() && b<s[i-1].size()){
			if(s[i][a] == s[i-1][b])
				++a,++b;
			else{
				gp[s[i-1][b]-'a'].PB(s[i][a]-'a');
				indeg[s[i][a]-'a']++;
				flag = false;
				break;
			}
		}
		if(flag && s[i-1].size() > s[i].size()){
			cout<<"Impossible";
			return;
		}
	}

	set<int> minHeap;
	for(int i=0;i<26;i++)
		if(!indeg[i])
			minHeap.insert(i);

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
	if(ans.size() != 26){
		cout<<"Impossible";
		return;
	}
	for(int i=0;i<26;i++)
		cout<<(char)(ans[i]+'a');
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
  	int t=4;
  	bool b = (t);
  	cout<<b<<endl;
  	while(t--)
    	solve();
return 0;
}