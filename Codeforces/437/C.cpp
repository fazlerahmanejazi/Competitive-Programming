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

lli n, S, x, y, tot, P, s, a, b, l, r, m, p1, p2, curr, ans, f1, f2 ;
vector<tuple<lli, lli, lli, lli>> A, B ;
vlli checkA, checkB ;

lli check(lli m)
  {
    p1=m*S ; p2=(P-m)*S ;
    curr=0 ;
    x=y=inf ;
    for(int i=0 ; i<A.size() ; i++) checkA[i]=get<3>(A[i]) ;
    for(int i=0 ; i<B.size() ; i++) checkB[i]=get<3>(B[i]) ;
    for(int i=0 ; i<A.size() ; i++)
      if(p1>=checkA[i])
        {
          curr+=get<1>(A[i])*checkA[i] ;
          p1-=checkA[i] ;
          checkA[i]=0 ;
        }
      else
        {
          curr+=get<1>(A[i])*p1 ;
          checkA[i]-=p1 ;
          x=i ;
          p1=0 ;
          break ;
        }
    for(int i=0 ; i<B.size() ; i++)
      if(p2>=checkB[i])
        {
          curr+=get<2>(B[i])*checkB[i] ;
          p2-=checkB[i] ;
          checkB[i]=0 ;
        }
      else
        {
          curr+=get<2>(B[i])*p2 ;
          checkB[i]-=p2 ;
          y=i ;
          p2=0 ;
          break ;
        }
    if(x==inf) for(int i=y ; i<B.size() ; i++) curr+=get<1>(B[i])*checkB[i] ;
    if(y==inf) for(int i=x ; i<A.size() ; i++) curr+=get<2>(A[i])*checkA[i] ;
    return curr ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> S ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> s >> a >> b ;
        tot+=s ;
        if(a>b) A.pb(mt(b-a, a, b, s)) ;
        else B.pb(mt(a-b, a, b, s)) ;
      }
    sort(all(A)) ; sort(all(B)) ;
    checkA.resize(A.size()+1), checkB.resize(B.size()+1) ;
    P=ceil((1.0*tot)/S) ;
    l=-1 ; r=P ;
    ans=0 ;
    while(r-l>1)
      {
        m=(l+r)/2 ;
        f1=check(m) ; f2=check(m+1) ;
        if(f1>f2)
          {
            r=m ;
            ans=max(ans, f1) ;
          }
        else
          {
            l=m ;
            ans=max(ans, f2) ;
          }
      }
    cout<< ans ;
  }
