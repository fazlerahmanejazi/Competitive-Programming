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

const int M=5010 ;
const int p=71 ;

lli n, m, l, r ;
string s ;
lli pal[M][M], cnt[M], pre[M], suf[M] ;

lli power(lli base, lli exp)
  {
    lli res=1;
    while(exp>0)
      {
        if(exp%2==1) res=((lli)res*base)%mod;
        base=((lli)base*base)%mod;
        exp/=2;
      }
    return res%mod;
  }

void generate()
  {
    pre[1]=s[1]*p ;
    suf[n]=s[n]*p ;
    for(int i=2 ; i<=n ; i++)
      pre[i]=(((lli)s[i]*power(p, i))%mod+pre[i-1])%mod ;
    for(int i=n-1 ; i>=1 ; i--)
      suf[i]=(((lli)s[i]*power(p, n-i+1))%mod+suf[i+1])%mod ;
  }

lli getInverse(lli n)
  {
    return power(n, mod-2);
  }

lli divide(lli a, lli b)
  {
    return (a*getInverse(b))%mod;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> s ;
    n=s.length() ;
    s='#'+s ;
    generate() ;
    for(int i=1 ; i<=n ; i++)
      for(int j=i ; j<=n ; j++)
        {
          m=(j-i-1)/2 ;
          l=(pre[i+m]-pre[i-1]+mod)%mod ;
          l=divide(l, power(p, i)) ;
          r=(suf[j-m]-suf[j+1]+mod)%mod ;
          r=divide(r, power(p, n-j+1)) ;
          if(r==l)
            pal[i][j]=pal[i][i+m]+1 ;
          cnt[pal[i][j]]++ ;
        }
    for(int i=n-1 ; i>=1 ; i--)
      cnt[i]+=cnt[i+1] ;
    for(int i=1 ; i<=n ; i++)
      cout<< cnt[i] << " " ;
  }
