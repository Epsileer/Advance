/**	epsileer 20 June 2019  20:00:37  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> PII;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define TEST int t = 1; while(t--) solve()

vector<pair<char,LL>> v(200005);
unordered_map<LL, LL> mp;
vector<LL> tree(1000000);

void update(int start, int end, int node, int idx, int value){
	if(start == end){
		tree[node] += value;
		return;
	}
	int mid = (start + end)/2;
	if(start <= idx && mid >= idx)
		update(start, mid, 2*node, idx, value);
	else
		update(mid+1, end, 2*node+1, idx, value);
	tree[node] = tree[2*node] + tree[2*node+1];
}

LL query(int start, int end, int node, int l, int r){
	if(start > r || end < l)
		return 0;
	if(start >= l && end <= r)
		return tree[node];
	int mid = (start + end)/2;
	return query(start, mid, 2*node, l, r) + query(mid+1, end, 2*node+1, l, r);
}

LL search(int start, int end, int node, int x){
	if(start == end)
		return start;
	int mid = (start + end)/2;
	if(tree[2*node] >= x)
		return search(start, mid, 2*node, x);
	else
		return search(mid+1, end, 2*node+1, x-tree[2*node]);
}

void solve(){
	int n; cin>>n;
	for(int i=0;i<n;i++){
		cin>>v[i].F>>v[i].S;
		mp[v[i].S] = 1;
	}
	vector<LL> a;
	for(auto i: mp)
		a.PB(i.F);
	sort(a.begin(), a.end());
	for(int i=0;i<n;i++)
		mp[a[i]] = i;

	for(int i=0;i<n;i++){
		if(v[i].F == 'I'){
			if(query(0, a.size()-1, 1, mp[v[i].S], mp[v[i].S]) == 0){
				update(0, a.size()-1, 1, mp[v[i].S], 1);
			}
		}
		if(v[i].F == 'D'){
			if(query(0, a.size()-1, 1, mp[v[i].S], mp[v[i].S]) == 1)
				update(0, a.size()-1, 1, mp[v[i].S], -1);
		}
		if(v[i].F == 'K'){
			if(tree[1] >= v[i].S)
				cout<<a[search(0, a.size()-1, 1, v[i].S)]<<endl;
			else
				cout<<"invalid"<<endl;
		}
		if(v[i].F == 'C'){
			int j = lower_bound(a.begin(), a.end(), v[i].S) - a.begin();
			j--;

			if(j < 0){
				cout<<0<<endl;
			}
			else
				cout<<query(0, a.size()-1, 1, 0, mp[a[j]])<<endl;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); TEST;
return 0;
}