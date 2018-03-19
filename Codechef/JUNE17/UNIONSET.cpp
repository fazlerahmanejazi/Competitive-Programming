#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
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
    int tc ;
    cin>> tc ;
    while(tc--)
      {
        int n, k, x, sz ;
        lli ans=0 ;
        cin>> n >> k ;
        vvi sets(n) ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> sz ;
            for(int j=0 ; j<sz ; j++)
              {
                cin>> x ;
                sets[i].pb(x) ;
              }
          }
        for(int i=0 ; i<n ; i++)
          {
            map<int, bool> taken ;
            int cnt=sets[i].size() ;
            for(int j=0 ; j<sets[i].size() ; j++)
              taken[sets[i][j]]=true ;
            for(int j=i+1 ; j<n ; j++)
              {
                x=0 ;
                for(int k=0 ; k<sets[j].size() ; k++)
                  if(!taken[sets[j][k]])
                    x++ ;
                if(cnt+x==k) ans++ ;
              }
          }
        cout<< ans << endl ;
      }
  }
 
