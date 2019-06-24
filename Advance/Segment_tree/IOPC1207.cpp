/**	epsileer 20 June 2019  18:40:06  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> PII;
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define TEST int t = 1; cin>>t; while(t--) solve()

vector<vector<LL>> tree(3, vector<LL>(500005)), lazy(3, vector<LL>(500005));

void clr(){
	for(int i=0;i<3;i++){
		for(int j=0;j<500005;j++){
			tree[i][j] = 0;
			lazy[i][j] = 0;
		}
	}
}

void updateRange(LL start, LL end, LL node, LL l, LL r, LL axis){
	if(lazy[axis][node]){
		tree[axis][node] = (end - start + 1) - tree[axis][node];
		if(start != end){
			lazy[axis][2*node] = 1 - lazy[axis][2*node];
			lazy[axis][2*node+1] = 1 - lazy[axis][2*node+1];
		}
		lazy[axis][node] = 0;
	}
	if(start > r || end < l)
		return;
	if(start >= l && end <= r){
		tree[axis][node] = (end - start + 1) - tree[axis][node];
		if(start != end){
			lazy[axis][2*node] = 1 - lazy[axis][2*node];
			lazy[axis][2*node+1] = 1 - lazy[axis][2*node+1];
		}
		return;
	}
	LL mid = (start + end)/2;
	updateRange(start, mid, 2*node, l, r, axis);
	updateRange(mid+1, end, 2*node+1, l, r, axis);
	tree[axis][node] = tree[axis][2*node] + tree[axis][2*node+1];
}

int queryRange(LL start, LL end, LL node, LL l, LL r, LL axis){
	if(start > end || start > r || end < l)
		return 0;
	if(lazy[axis][node]){
		tree[axis][node] = (end - start + 1) - tree[axis][node];
		if(start != end){
			lazy[axis][2*node] = 1 - lazy[axis][2*node];
			lazy[axis][2*node+1] = 1 - lazy[axis][2*node+1];
		}
		lazy[axis][node] = 0;
	}
	if(start >= l && end <= r)
		return tree[axis][node];
	LL mid = (start + end)/2;
	return queryRange(start, mid, 2*node, l, r, axis) + queryRange(mid+1, end, 2*node+1, l, r, axis);
}

void solve(){
	clr();
	LL x,y,z,q; cin>>x>>y>>z>>q;
	while(q--){
		LL a; cin>>a;
		if(a == 0){
			LL l,r; cin>>l>>r;
			updateRange((LL)0, x-1, 1, l, r, 0);
		}
		if(a == 1){
			LL l,r; cin>>l>>r;
			updateRange((LL)0, y-1, 1, l, r, 1);
		}
		if(a == 2){
			LL l,r; cin>>l>>r;
			updateRange((LL)0, z-1, 1, l, r, 2);
		}
		if(a == 3){
			LL x1, y1, z1, x2, y2, z2; cin>>x1>>y1>>z1>>x2>>y2>>z2;
			LL rx = queryRange((LL)0, x-1, 1, x1, x2, 0);
			LL gx = (x2 - x1 + 1) - rx;
			LL ry = queryRange((LL)0, y-1, 1, y1, y2, 1);
			LL gy = (y2 - y1 + 1) - ry;
			LL rz = queryRange((LL)0, z-1, 1, z1, z2, 2);
			LL gz = (z2 - z1 + 1) - rz;

			LL ans = (rx * ry * rz) + (rx * gy * gz) + (gx * ry * gz) + (gx * gy * rz);
			cout<<ans<<endl;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); TEST;
return 0;
}