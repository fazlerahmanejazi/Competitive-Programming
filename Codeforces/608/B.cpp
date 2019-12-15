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
    int n, cnt=0 ;
    bool pos ;
    string s, r ;
    cin>> n >> s ;
    r=s ;
    pos=true ;
    for(int i=0 ; i<n ; i++)
      if(r[i]=='B' && i+1<n)
        {
          if(r[i+1]=='W') r[i+1]='B' ;
          else r[i+1]='W' ;
          r[i]='W' ;
          cnt++ ;
        }
    for(int i=0 ; i<n ; i++) if(r[i]=='B') pos=false ;
    if(pos)
      {
        cout<< cnt << endl ;
        r=s ;
        for(int i=0 ; i<n ; i++)
          if(r[i]=='B' && i+1<n)
            {
              cout<< i+1 << " " ;
              if(r[i+1]=='W') r[i+1]='B' ;
              else r[i+1]='W' ;
              r[i]='W' ;
            }
        return 0 ;
      }
    r=s ;
    pos=true ;
    for(int i=0 ; i<n ; i++)
      if(r[i]=='W' && i+1<n)
        {
          if(r[i+1]=='W') r[i+1]='B' ;
          else r[i+1]='W' ;
          r[i]='B' ;
          cnt++ ;
        }
    for(int i=0 ; i<n ; i++) if(r[i]=='W') pos=false ;
    if(pos)
      {
        cout<< cnt << endl ;
        r=s ;
        for(int i=0 ; i<n ; i++)
          if(r[i]=='W' && i+1<n)
            {
              cout<< i+1 << " " ;
              if(r[i+1]=='W') r[i+1]='B' ;
              else r[i+1]='W' ;
              r[i]='B' ;
            }
        return 0 ;
      }
    cout<< -1 ;
  }
