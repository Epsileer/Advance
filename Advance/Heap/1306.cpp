/**	epsileer 10 May 2019  16:39:36  **/	
#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n; cin>>n;
	vector<unsigned int> a(n);
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a.begin(), a.end());
	if(n%2)
		cout<<a[n/2]<<".0\n";
	else{
		unsigned int x = a[n/2] + a[(n/2)-1];
		if(x%2)
			cout<<x/2<<".5\n";
		else
			cout<<x/2<<".0\n";
	}
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
    // int t;cin>>t;
    // while(t--)
    	solve();
return 0;
}