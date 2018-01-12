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
    lli tc, p, q, r, ans, P, R ;
    cin>> tc ;
    while(tc--)
      {
        cin>> p >> q >> r ;
        ans=0 ;
        vlli x(p+1), y(q+1), z(r+1), sumX(p+1, 0), sumZ(r+1, 0) ;
        for(int i=1 ; i<=p ; i++)
          cin>> x[i] ;
        for(int i=1 ; i<=q ; i++)
          cin>> y[i] ;
        for(int i=1 ; i<=r ; i++)
          cin>> z[i] ;
        sort(x.begin()+1, x.end()) ;
        sort(y.begin()+1, y.end()) ;
        sort(z.begin()+1, z.end()) ;
        for(int i=1 ; i<=p ; i++)
          sumX[i]=sumX[i-1]+x[i] ;
        for(int i=1 ; i<=r ; i++)
          sumZ[i]=sumZ[i-1]+z[i] ;
        for(int i=1 ; i<=q ; i++)
          {
            P=upper_bound(x.begin()+1, x.end(), y[i])-x.begin()-1 ;
            R=upper_bound(z.begin()+1, z.end(), y[i])-z.begin()-1 ;
            if(y[i]<x[1] || y[i]<z[1] || !P || !R) continue ;
            ans+=((sumX[P]+P*y[i])%mod)*((sumZ[R]+R*y[i])%mod) ;
            ans=ans%mod ;
          }
        cout<< ans << endl ;
      }
  }
