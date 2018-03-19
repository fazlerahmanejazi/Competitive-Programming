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

#define pi acos(-1.0)
#define eps 1e-8

double dist(double x1, double y1, double x2, double y2)
  {
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    double x, y, r, ans ;
    int n, curr=0 ;
    cin>> n ;
    vector<tuple<double, double, double>> data ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x >> y >> r ;
        data.pb(mt(x, y, r)) ;
      }
    for(int i=0 ; i<=1000 ; i++)
      for(int j=0 ; j<=1000 ; j++)
        {
          bool pos=true ;
          for(int k=0 ; k<n ; k++)
            {
              tie(x, y, r)=data[k] ;
              if(dist(i/1000.0, j/1000.0, x, y)<=r)
                pos=false ;
            }
          if(!pos) curr++ ;
        }
    ans=curr/1002001.0 ;
    ans*=100.0 ;
    cout<< fixed << setprecision(6) << ans ;
  }
