/**	epsileer 28 May 2019  12:44:40  **/	
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;

vector<int> gp[20000],visited(20000),dist(20000);
map<int,int> prime;

void clr(){
	for(int i=0;i<20000;i++){
		visited[i] = 0;
		dist[i] = 0;
	}
}

void cal_prime(){
	for(int i=1000;i<10000;i++){
		bool p = true;
		for(int j=2;j<=sqrt(i);j++)
			if(i%j==0)
				p=false;
		if(p)
			prime[i] = 1;
	}
}

int bfs(int source, int destination){
	queue<int> q; q.push(source);
	while(!q.empty()){
		int u = q.front(); q.pop(); visited[u] = 1;
		for(auto v: gp[u]){
			if(!visited[v]){
				visited[v] = 1;
				q.push(v);
				dist[v] += dist[u]+1;
			}
		}
	}
	return dist[destination];
}

void solve(){
	clr();
	int x,y; cin>>x>>y;
	cout<<bfs(x, y)<<endl;
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cal_prime();

    map<int,int>::iterator it;
    for(it=prime.begin();it!=prime.end();it++){
    	int x = (*it).first;
    	for(int i=0;i<4;i++){
    		int y = (x/(int)pow(10,i))%10;
    		for(int j=0;j<10;j++){
    			if(j==y || (i==3 && j==0))continue;
    			int prm = (((x/(int)pow(10,i))/10)*10 + j)*pow(10,i) + x%(int)pow(10,i);
    			if(prime.find(prm) != prime.end()){
    				gp[x].push_back(prm);
    			}
    		}
    	}
    }

    int t;cin>>t;
    while(t--)
    	solve();
return 0;
}