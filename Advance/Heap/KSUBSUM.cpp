/**	epsileer 08 May 2019  02:36:12  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<ll> ob(3003);

void merge(vector<ll> cb, int c){
	vector<ll> ans;
	int i,j;
	for(i=0,j=0; i<c && j<c;){
		if(ob[i] > cb[j]){
			ans.push_back(ob[i]);
			i++;
		}
		else{
			ans.push_back(cb[j]);
			j++;
		}
	}
	for(int i=0;i<c;i++)
		ob[i] = ans[i];
}

void solve(){
	int n,a,b,c,i,j; cin>>n>>a>>b>>c; 

	multiset<ll> ms1;
	vector<ll> sum(n+1, 0), ans(c);

	for(i=1;i<=n;i++){
		ll x; cin>>x;
		sum[i] = x + sum[i-1];
	} 

	for(i=0;i<c;i++)
		ob[i] = -1e10;

	ms1.insert(0);
	multiset<ll>::iterator it;

	for(i=1;i<=n;i++){
		vector<ll> cb;
		for(j=0,it=ms1.begin(); it!=ms1.end() && j<c; it++,j++){
			ll s = sum[i] - *it;
			cb.push_back(s);
		}
		for(j=cb.size()-1;j<c;j++)
			cb.push_back(-1e10);
		merge(cb, c);
		ms1.insert(sum[i]);
	}

	cout<<ob[a-1]<<" "<<ob[b-1]<<" "<<ob[c-1]<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t; cin>>t;
    while(t--)
    	solve();
return 0;
}