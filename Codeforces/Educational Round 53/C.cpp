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

lli n, xf, yf, x, y, l, r, m, ans, dp[5][300000] ;
string s ;
map<char, int> f ;

lli get(char c)
  {
    if(c=='U' || c=='R') return 1 ;
    else return -1 ;
  }

bool canReach(lli xx, lli yy, lli x, lli y)
  {
    if(x<y) swap(x, y), swap(xx, yy) ;
    lli temp=min((x-y)/2, xx) ;
    x-=2*temp-y ;
    xx-=temp ;
    if(x) return false ;
    if(xx+yy>=x+y) return true ;
    return false ;
  }

bool check(lli l, char xc, char yc)
  {
    lli currX=0, currY=0 ;
    for(int i=1 ; i<=l ; i++)
      {
        if(s[i]==xc) currX++ ;
        if(s[i]==yc) currY++ ;
        if(canReach(currX, currY, x, y)) return true ;
      }
    for(int i=l+1 ; i<=n ; i++)
      {
        if(s[i-l]==xc) currX-- ;
        if(s[i-l]==yc) currY-- ;
        if(s[i]==xc) currX++ ;
        if(s[i]==yc) currY++ ;
        if(canReach(currX, currY, x, y)) return true ;
      }
    if(canReach(currX, currY, x, y)) return true ;
    return false ;
  }

lli solve(char xc, char yc)
  {
    lli ans=n ;
    l=0 ; r=n ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        if(check(m, xc, yc)) r=m-1, ans=m ;
        else l=m+1 ;
      }
    check(58, xc, yc) ;
    return ans ;
  }

bool possible()
  {
    lli dist=abs(xf)+abs(yf), diff=n-dist ;
    if(diff<0 || diff%2 || (abs(x)+abs(y))%2) return false ;
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> s >> xf >> yf ;
    s='#'+s ;
    f['U']=0 ; f['D']=1 ; f['R']=2 ; f['L']=3 ;
    for(int i=1 ; i<=n ; i++)
      for(int j=0 ; j<4 ; j++)
        dp[j][i]=dp[j][i-1]+(f[s[i]]==j) ;
    if(!possible()) return cout<< -1, 0 ;

  }
