/**	epsileer 16 May 2019  15:09:19  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> p;

int find_set(int x){
	if(p[x] == x) return x;
	else return p[x] = find_set(p[x]);
}

void solve(){
	p.clear();
	int n,c; cin>>n>>c;
	for(int i=0;i<n;i++)
		p.push_back(i);
	for(int i=0;i<c;i++){
		int x,y; cin>>x>>y; --x; --y;
		if(find_set(x) != find_set(y))
			p[find_set(y)] = find_set(x);
	}

	int q; cin>>q;
	while(q--){
		int x,y; cin>>x>>y; --x; --y;
		if(find_set(x) == find_set(y))
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    	solve();
return 0;
}