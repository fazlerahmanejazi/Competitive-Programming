#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
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
        int n, m, d, D, u, v, x, vd ;
        cin>> n >> m >> d >> D ;
        bool pos=true ;
        vpii ans ;
        bool edge[102][102] ;
        memset(edge, false, sizeof edge) ;
        set<pii> temp ;
        vi degA(n+1, 0), degB(n+1, 0) ;
        x=m/n ;
        for(int i=1 ; i<=n ; i++)
          {
            temp.clear() ;
            for(int j=1 ; j<=n ; j++) if(!edge[i][j]) temp.insert(mp(degB[j], j)) ;
            auto it=temp.begin() ;
            for(int j=1 ; j<=x && it!=temp.end() ; j++)
              {
                tie(vd, v)=*it ; it++ ;
                edge[i][v]=true ;
                ans.pb(mp(i, v)) ;
                degA[i]++ ; degB[v]++ ;
              }
            if(degA[i]>D || degB[v]>D) { pos=false ; break ; }
          }
        x=m%n ;
        for(int i=1 ; i<=x ; i++)
          {
            temp.clear() ;
            for(int j=1 ; j<=n ; j++)
              if(!edge[i][j])
                temp.insert(mp(degB[j], j)) ;
            auto it=temp.begin() ;
            tie(vd, v)=*it ;
            ans.pb(mp(i, v)) ;
            edge[i][v]=true ;
            degA[i]++ ; degB[v]++ ;
            if(degA[i]>D || degB[v]>D) { pos=false ; break ; }
          }
        for(int i=1 ; i<=n ; i++)
          if(degA[i]<d || degA[i]>D || degB[i]<d || degB[i]>D)
            pos=false ;
        //if(pos) for(int i=0 ; i<ans.size() ; i++) cout<< ans[i].fi << " " << ans[i].se << endl ;
        //else cout<< -1 << endl ;
        if(!pos) cout<< -1 << endl ;
      }
  }
