/**	epsileer 09 May 2019  19:04:27  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve(){
	priority_queue<ll> pq1,pq2;
	int flag = 0;

	ll x;

	while(true){
		scanf("%lld", &x);

		if(x == 0)
			break;

		if(x == -1){
			printf("%lld \n",pq1.top()); pq1.pop();
			if(pq1.size() < pq2.size()){
				ll y = -pq2.top(); pq2.pop();
				pq1.push(y);
			}
			if(pq1.size() > pq2.size())
				flag = 1;
			else
				flag = 0;
			continue;
		}

		if(flag == 0){
			if(pq1.empty() || x <= -pq2.top()){
				pq1.push(x);
			}
			else{
				ll y = -pq2.top(); pq2.pop();
				pq2.push(-x);
				pq1.push(y);
			}
		}
		else{
			if(x >= pq1.top()){
				pq2.push(-x);
			}
			else{
				ll y = pq1.top(); pq1.pop();
				pq1.push(x);
				pq2.push(-y);
			}
		}
		flag = (flag+1)%2;
	}
}

int main(){
    int t;	scanf("%d", &t);
    while(t--)
    	solve();
return 0;
}