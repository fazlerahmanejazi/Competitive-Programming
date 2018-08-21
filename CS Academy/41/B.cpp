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
    int n, curr=1, idx, ans=0, L, R, prev, v1, v2 ;
    bool pos ;
    string s ;
    cin>> s ;
    n=s.length() ;
    vi l(n+1), r(n+1), vacant ;
    prev=-1 ;
    for(int i=0 ; i<n ; i++)
      if(s[i]=='1')
        {
          l[i]=prev ;
          prev=i ;
        }
    prev=n ;
    for(int i=n-1 ; i>=0 ; i--)
      if(s[i]=='1')
        {
          r[i]=prev ;
          prev=i ;
        }
    for(int i=0 ; i<n ; i++)
      if(s[i]=='0')
        vacant.pb(i) ;
    v1=n ;
    v2=-1 ;
    if(vacant.size()>=2)
      {
        v1=vacant[0] ;
        v2=vacant[vacant.size()-1] ;
      }
    else if(vacant.size()==1)
      {
        v1=v2=vacant[0] ;
      }
    for(int i=0 ; i<n ; i++)
      if(s[i]=='1')
        {
          L=l[i] ;
          R=r[i] ;
          pos=false ;
          if((vacant.size()>=1) && (v1<L || v2>R)) pos=true ;
          if(L<v1 && v2<R)
            {
              L++ ;
              R-- ;
              curr=R-L ;
              ans=max(ans, curr) ;
            }
          else
            {
              L++ ;
              R-- ;
              curr=R-L+1 ;
              if(pos) ans=max(ans, curr) ;
            }
        }
    cout<< ans ;
  }
