/**	epsileer 09 May 2019  11:29:15  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve(){
	set< pair<ll,int> > st;
	set< pair<ll,int> >::iterator it;

	int n; cin>>n;
	vector<int> gp[n];
	vector<ll> p(n);

	for(int i=0;i<n;i++){
		ll x; cin>>x;
		st.insert(make_pair(x,i));
		p[i] = x;
	}

	for(int i=0;i<n-1;i++){
		int x,y; cin>>x>>y; --x; --y;
		gp[x].push_back(y);
		gp[y].push_back(x);
	}

	for(int i=0;i<n;i++){
		st.erase(make_pair(p[i],i));
		for(auto j : gp[i]){
			st.erase(make_pair(p[j],j));
		}
		it = st.end(); --it;
		cout<<(*it).second+1<<" ";
		st.insert(make_pair(p[i],i));
		for(auto j : gp[i]){
			st.insert(make_pair(p[j],j));
		}
	}
	cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    	solve();
return 0;
}