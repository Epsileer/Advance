/**	epsileer 29 May 2019  12:52:57  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

void solve(){
	string s; cin>>s;
	s = " "+s+" ";
	vector<int> dp(s.size()+2,INT_MAX-1),q(10);
	dp[1] = 0;

	for(int i=0;i<20;i++){
		for(int j=0;j<10;j++)
			q[j] = INT_MAX-1;
		for(int j=1;j<s.size()-1;j++)
			q[s[j]-'0'] = min(q[s[j]-'0'], dp[j]);
		for(int j=1;j<s.size()-1;j++)
			dp[j] = min( min(dp[j], dp[j-1]+1), min(dp[j+1]+1, q[s[j]-'0']+1) );
	}

	cout<<dp[s.size()-2];
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    // int t;cin>>t;
    // while(t--)
    	solve();
return 0;
}