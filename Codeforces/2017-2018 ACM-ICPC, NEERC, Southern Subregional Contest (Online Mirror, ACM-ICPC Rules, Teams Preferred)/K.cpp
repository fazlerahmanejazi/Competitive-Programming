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

lli n, u, d, x, idx, l, r, m, curr, res ;
vlli s, g, a, ans, resVal ;

lli check(int x)
  {
    u=d=x ;
    ans[0]=x ;
    for(int i=1 ; i<n ; i++)
      {
        u++ ; d-- ;
        if(s[i]>u || a[i]<d) return -1 ;
        u=min(a[i], u) ;
        d=max(s[i], d) ;
        ans[i]=u ;
      }
    ans[n-1]=u ;
    for(int i=n-2 ; i>=0 ; i--) ans[i]=min({ans[i], a[i], ans[i+1]+1}) ;
    lli temp=0 ;
    for(int i=0 ; i<n ; i++)
      temp+=(ans[i]-s[i]) ;
    return temp ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    s.resize(n+1) ; g.resize(n+1) ; a.resize(n+1) ; ans.resize(n+1) ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> s[i] >> g[i] ;
        a[i]=s[i]+g[i] ;
      }
    l=s[0]-1 ; r=a[0] ;
    res=-1 ;
    /*while(r-l>1)
      {
        m=(l+r)/2 ;
        lli f1=check(m), f2=check(m+1) ;
        if(f1>f2)
          {
            r=m ;
            if(f1>res) res=f1, resVal=ans ;
          }
        else
          {
            l=m ;
            if(f2>res) res=f2, resVal=ans ;
          }
      }*/
    for(int i=a[0] ; i>=s[0] ; i--)
      {
        x=check(i) ;
        if(x!=-1)
          {
            res=x ;
            resVal=ans ;
            break ;
          }
      }
    cout<< res << endl ;
    if(res!=-1) for(int i=0 ; i<n ; i++) cout<< resVal[i] << " " ;
  }
