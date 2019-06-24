/**	epsileer 27 May 2019  14:43:54  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
vector<int> pr(10000),po(10000),in(10000),tree(10000,-1);
int n,p=-1;

int find_root(){
	p++;
	for(int i=0;i<n;i++)
		if(pr[p] == in[i])
			return i;
	return -1;
}

void pre(int l, int r, int tree_node){
	if(l <= r){
		int x = find_root();
		if(x<l || x>r)
			return;
		tree[tree_node] = in[x];
		pre(l,x-1,2*tree_node+1);
		pre(x+1,r,2*tree_node+2);
	}
}

void post(int root){
	if(tree[root] == -1)
		return;
	post(2*root+1);
	post(2*root+2);
	in.push_back(tree[root]);
}

void solve(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>pr[i];
	for(int i=0;i<n;i++) cin>>po[i];
	for(int i=0;i<n;i++) cin>>in[i];

	pre(0,n-1,0);
	in.clear();
	bool flag = true;
	post(0);
	if(in.size()!=n)
		flag = false;
	if(flag)
	for(int i=0;i<n;i++)
		if(in[i] != po[i])
			flag = false;


	if(flag)
		cout<<"yes";
	else
		cout<<"no";
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    // int t;cin>>t;
    // while(t--)
    	solve();
return 0;
}