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

int n, l, r, m, ans=inf ;
string s ;

bool check(int x)
  {
    vi cnt(27, 0) ;
    for(int i=0 ; i<x ; i++) cnt[s[i]-'a']++ ;
    for(int i=x ; i<n ; i++)
      {
        if(cnt[s[i]-'a']>0) cnt[s[i]-'a']++ ;
        cnt[s[i-x]-'a']-- ;
      }
    for(int i=0 ; i<26 ; i++) if(cnt[i]>0) return true ;
    return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> s ;
    n=s.length() ;
    l=1 ; r=n ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        if(check(m)) ans=min(m, ans), r=m-1 ;
        else l=m+1 ;
      }
    cout<< ans ;
  }
