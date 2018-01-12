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
    int n, k, st=0, en=0 ;
    cin>> n >> k ;
    string s ;
    cin>> s ;
    s='#'+s ;
    vpii a ;
    bool check=false ;
    for(int j=0 ; j<26 ; j++)
      {
        char x='A'+j ;
        st=0 ; en=0 ;
        for(int i=1 ; i<=n ; i++)
          if(x==s[i])
            {
              st=i ;
              break ;
            }
        for(int i=n ; i>=1 ; i--)
          if(x==s[i])
            {
              en=i ;
              break ;
            }
        if(st) a.pb(mp(st, en)) ;
      }
    sort(all(a)) ;
    int dur[1000010]={0} ;
    for(int i=0 ; i<a.size() ; i++)
      {
        tie(st, en)=a[i] ;
        dur[st]++ ;
        dur[en+1]-- ;
      }
    for(int i=1 ; i<=1000000 ; i++)
      dur[i]+=dur[i-1] ;
    for(int i=1 ; i<=1000000 ; i++)
      if(dur[i]>k)
        check=true ;
    if(check) cout<< "YES" ;
    else cout<< "NO" ;
  }
