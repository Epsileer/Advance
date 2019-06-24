/**	epsileer 13 June 2019  17:34:50  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef pair<LL,LL> PII;
#define PB push_back
#define MP make_pair
#define F first
#define S second

vector<vector<int>> a(26, vector<int>(2)), gp(26, vector<int>(26));
vector<int> v(26), t(26);

void clr(){
	for(int i=0;i<26;i++){
		a[i][0] = a[i][1] = v[i] = t[i] = 0;
		for(int j=0;j<26;j++) gp[i][j] = 0;
	}
}

void dfs(int i){
	t[i] = 1;
	for(int j=0;j<26;j++)
		if(gp[i][j] && !t[j])
			dfs(j);
}

void solve(){
	int n; cin>>n;
	clr();
	string s; 
	for(int i=0;i<n;i++){
		cin>>s;
		v[s[0]-'a'] = v[s[s.size()-1]-'a'] = 1;
		a[s[0]-'a'][0]++;
		a[s[s.size()-1]-'a'][1]++;
		gp[s[0]-'a'][s[s.size()-1]-'a'] = 1;
		gp[s[s.size()-1]-'a'][s[0]-'a'] = 1;
	}

	int i=0,start=0,end=0,connected=1;

	for(i=0;!v[i];i++);
	dfs(i);
	for(i=0;i<26;i++){
		if(v[i]&&!t[i]){
			connected = 0;
			break;
		}
	}
	if(!connected){
		cout<<"The door cannot be opened.\n";
		return;
	}

	i=-1;
	while(++i < 26){
		if(a[i][0]+1 == a[i][1])
			start++;
		else if(a[i][0] == a[i][1]+1)
			end++;
		else if(a[i][0] != a[i][1])
			break;
	}

	if(i==26 && ((start==1 && end==1) || (start==0 && end==0)))
		cout<<"Ordering is possible.\n";
	else
		cout<<"The door cannot be opened.\n";
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
  	int t=1; cin>>t;
  	while(t--)
    	solve();
return 0;
}