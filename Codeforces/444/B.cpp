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
    int n, x, prev ;
    cin>> n ;
    vvi a(n) ;
    set<int> num ;
    for(int i=0 ; i<n ; i++)
      for(int j=0 ; j<6 ; j++)
        {
          cin>> x ;
          a[i].pb(x) ;
        }
    num.insert(0) ;
    for(int i=0 ; i<6 ; i++)
      for(int j=0 ; j<6 ; j++)
        for(int k=0 ; k<6 ; k++)
          {
            if(n>=3)
              {
                num.insert(100*a[0][i]+10*a[1][j]+a[2][k]) ;
                num.insert(100*a[1][i]+10*a[2][j]+a[0][k]) ;
                num.insert(100*a[2][i]+10*a[0][j]+a[1][k]) ;
                num.insert(100*a[0][i]+10*a[2][j]+a[1][k]) ;
                num.insert(100*a[2][i]+10*a[1][j]+a[0][k]) ;
                num.insert(100*a[1][i]+10*a[0][j]+a[2][k]) ;
                num.insert(10*a[0][j]+a[2][k]) ;
                num.insert(10*a[2][j]+a[0][k]) ;
                num.insert(10*a[1][j]+a[2][k]) ;
                num.insert(10*a[2][j]+a[1][k]) ;
                num.insert(a[2][k]) ;
              }
            if(n>=2)
              {
                num.insert(10*a[0][j]+a[1][k]) ;
                num.insert(10*a[1][j]+a[0][k]) ;
                num.insert(a[1][k]) ;
              }
            num.insert(a[0][k]) ;
          }
    prev=-1 ;
    for(auto i:num)
      if(i!=prev+1) break ;
      else prev=i ;
    cout<< max(prev, 0) ;
  }
