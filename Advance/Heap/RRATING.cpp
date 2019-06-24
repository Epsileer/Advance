/**	epsileer 08 May 2019  14:48:02  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve(){
	priority_queue<ll> pq1,pq2;
	int n,count=0; cin>>n; 
	while(n--){
		int op; cin>>op;
		if(op == 1){
			ll x; cin>>x;
			count++;
			ll rev = count/3;
            if (rev == 0) {
                pq1.push(x);
            } else if (pq2.size() == rev-1) {
                pq1.push(x);
                pq2.push(-pq1.top());
                pq1.pop();
            } else {
                ll front = -pq2.top();
                if (front < x) {
                    pq2.pop();
                    pq2.push(-x);
                    pq1.push(front);
                } else {
                    pq1.push(x);
                }
            }
		}
		else{
			if(count/3){
				cout<<(-pq2.top())<<endl;
			}
			else
				cout<<"No reviews yet"<<endl;
		}
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    // int t;cin>>t;
    // while(t--)
    	solve();
return 0;
}	