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

int n, a, b, x, y, sz, curr, ans ;

bool check(int x1, int y1, int x2, int y2)
  {
    if(x1+x2<=a && y1<=b && y2<=b) return true ;
    else if(x1+y2<=a && y1<=b && x2<=b) return true ;
    else if(y1+y2<=a && x1<=b && x2<=b) return true ;
    else if(y1+x2<=a && x1<=b && y2<=b) return true ;
    else if(x1+x2<=b && y1<=a && y2<=a) return true ;
    else if(x1+y2<=b && y1<=a && x2<=a) return true ;
    else if(y1+y2<=b && x1<=a && x2<=a) return true ;
    else if(y1+x2<=b && x1<=a && y2<=a) return true ;
    else return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    ans=0 ;
    int x1, x2, y1, y2 ;
    cin>> n >> a >> b ;
    vpii seals ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x >> y ;
        seals.pb(mp(x, y)) ;
      }
    for(int i=0 ; i<n ; i++)
      for(int j=i+1 ; j<n ; j++)
        {
          tie(x1, y1)=seals[i] ;
          tie(x2, y2)=seals[j] ;
          if(check(x1, y1, x2, y2))
            {
              curr=x1*y1+x2*y2 ;
              ans=max(ans, curr) ;
            }
        }
    cout<< ans ;
  }
