/**	epsileer 26 May 2019  14:39:36  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

ll exp_power(ll x, ll y){
	ll result = 1;
	x %= 1000000007;
	while(y>0){
		if(y%2){
			result *= x;
			result %= 1000000007;
		}
		y /= 2;
		x = (x*x)%1000000007;
	}
	return result;
}

vector<ll> p(3000,0);

ll find_set(ll x){
	if(p[x] == x)
		return x;
	return p[x] = find_set(p[x]);
}

void solve(){
	ll n,m; cin>>n>>m; 

	for(ll i=1;i<=n;i++){
		p[i] = i;
	}

	map<ld, ll> mp;
	for(ll i=0;i<m;i++){
		ll x,y; cin>>x>>y;
		ld mid = ((ld)x+y)/2.0;
		if(mp.find(mid) == mp.end())
			mp[mid] = (y-x+1)/2;
		else
			mp[mid] = max(mp[mid], (y-x+1)/2);
	}

	for(auto i: mp){
		for(ll k=1;k<=i.second;k++){
			if(find_set(ceil(i.first-k)) != find_set(floor(i.first+k)))
				p[ceil(i.first-k)] = floor(i.first+k);
		}
	}

	set<ll> st;
	for(ll i=1;i<=n;i++){
		st.insert(find_set(i));
	}

	cout<<exp_power(26, st.size())<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    ll t;cin>>t;
    while(t--)
    	solve();
return 0;
}