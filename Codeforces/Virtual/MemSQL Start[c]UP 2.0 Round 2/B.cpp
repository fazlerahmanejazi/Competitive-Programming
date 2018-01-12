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
    int n, m, x ;
    double curr, dist ;
    cin>> n >> m ;
    if(!n)
      {
        cout<< 0 << " " << 1 << endl ;
        cout<< 0 << " " << m << endl ;
        cout<< 0 << " " << 0 << endl ;
        cout<< 0 << " " << m-1 << endl ;
      }
    else if(!m)
      {
        cout<< 1 << " " << 0 << endl ;
        cout<< n << " " << 0 << endl ;
        cout<< 0 << " " << 0 << endl ;
        cout<< n-1 << " " << 0 << endl ;
      }
    else if(n>m)
      {
        dist=2.0*sqrt((double)(n*n+m*m))+(double)n ;
        x=m ;
        for(int i=m-1 ; i>=1 ; i--)
          {
            curr=sqrt((double)(n*n+m*m))+2.0*sqrt((double)(n*n+i*i)) ;
            if(curr>dist)
              {
                x=i ;
                dist=curr ;
              }
          }
        if(x==m)
          {
            cout<< n << " " << m << endl ;
            cout<< 0 << " " << 0 << endl ;
            cout<< n << " " << 0 << endl ;
            cout<< 0 << " " << m << endl ;
          }
        else
          {
            cout<< 0 << " " << x << endl ;
            cout<< n << " " << 0 << endl ;
            cout<< 0 << " " << m << endl ;
            cout<< n << " " << m-x << endl ;
          }
      }
    else
      {
        dist=2.0*sqrt((double)(n*n+m*m))+(double)m ;
        x=n ;
        for(int i=n-1 ; i>=1 ; i--)
          {
            curr=sqrt((double)(n*n+m*m))+2.0*sqrt((double)(i*i+m*m)) ;
            if(curr>dist)
              {
                x=i ;
                dist=curr ;
              }
          }
        if(x==n)
          {
            cout<< n << " " << m << endl ;
            cout<< 0 << " " << 0 << endl ;
            cout<< 0 << " " << m << endl ;
            cout<< n << " " << 0 << endl ;
          }
        else
          {
            cout<< x << " " << 0 << endl ;
            cout<< 0 << " " << m << endl ;
            cout<< n << " " << 0 << endl ;
            cout<< (n-x) << " " << m << endl ;
          }

      }
  }
