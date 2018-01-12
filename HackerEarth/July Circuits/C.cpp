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

lli gcd(lli a, lli b)
  {
    return b==0 ? a : gcd(b, a%b) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, t, d, c, prev, S, pos ;
    lli x, A, B, a, b ;
    long double ans=HUGE_VALL, curr ;
    cin>> n >> S ;
    vpii data ;
    vlli down(2000001, 0), speed(2000100, 0) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> t >> d ;
        data.pb(mp(t, d)) ;
      }
    data.pb(mp(INF, INF)) ;
    speed[0]=prev=data[0].se ;
    c=1 ;
    for(int i=1 ; i<=2000000 ; i++)
      {
        tie(t, d)=data[c] ;
        speed[i]=prev ;
        down[i]+=down[i-1]+prev ;
        if(i==t)
          {
            speed[i]=prev=d ;
            c++ ;
          }
      }
    for(int i=0 ; i<=1000000 ; i++)
      {
        x=S+down[i] ;
        pos=lower_bound(all(down), x)-down.begin() ;
        pos-- ;
        x-=down[pos] ;
        A=(pos-i)*speed[pos]+x ;
        B=speed[pos] ;
        curr=(long double)A/B ;
        if(curr<ans)
          {
            a=A ;
            b=B ;
            ans=curr ;
          }
      }
    cout<< a/gcd(a, b) << "/" << b/gcd(a, b) ;
  }
