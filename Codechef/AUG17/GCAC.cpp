#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        int n, m, sal, idx ;
        lli num=0, totSalary=0, noCompany=0 ;
        cin>> n >> m ;
        string s ;
        vector<vpii> adj(n+1) ;
        vi minSalary(n+1), offeredSalary(m+1), maxJobOffers(m+1) ;
        vb companyHired(m+1, false) ;
        for(int i=0 ; i<n ; i++)
          cin>> minSalary[i] ;
        for(int i=0 ; i<m ; i++)
          cin>> offeredSalary[i] >> maxJobOffers[i] ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> s ;
            for(int j=0 ; j<m ; j++)
              if(s[j]=='1')
                adj[i].pb(mp(offeredSalary[j], j)) ;
            sort(all(adj[i])) ;
            reverse(all(adj[i])) ;
          }
        for(int i=0 ; i<n ; i++)
          {
            for(int j=0 ; j<adj[i].size() ; j++)
              {
                tie(sal, idx)=adj[i][j] ;
                if(maxJobOffers[idx] && minSalary[i]<=sal)
                  {
                    companyHired[idx]=true ;
                    totSalary+=sal ;
                    maxJobOffers[idx]-- ;
                    num++ ;
                    break ;
                  }
              }
          }
        for(int i=0 ; i<m ; i++)
          if(!companyHired[i])
            noCompany++ ;
        cout<< num << " " << totSalary << " " << noCompany << endl ;
      }
  }
