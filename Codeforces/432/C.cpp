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

vector<tuple<int, int, int, int, int>> point, xy ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, a, b, c, d, e, A, B, C, D, E ;
    lli XY, distX, distY ;
    vi ans ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> a >> b >> c >> d >> e ;
        point.pb(mt(a, b, c, d, e)) ;
      }
    if(n<=20)
      {
        for(int i=0 ; i<n ; i++)
          {
            bool check=true ;
            xy.clear() ;
            tie(A, B, C, D, E)=point[i] ;
            for(int j=0 ; j<n ; j++)
              if(j!=i)
                {
                  tie(a, b, c, d, e)=point[j] ;
                  xy.pb(mt(a-A, b-B, c-C, d-D, e-E)) ;
                }
            for(int j=0 ; j<xy.size() ; j++)
              for(int k=j+1 ; k<xy.size() ; k++)
                {
                  tie(a, b, c, d, e)=xy[j] ;
                  tie(A, B, C, D, E)=xy[k] ;
                  XY=a*A+b*B+c*C+d*D+e*E ;
                  distX=a*a+b*b+c*c+d*d+e*e ;
                  distY=A*A+B*B+C*C+D*D+D*D ;
                  if(XY>0) check=false ;
                }
            if(check) ans.pb(i+1) ;
          }
        cout<< ans.size() << endl ;
        for(int i=0 ; i<ans.size() ; i++)
          cout<< ans[i] << endl ;
      }
    else
      {
        cout<< 0 ;
      }
  }
