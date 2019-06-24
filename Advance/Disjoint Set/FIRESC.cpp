/**	epsileer 16 May 2019  14:52:16  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> ds;

int find_set(int x){
	if(ds[x] == x)
		return x;
	else return ds[x] = find_set(ds[x]);
}

void solve(){
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++)
		ds.push_back(i);
	for(int i=0;i<m;i++){
		int x,y; cin>>x>>y; --x; --y;
		if(find_set(x) != find_set(y)){
			ds[find_set(y)] = find_set(x);
		}
	}

	set<int> st;
	for(int i=0;i<n;i++){
		st.insert(find_set(i));
	}

	cout<<st.size()<<" ";
	int ans = 1, cnt = 1;
	sort(ds.begin(), ds.end());
	ds.push_back(-1);

	for(int i=0;i<n;i++){
		if(ds[i] != ds[i+1]){
			ans *= cnt;
			ans %= 1000000007;
			cnt = 1;
		}
		else
			cnt++;
	}

	cout<<ans<<endl;

	ds.clear();
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    	solve();
return 0;
}