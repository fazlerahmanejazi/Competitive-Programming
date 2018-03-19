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
    lli n, x, curr, ans, p, q, pi, qi, l, r, m, P, Q, res=0 ;
    cin>> n ;
    vlli a(n) ;
    vector<pair<lli, lli>> b(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    bool done ;
    while(1)
      {
        done=true ;
        for(int i=0 ; i<n ; i++)
          if(a[i]>=n)
            done=false ;
        if(done) break ;
        for(int i=0 ; i<n ; i++)
          b[i]=mp(a[i], i) ;
        sort(all(b)) ;
        tie(p, pi)=b[n-1] ;
        tie(q, qi)=b[n-2] ;
        if(p>q)
          {
            l=1 ; r=1e18 ;
            ans=r ;
            while(l<=r)
              {
                m=(l+r)/2 ;
                P=p-m*n ;
                Q=q+m ;
                if(P>=0)
                  {
                    l=m+1 ;
                    ans=min(m, ans) ;
                  }
                else r=m-1 ;
              }
            for(int i=0 ; i<n ; i++)
              if(i==pi) a[i]-=ans*n ;
              else a[i]+=ans ;
            res+=ans ;
          }
        else if(p!=n)
          {
            curr=p-n ;
            x=ceil(curr/(1.0*n)) ;
            if(p-x*n<0) x-- ;
            for(int i=0 ; i<n ; i++)
              if(i==pi) a[i]-=x*n ;
              else a[i]+=x ;
            res+=x ;
          }
        else
          {
            res++ ;
            for(int i=0 ; i<n ; i++)
              if(i==pi) a[i]-=n ;
              else a[i]++ ;
          }
      }
    cout<< res ;
  }
