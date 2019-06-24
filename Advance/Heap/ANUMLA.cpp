/**	epsileer 07 May 2019  21:29:38  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve(){
	int n; cin>>n;
	multiset<ll> ms;
	vector<ll> ss;
	ss.push_back(0);
	vector<ll> ans; 

	for(int i=0;i<pow(2,n);i++){
		ll x; cin>>x;
		if(x)
			ms.insert(x);
	}

	while(!ms.empty()){
		ll x = *ms.begin();
		ans.push_back(x);
		ll sz = ss.size();
		for(int i=0;i<sz;i++){
			ms.erase(ms.lower_bound(ss[i]+x));
			ss.push_back(ss[i]+x);
		}
	}

	for(int i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
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