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

int n, x, l, r, m, ans=inf, tot, curr ;
string s ;
set<char> pokemon ;
map<char, int> cnt ;

bool check(int x)
  {
    curr=0 ;
    cnt.clear() ;
    for(int i=0 ; i<x ; i++)
      {
        if(!cnt[s[i]]) curr++ ;
        cnt[s[i]]++ ;
        if(curr==tot) return true ;
      }
    for(int i=x ; i<n ; i++)
      {
        cnt[s[i-x]]-- ;
        if(!cnt[s[i-x]]) curr-- ;
        if(!cnt[s[i]]) curr++ ;
        cnt[s[i]]++ ;
        if(curr==tot) return true ;
      }
    return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> s ;
    l=1 ; r=n ;
    for(int i=0 ; i<n ; i++) pokemon.insert(s[i]) ;
    tot=pokemon.size() ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        if(check(m)) ans=min(ans, m), r=m-1 ;
        else l=m+1 ;
      }
    cout<< ans ;
  }
