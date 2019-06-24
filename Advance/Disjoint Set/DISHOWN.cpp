/**	epsileer 12 May 2019  12:55:56  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<pair<int, int>> dish;

int find_set(int x){
	if(dish[x].second == x)
		return x;
	return dish[x].second = find_set(dish[x].second);
}

void solve(){
	int n; cin>>n;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		dish.push_back(make_pair(x,i));
	}

	int q; cin>>q;

	while(q--){
		int x; cin>>x;
		if(x==0){
			int y,z; cin>>y>>z; --y; --z;
			if(find_set(y) != find_set(z)){
				int p = find_set(y) ;
			    int q = find_set(z) ;
			    if(dish[p].first > dish[q].first)
			    	dish[q].second = p ;
			    else if(dish[q].first  > dish[p].first)
			    	dish[p].second = q ;
			}
			else{
				cout<<"Invalid query!"<<endl;
			}
		}
		else{
			int y; cin>>y; --y;
			cout<<find_set(y)+1<<endl;
		}
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