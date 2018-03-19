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
const int q=71 ;

int n, m ;
string s ;
int lHash[M][M], rHash[M][M], pal[M][M], cnt[M] ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> s ;
    n=s.length() ;
    s='#'+s ;
    for(int i=1 ; i<=n ; i++)
      for(int j=i ; j<=n ; j++)
        lHash[i][j]=((lli)lHash[i][j-1]*q+(lli)s[j])%mod ;
    for(int i=n ; i>=1 ; i--)
      for(int j=i ; j<=n ; j++)
        rHash[i][j]=((lli)rHash[i+1][j]*q+(lli)s[i])%mod ;
    for(int i=1 ; i<=n ; i++)
      for(int j=i ; j<=n ; j++)
        {
          m=(j-i-1)/2 ;
          if(lHash[i][i+m]==rHash[j-m][j])
            pal[i][j]=pal[i][i+m]+1 ;
          cnt[pal[i][j]]++ ;
        }
    for(int i=n-1 ; i>=1 ; i--)
      cnt[i]+=cnt[i+1] ;
    for(int i=1 ; i<=n ; i++)
      cout<< cnt[i] << " " ;
  }
