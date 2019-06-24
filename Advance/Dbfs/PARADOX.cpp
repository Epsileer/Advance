/**	epsileer 28 May 2019  11:38:45  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> value(200,1);

void clr(){
	for(int i=0;i<200;i++){
		value[i] = 1;
	}
}

void solve(){
	while(true){
		clr();
		int n; cin>>n; if(n==0) break;
		vector< pair<int,int> > stmt;
		for(int i=0;i<n;i++){
			int x; string flag; cin>>x>>flag; --x;
			if(flag == "false"){
				stmt.push_back(make_pair(x,0));
				value[x] = value[i]^1;
			}
			else{
				stmt.push_back(make_pair(x,1));
				value[x] = value[i];
			}
		}
		bool ans = true;
		for(int i=0;i<stmt.size();i++){
			if(stmt[i].second == 0){
				if(value[i] == value[stmt[i].first])
					ans = false;
			}
			else{
				if(value[i] != value[stmt[i].first])
					ans = false;
			}
		}
		if(ans)
			cout<<"NOT PARADOX"<<endl;
		else
			cout<<"PARADOX"<<endl;
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    // int t;cin>>t;
    // while(t--)
    	solve();
return 0;
}