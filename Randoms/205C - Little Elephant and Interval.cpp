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

lli calc(lli n)
  {
    if(n<10) return n ;
    lli res=0 ;
    string s=to_string(n), temp="0" ;
    int l=s.length() ;
    for(int i=1 ; i<=l-2 ; i++)
      temp+=s[i] ;
    res=stoll(temp) ;
    if(s[l-1]<s[0]) res-- ;
    res+=(s[0]-'0')*pow(10, l-2) ;
    return res+9 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli l, r ;
    cin>> l >> r ;
    cout<< calc(r)-calc(l-1) ;
  }
