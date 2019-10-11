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

lli n ;
string t ;

bool checkPal(int s, int e)
  {
    bool pos=true ;
    while(s<e && pos)
      if(t[s]!=t[e]) pos=false ;
      else s++, e-- ;
    return pos ;
  }

lli solve(int s, int e)
  {
    if(s>=e) return 0 ;
    if(checkPal(s, e)) return 1+solve(s+1, e)+solve(s, e-1) ;
    else return solve(s+1, e)+solve(s, e-1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> t ;
    cout<< solve(0, n-1) ;
  }
