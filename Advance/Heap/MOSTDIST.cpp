/**	epsileer 09 May 2019  11:43:23  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve(){
	priority_queue< pair<ll, ll> > h1,h2,h3,h4;
	ll x,y;

	vector<int> point;

	int n; cin>>n;
	ll answer = 0;

	while(n--){
		char ch; cin>>ch;
		if(ch == '+'){
			cin>>x>>y;
			x ^= answer;
			y ^= answer;
			point.push_back(0);
			h1.push({x+y, point.size()-1});
			h2.push({x-y, point.size()-1});
			h3.push({-x+y, point.size()-1});
			h4.push({-x-y, point.size()-1});
		}

		if(ch == '-'){
			int N; cin>>N; N ^= answer; --N;
			point[N] = 1;
		}

		if(ch == '?'){
			cin>>x>>y;
			x ^= answer;
			y ^= answer;
			while(!h1.empty() && point[h1.top().second])
				h1.pop();
			while(!h2.empty() && point[h2.top().second])
				h2.pop();
			while(!h3.empty() && point[h3.top().second])
				h3.pop();
			while(!h4.empty() && point[h4.top().second])
				h4.pop();
			ll mx = -1e10;
			if(!h1.empty() && abs((x+y) - h1.top().first) > mx){
				mx = abs((x+y) - h1.top().first);
			}
			if(!h2.empty() && abs((x-y) - h2.top().first) > mx){
				mx = abs((x-y) - h2.top().first);
			}
			if(!h3.empty() && abs((-x+y) - h3.top().first) > mx){
				mx = abs((-x+y) - h3.top().first);

			}
			if(!h4.empty() && abs((-x-y) - h4.top().first) > mx){
				mx = abs((-x-y) - h4.top().first);
			}
			answer = mx;
			cout<<answer<<endl;
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