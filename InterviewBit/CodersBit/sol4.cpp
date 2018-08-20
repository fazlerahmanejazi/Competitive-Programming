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


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;

    for(int x=1 ; x<=100 ; x++)
      {
        lli n, idx=26, curr, len, pos=0 ;
    n=x ;
    vlli a, p ;
    a.pb(1) ; p.pb(1) ;
    string s="" ;
    while(a.back()<inf) a.pb(idx), p.pb(idx), idx=idx*26 ;
    for(int i=1 ; i<a.size() ; i++) a[i]+=a[i-1] ;
    curr=n ;
    len=upper_bound(all(a), n)-a.begin() ;
    curr-=a[len-1] ;
    for(int i=0 ; i<len ; i++) s+='a' ;
    while(len>0 && curr>0)
      {
        idx=0 ;
        while(idx*p[len-1]<=curr) idx++ ;
        idx-- ;
        s[pos++]=(char)(idx+'a') ;
        curr-=idx*p[len-1] ;
        len-- ;
      }
    len=s.length()-1 ;
    for(int i=len-1 ; i>=0 ; i--) s+=s[i] ;
    cout<< s << endl ;;
  }
}
