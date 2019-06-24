/**	epsileer 09 May 2019  09:55:41  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve(){
	priority_queue<ll> pq;
	int k,n,x; cin>>k>>n;
	for(int i=1;i<=n;i++){
		cin>>x;
		if(i < k){
			pq.push(-x);
			cout<<-1<<" ";
		}
		else if(i == k){
			pq.push(-x);
			cout<<-pq.top()<<" ";
		}
		else{
			if(x > -pq.top()){
				pq.pop();
				pq.push(-x);
				cout<<-pq.top()<<" ";
			}
			else
				cout<<-pq.top()<<" ";
		}
	}
	cout<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int t;cin>>t;
    while(t--)
    	solve();
return 0;
}