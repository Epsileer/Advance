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
#define TEST LL t = 1; cin>>t; while(t--) solve()

struct poLL{
	LL sum,pre,suf,mx;
};

vector<LL> arr(100000);
vector<poLL> tree(500000);

poLL merge(poLL a, poLL b){
	poLL res;
	res.sum = a.sum + b.sum;
	res.pre = max(a.pre, a.sum + b.pre);
	res.suf = max(b.suf, b.sum + a.suf);
	res.mx = max(max(a.mx, b.mx), a.suf + b.pre);
	return res;
}

void build(LL start, LL end, LL node){
	if(start == end){
		tree[node].sum = arr[start];
		tree[node].pre = arr[start];
		tree[node].suf = arr[start];
		tree[node].mx = arr[start];
		return;
	}
	LL mid = (start + end)/2;
	build(start, mid, 2*node);
	build(mid+1, end, 2*node+1);

	tree[node] = merge(tree[2*node], tree[2*node+1]);
}

poLL query(LL start, LL end, LL node, LL l, LL r){
	if(start > r || end < l){
		poLL p; p.sum = 0; p.pre = 0; p.suf = 0; p.mx = 0;
		return p;
	}
	if(start >= l && end <= r)
		return tree[node];
	LL mid = (start + end)/2;
	if(r <= mid)
		return query(start, mid, 2*node, l, r);
	if(l > mid)
		return query(mid+1, end, 2*node+1, l, r);
	return merge(query(start, mid, 2*node, l, r), query(mid+1, end, 2*node+1, l, r));
}

void solve(){
	LL n; cin>>n;
	for(LL i=0;i<n;i++)cin>>arr[i];

	build(0, n-1, 1);

	LL q; cin>>q;

	while(q--){
		LL x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2; --x1; --y1; --x2; --y2;
		if(y1 < x2){
			cout<<query(0, n-1, 1, x1, y1).suf + query(0, n-1, 1, y1+1, x2-1).sum + query(0, n-1, 1, x2, y2).pre<<endl;
		}
		else{
			LL ans = 0;
			ans = query(0, n-1, 1, x1, x2-1).suf + query(0, n-1, 1, x2, y2).pre;
            ans = max(ans, query(0, n-1, 1, x2, y1).suf + query(0, n-1, 1, y1+1, y2).pre) ;
            ans = max(ans, query(0, n-1, 1, x2, y1).mx) ;
            cout<< ans << endl ;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); TEST;
return 0;
}