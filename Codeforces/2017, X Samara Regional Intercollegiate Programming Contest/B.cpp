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

int cnt, ans ;
string s, r="happiness" ;

bool check(int idx)
  {
    if(idx+r.length()>s.length()) return false ;
    for(int i=0 ; i<r.length() ; i++) if(s[idx+i]!=r[i]) return false ;
    return true ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> s ;
    for(int i=0 ; i<s.length() ; i++) if(check(i)) ans++ ;
    if(ans==0)
      {
        swap(s[0], s[1]) ;
        if(check(0) || check(1))
          {
            swap(s[0], s[1]) ;
            swap(s[1], s[2]) ;
            cout<< "YES" << endl << 2 << " " << 3 ;
          }
        else cout<< "YES" << endl << 1 << " " << 2 ;
      }
    else if(ans==1)
      {
        for(int i=0 ; i<s.length() ; i++)
          if(check(i))
            {
              cout<< "YES" << endl << i+1 << " " << i+2 ;
              return 0 ;
            }
      }
    else if(ans==2)
      {
        vi a ;
        for(int i=0 ; i<s.length() ; i++) if(check(i)) a.pb(i+1) ;
        cout<< "YES" << endl << a[0] << " " << a[1]+1 ;
      }
    else cout<< "NO" ;
  }
