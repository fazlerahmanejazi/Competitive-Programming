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
    int n, pos, l, r, ans=0, m=0, curr=0 ;
    cin>> n >> pos >> l >> r ;
    m=pos ;
    if(pos<=l)
      {
        if(l!=1)
          {
            while(pos<l) pos++, ans++ ;
            ans++ ;
          }
        if(r!=n)
          {
            while(pos<r) pos++, ans++ ;
            ans++ ;
          }
      }
    else if(pos>=r)
      {
        if(r!=n)
          {
            while(pos>r) pos--, ans++ ;
            ans++ ;
          }
        if(l!=1)
          {
            while(pos>l) pos--, ans++ ;
            ans++ ;
          }
      }
    else
      {
        if(l!=1)
          {
            while(pos>l) pos--, curr++ ;
            curr++ ;
          }
        if(r!=n)
          {
            while(pos<r) pos++, curr++ ;
            curr++ ;
          }
        ans=curr ;
        curr=0 ;
        pos=m ;
        if(r!=n)
          {
            while(pos<r) pos++, curr++ ;
            curr++ ;
          }
        if(l!=1)
          {
            while(pos>l) pos--, curr++ ;
            curr++ ;
          }
        ans=min(ans, curr) ;
      }
    cout<< ans ;
  }
