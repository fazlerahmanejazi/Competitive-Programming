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

int n ;
string x ;
bool pos=true ;
vector<string> a ;

bool check(string s, string r)
  {
    for(int i=0 ; i<s.length() ; i++) if(s[i]=='?') s[i]='9' ;
    return s>r ;
  }

string get(string s, string r)
  {
    string x ;
    if(r.length()>s.length()) pos=false ;
    else if(r.length()==s.length())
      {
        if(!check(s, r)) pos=false ;
        else
          {
            for(int i=0 ; i<s.length() ; i++)
              if(s[i]=='?')
                {
                  s[i]=r[i] ;
                  if(!check(s, r))
                    {
                      s[i]++ ;
                      for(int j=0 ; j<s.length() ; j++) if(s[j]=='?') s[j]='0' ;
                      return s ;
                    }
                }
              else if(s[i]<r[i]) pos=false ;
              else if(s[i]>r[i])
                {
                  for(int j=0 ; j<s.length() ; j++) if(s[j]=='?') s[j]='0' ;
                  return s ;
                }
            return s ;
          }
      }
    else
      {
        for(int i=1 ; i<s.length() ; i++) if(s[i]=='?') s[i]='0' ;
        if(s[0]=='?') s[0]='1' ;
        return s ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    a.pb("0") ;
    for(int i=1 ; i<=n ; i++) cin>> x, a.pb(x) ;
    for(int i=1 ; i<=n ; i++)
      {
        a[i]=get(a[i], a[i-1]) ;
        if(!pos)
          {
            cout<< "NO" ;
            return 0 ;
          }
      }
    if(pos)
      {
        cout<< "YES" << endl ;
        for(int i=1 ; i<=n ; i++) cout<< a[i] << endl ;
      }
    else cout<< "NO" ;
  }
