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
    lli l, len ;
    bool check=false ;
    string s, ans="", r="" ;
    cin>> l >> s ;
    len=s.length() ;
    if(len%l)
      {
        r='1' ;
        for(int i=1 ; i<l ; i++) r+='0' ;
      }
    else
      {
        for(int i=0 ; i<l ; i++) r+=s[i] ;
        check=true ;
        for(int j=0 ; j<len ; j+=l)
          {
            string temp="" ;
            for(int k=0 ; k<l ; k++) temp+=s[j+k] ;
            if(temp<r)
              {
                check=false ;
                break ;
              }
          }
        if(check)
          for(int i=l-1 ; i>=0 ; i--)
            if(r[i]!='9')
              {
                r[i]++ ;
                check=false ;
                break ;
              }
          else r[i]='0' ;
        if(check)
          {
            r='1' ;
            for(int i=1 ; i<l ; i++) r+='0' ;
          }
      }
    while(ans.length()<len) ans+=r ;
    if(l==1 && check) ans+='1' ;
    else if(check) ans+=r ;
    cout<< ans ;
  }
