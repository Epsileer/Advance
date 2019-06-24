/**	epsileer 11 May 2019  11:11:21  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<pair<int,int>> ds(100000);

int find_set(int x){
	if(ds[x].second == x)
		return x;
	return ds[x].second = find_set(ds[x].second);
}

void solve(){
	int n; cin>>n;
	for(int i=0;i<n;i++){
		ds[i].first = i*10;
		ds[i].second = i;
	}

	int q; cin>>q;

	while(q--){
		int x,y; cin>>x>>y;

		if(find_set(x) != find_set(y))
			ds[find_set(x)].second = find_set(y);
	}

	for(int i=0;i<n;i++)
		cout<<find_set(i)<<" ";
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    // int t;cin>>t;
    // while(t--)
    	solve();
return 0;
}