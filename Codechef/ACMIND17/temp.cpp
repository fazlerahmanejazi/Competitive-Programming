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

lli T, n, mi=inf, l, r, m, f1, f2, ans ;
vector<tuple<lli, lli, lli>> p ;

void init()
  {
    p.clear() ;
    p.resize(n+1) ;
  }

lli check(lli x)
  {
    lli res=0 ;
    for(int i=0 ; i<n ; i++)
      {
        if(get<1>(p[i])<=x) res+=1LL*(x-get<1>(p[i])) ;
        else res+=1LL*(get<2>(p[i])+x-get<1>(p[i])) ;
      }
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        init() ;
        for(int i=0 ; i<n ; i++) cin>> get<1>(p[i]) ;
        for(int i=0 ; i<n ; i++) cin>> get<2>(p[i]) ;
        for(int i=0 ; i<n ; i++)
          {
            get<0>(p[i])=get<1>(p[i])%get<2>(p[i]) ;
            get<1>(p[i])=get<1>(p[i])%get<2>(p[i]) ;
          }
        ans=INF ;
        if(mi==1) ans=check(0) ;
        else if(check(0)<check(1)) ans=min(check(0), check(mi-1)) ;
        else
          {
            l=-1 ; r=mi-1 ;
            while(r-l>1)
              {
                m=(l+r)/2 ;
                f1=check(m) ; f2=check(m+1) ;
                if(f1<f2)
                  {
                    r=m ;
                    ans=min(ans, f1) ;
                  }
                else
                  {
                    l=m ;
                    ans=min(ans, f2) ;
                  }
              }
          }
        cout<< ans << endl ;
      }
  }
