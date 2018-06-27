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

lli n, ans ;
string s[2] ;

bool check(int idx, int t)
  {
    if(t==0) return (s[0][idx]=='0' && s[0][idx-1]=='0' && s[1][idx-1]=='0') ;
    else if(t==1) return (s[0][idx]=='0' && s[0][idx-1]=='0' && s[1][idx]=='0') ;
    else if(t==2) return (s[1][idx]=='0' && s[1][idx-1]=='0' && s[0][idx]=='0') ;
    else return (s[1][idx]=='0' && s[1][idx-1]=='0' && s[0][idx-1]=='0') ;
  }

void fill(int idx, int t)
  {
    ans++ ;
    if(t==0) s[0][idx]='X', s[0][idx-1]='X', s[1][idx-1]='X' ;
    else if(t==1) s[0][idx]='X', s[0][idx-1]='X', s[1][idx]='X' ;
    else if(t==2) s[1][idx]='X', s[1][idx-1]='X', s[0][idx]='X' ;
    else s[1][idx]='X', s[1][idx-1]='X', s[0][idx-1]='X' ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> s[0] >> s[1] ;
    n=s[0].length() ;
    if(n==1) return cout<< 0, 0 ;
    for(int i=1 ; i<n ; i++)
      for(int j=0 ; j<4 ; j++)
        if(check(i, j))
          fill(i, j) ;
    cout<< ans ;
  }
