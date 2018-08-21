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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    string s ;
    cin>> s ;
    int len=s.length(), tot, x, ans=inf, curr, lower, upper ;
    vi pre(len+1) ;
    if(isupper(s[0])) pre[0]=1 ;
    for(int i=1 ; i<len ; i++)
      if(isupper(s[i])) pre[i]=pre[i-1]+1 ;
      else pre[i]=pre[i-1] ;
    tot=pre[len-1] ;
    ans=tot ;
    for(int i=0 ; i<len ; i++)
      {
        upper=tot-pre[i] ;
        lower=i+1-pre[i] ;
        curr=lower+upper ;
        ans=min(ans, curr) ;
      }
    cout<< ans ;
  }
