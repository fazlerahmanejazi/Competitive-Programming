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

int n, m, ans=0 ;
string s, t, r ;

bool check(int idx, string &x)
  {
    map<char, char> match ;
    bool pos=true ;
    for(int j=0 ; j<m ; j++)
      if(match.find(x[j])!=match.end() && match[x[j]]!=s[idx+j]) pos=false ;
      else if(match.find(x[j])==match.end()) match[x[j]]=s[idx+j] ;
    return pos ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> s >> t ;
    r=t ;
    reverse(all(r)) ;
    n=s.length() ;
    m=t.length() ;
    for(int i=0 ; i<n-m+1 ; i++) if(check(i, r) || check(i, t)) ans++ ;
    cout<< ans ;
  }
