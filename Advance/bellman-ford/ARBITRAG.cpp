#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    int n, m, tc=1 ;
    double x ;
    string s, u, v ;
    bool check ;
    while(cin>> n && n)
      {
        check=false ;
        map<string, int> cnc ;
        map<int, string> ncn ;
        vector<vector<double> > dp(n+1, vector<double>(n+1)) ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> s ;
            cnc[s]=i+1 ;
            ncn[i+1]=s ;
          }
        for(int i=1 ; i<=n ; i++)
          for(int j=1 ; j<=n ; j++)
            dp[i][j]=-1 ;
        for(int i=1 ; i<=n ; i++)
          dp[i][i]=1 ;
        cin>> m ;
        for(int i=0 ; i<m ; i++)
          {
            cin>> u >> x >> v ;
            dp[cnc[u]][cnc[v]]=x ;
          }
        for(int k=1 ; k<=n ; k++)
          for(int i=1 ; i<=n ; i++)
            for(int j=1 ; j<=n ; j++)
                if(dp[i][k]>0 && dp[k][j]>0)
                  dp[i][j]=max(dp[i][j], dp[i][k]*dp[k][j]) ;
        for(int i=1 ; i<=n ; i++)
            if(dp[i][i]>1)
              check=true ;
        if(check) cout << "Case " << tc++ << ": Yes" << endl ;
        else cout << "Case " << tc++ << ": No" << endl ;
      }
  }