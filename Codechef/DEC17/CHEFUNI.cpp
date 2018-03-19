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

lli T, A, B, C, ans, p, q, curr ;
vlli d(3), temp ;

void solve1()
  {
    temp=d ;
    curr=0 ;
    sort(all(temp)) ;
    p=temp[0] ;
    for(int i=0 ; i<3 ; i++) temp[i]-=p ;
    curr+=p*C ;
    sort(all(temp)) ;
    p=temp[1] ;
    curr+=p*B ;
    for(int i=1 ; i<3 ; i++) temp[i]-=p ;
    curr+=temp[2]*A ;
    ans=min(curr, ans) ;
    curr=0 ;
    temp=d ;
    sort(all(temp)) ;
    p=min(temp[0], temp[2]-temp[1]) ;
    temp[0]-=p ; temp[2]-=p ;
    curr+=p*B ;
    sort(all(temp)) ;
    p=temp[0] ;
    temp[1]+=p-(p/2) ; temp[2]+=p/2 ; temp[0]=0 ;
    p=min(temp[1], temp[2]) ;
    curr+=p*B ;
    temp[1]-=p ; temp[2]-=p ;
    curr+=(temp[0]+temp[1]+temp[2])*A ;
    ans=min(curr, ans) ;
    temp=d ;
    curr=0 ;
    curr+=(temp[0]+temp[1]+temp[2])*A ;
    ans=min(curr, ans) ;
  }

void solve2()
  {
    curr=0 ;
    temp=d ;
    sort(all(temp)) ;
    p=min(temp[0], temp[2]-temp[1]) ;
    temp[0]-=p ; temp[2]-=p ;
    curr+=p*B ;
    sort(all(temp)) ;
    p=temp[0] ;
    temp[1]+=p-(p/2) ; temp[2]+=p/2 ; temp[0]=0 ;
    p=min(temp[1], temp[2]) ;
    curr+=p*B ;
    temp[1]-=p ; temp[2]-=p ;
    curr+=(temp[0]+temp[1]+temp[2])*A ;
    ans=min(curr, ans) ;
    temp=d ;
    curr=0 ;
    curr+=(temp[0]+temp[1]+temp[2])*A ;
    ans=min(curr, ans) ;
    temp=d ;
    sort(all(temp)) ;
    curr=0 ;
    curr+=C ;
    for(int i=0 ; i<3 ; i++) temp[i]-- ;
    sort(all(temp)) ;
    p=min(temp[0], temp[2]-temp[1]) ;
    temp[0]-=p ; temp[2]-=p ;
    curr+=p*B ;
    sort(all(temp)) ;
    p=temp[0] ;
    temp[1]+=p-(p/2) ; temp[2]+=p/2 ; temp[0]=0 ;
    p=min(temp[1], temp[2]) ;
    curr+=p*B ;
    temp[1]-=p ; temp[2]-=p ;
    curr+=(temp[0]+temp[1]+temp[2])*A ;
    ans=min(curr, ans) ;
    temp=d ;
    curr=0 ;
    curr+=(temp[0]+temp[1]+temp[2])*A ;
    ans=min(curr, ans) ;
  }

void solve3()
  {
    curr=0 ;
    temp=d ;
    sort(all(temp)) ;
    p=temp[0]+temp[1]-temp[2] ;
    if(p<0) return ;
    for(int i=0 ; i<3 ; i++) temp[i]-=p ;
    curr+=p*C ;
    ans=min(curr+(temp[0]+temp[1]+temp[2])*A, ans) ;
    sort(all(temp)) ;
    p=min(temp[0], temp[2]-temp[1]) ;
    temp[0]-=p ; temp[2]-=p ;
    curr+=p*B ;
    sort(all(temp)) ;
    p=temp[0] ;
    temp[1]+=p-(p/2) ; temp[2]+=p/2 ; temp[0]=0 ;
    p=min(temp[1], temp[2]) ;
    curr+=p*B ;
    temp[1]-=p ; temp[2]-=p ;
    curr+=(temp[0]+temp[1]+temp[2])*A ;
    ans=min(curr, ans) ;
    temp=d ;
    curr=0 ;
    curr+=(temp[0]+temp[1]+temp[2])*A ;
    ans=min(curr, ans) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> d[0] >> d[1] >> d[2] >> A >> B >> C ;
        ans=INF ;
        sort(all(d)) ;
        temp=d ;
        solve1() ; solve2() ; solve3() ;
        if(2*C<3*B && B<2*A)
          {
            temp=d ;
            curr=0 ;
            sort(all(temp)) ;
            p=temp[0] ;
            if(p%2) p-- ;
            for(int i=0 ; i<3 ; i++) temp[i]-=p ;
            curr+=p*C ;
            sort(all(temp)) ;
            p=min(temp[0], temp[2]-temp[1]) ;
            temp[0]-=p ; temp[2]-=p ;
            curr+=p*B ;
            sort(all(temp)) ;
            p=temp[0] ;
            temp[1]+=p-(p/2) ; temp[2]+=p/2 ; temp[0]=0 ;
            p=min(temp[1], temp[2]) ;
            curr+=p*B ;
            temp[1]-=p ; temp[2]-=p ;
            curr+=(temp[0]+temp[1]+temp[2])*A ;
            ans=min(curr, ans) ;
          }
        else if(2*C<3*B && B>2*A && C<3*A)
          {
            temp=d ;
            curr=0 ;
            sort(all(temp)) ;
            p=temp[0] ;
            for(int i=0 ; i<3 ; i++) temp[i]-=p ;
            curr+=p*C ;
            curr+=(temp[0]+temp[1]+temp[2])*A ;
            ans=min(curr, ans) ;
          }
        else if(2*C<3*B && C>3*A)
          {
            temp=d ;
            curr=0 ;
            curr+=(temp[0]+temp[1]+temp[2])*A ;
            ans=min(curr, ans) ;
          }
        else if(2*C>3*B && B>2*A)
          {
            temp=d ;
            curr=0 ;
            curr+=(temp[0]+temp[1]+temp[2])*A ;
            ans=min(curr, ans) ;
          }
        else if(2*C>3*B && B<2*A)
          {
            temp=d ;
            curr=0 ;
            sort(all(temp)) ;
            p=min(temp[0], temp[2]-temp[1]) ;
            temp[0]-=p ; temp[2]-=p ;
            curr+=p*B ;
            sort(all(temp)) ;
            p=temp[0] ;
            temp[1]+=p-(p/2) ; temp[2]+=p/2 ; temp[0]=0 ;
            p=min(temp[1], temp[2]) ;
            curr+=p*B ;
            temp[1]-=p ; temp[2]-=p ;
            curr+=(temp[0]+temp[1]+temp[2])*A ;
            ans=min(curr, ans) ;
          }
        else
          {
            temp=d ;
            curr=0 ;
            curr+=(temp[0]+temp[1]+temp[2])*A ;
            ans=min(curr, ans) ;
          }
        cout<< ans << endl ;
      }
  }
