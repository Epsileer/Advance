/**	epsileer 18 June 2019  21:20:26  **/	
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

struct point{
	int sum,pre,suf,mx;
};

vector<int> arr(100000);
vector<point> tree(500000);

point merge(point a, point b){
	point res;
	res.sum = a.sum + b.sum;
	res.pre = max(a.pre, a.sum + b.pre);
	res.suf = max(b.suf, b.sum + a.suf);
	res.mx = max(max(a.mx, b.mx), a.suf + b.pre);
	return res;
}

void build(int start, int end, int node){
	if(start == end){
		tree[node].sum = arr[start];
		tree[node].pre = arr[start];
		tree[node].suf = arr[start];
		tree[node].mx = arr[start];
		return;
	}
	int mid = (start + end)/2;
	build(start, mid, 2*node);
	build(mid+1, end, 2*node+1);

	tree[node] = merge(tree[2*node], tree[2*node+1]);
}

point query(int start, int end, int node, int l, int r){
	if(start > r || end < l){
		point p; p.sum = 0; p.pre = 0; p.suf = 0; p.mx = 0;
		return p;
	}
	if(start >= l && end <= r)
		return tree[node];
	int mid = (start + end)/2;
	if(r <= mid)
		return query(start, mid, 2*node, l, r);
	if(l > mid)
		return query(mid+1, end, 2*node+1, l, r);
	return merge(query(start, mid, 2*node, l, r), query(mid+1, end, 2*node+1, l, r));
}

void solve(){
	int n; cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];

	build(0, n-1, 1);

	int q; cin>>q;

	while(q--){
		int l,r; cin>>l>>r; --l; --r;
		cout<<query(0, n-1, 1, l, r).mx<<endl;
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); TEST;
return 0;
}