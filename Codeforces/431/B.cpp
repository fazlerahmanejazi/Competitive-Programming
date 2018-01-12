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

bool collinear(lli x1, lli y1, lli x2, lli y2, lli x3, lli y3)
  {
    return (y1-y2)*(x1-x3)==(y1-y3)*(x1-x2) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n ;
    cin>> n ;
    vlli a(n+1) ;
    vb taken(n+1, false) ;
    bool pos=true ;
    for(int i=1 ; i<=n ; i++)
      cin>> a[i] ;
    for(int j=1 ; j<=n ; j++)
      {
        pos=true ;
        taken.assign(n+1, false) ;
        if(j==1)
          {
            taken[1]=taken[2]=taken[3]=true ;
            for(int i=4 ; i<=n ; i++)
              if(collinear(2, a[2], 3, a[3], i, a[i]))
                taken[i]=true ;
            if(collinear(1, a[1], 2, a[2], 3, a[3])) pos=false ;
            for(int i=1 ; i<=n ; i++)
              if(!taken[i])
                pos=false ;
          }
        else
          {
            taken[1]=taken[j]=true ;
            for(int i=j+1 ; i<=n ; i++)
              if(collinear(1, a[1], j, a[j], i, a[i]))
                taken[i]=true ;
            vlli b ;
            for(int i=1 ; i<=n ; i++)
              if(!taken[i])
                b.pb(i) ;
            if(b.empty()) pos=false ;
            else if(b.size()==1 && collinear(1, a[1], j, a[j], b[0], a[b[0]])) pos=false ;
            else if(b.size()>=2)
              {
                taken[b[0]]=taken[b[1]]=true ;
                for(int i=2 ; i<b.size() ; i++)
                  if(collinear(b[0], a[b[0]], b[1], a[b[1]], b[i], a[b[i]]))
                    taken[b[i]]=true ;
                if(collinear(1, a[1], j, a[j], b[0], a[b[0]])) pos=false ;
                for(int i=1 ; i<=n ; i++)
                  if(!taken[i])
                    pos=false ;
                if((a[j]-a[1])*(b[1]-b[0])!=(a[b[1]]-a[b[0]])*(j-1)) pos=false ;
              }
          }
        if(pos)
          {
            cout<< "YES" ;
            return 0 ;
          }
      }
    cout<< "NO" ;
  }
