/**	epsileer 21 June 2019  03:08:44  **/	
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

vector<int> arr(50000),tree(200000);

bool cmp(pair<PII,LL> x, pair<PII,LL> y){
	if(x.F.F < y.F.F)
		return true;
	else if(x.F.F == y.F.F)
		return x.F.S <= y.F.S;
	return false;
}

void update(){

}

void solve(){
	int n; cin>>n;
	for(int i=1;i<=n;i++)cin>>arr[i];
	int q; cin>>q;
	vector<pair<PII,LL>> query(q);
	vector<int> has(1000000), ans(q);
	for(int i=0;i<q;i++) cin>>query[i].F.F>>query[i].F.S, query[i].S = i;
	sort(query.begin(), query.end(), cmp);

	int cur_l = 0, cur_r = -1;

	for(int i=0;i<q;i++){
		while (cur_l > q.l) {
            cur_l--;
            if(has[cur_l] == 0){
            	has[cur_l] += 1;
            	add(cur_l);
            }
        }
        while (cur_r < q.r) {
            cur_r++;
            if(has[cur_r] == 0){
            	has[cur_r] += 1;
            	add(cur_r);
            }
        }
        while (cur_l < q.l) {
        	if(has[cur_l] == 1)
            	remove(cur_l);
            cur_l++;
            if(has[cur_l] > 0)
            	has[cur_l] -= 1;
        }
        while (cur_r > q.r) {
        	if(has[cur_r] == 1)
            	remove(cur_r);
            cur_r--;
            if(has[cur_r] > 0)
            	has[cur_r] -= 1;
        }
        ans[query[i].S] = get_answer();
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); TEST;
return 0;
}