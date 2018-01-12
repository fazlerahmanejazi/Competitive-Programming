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

lli a00, a01, a10, a11, cnt0, cnt1, x10, x01 ;

lli cnt(lli x)
  {
    lli l, r, m, curr ;
    l=1 ; r=1e9 ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        curr=(m*(m-1))/2 ;
        if(curr==x) return m ;
        else if(curr<x) l=m+1 ;
        else r=m-1 ;
      }
    return -1 ;
  }

string recover()
  {
    lli x01=cnt0*cnt1, x10=0, l=cnt0-1, r=cnt0+cnt1-1, diff=cnt1, idx ;
    string s=string(cnt0, '0')+string(cnt1, '1') ;
    while(abs(x01-a01)>diff)
      {
        s[l--]='1' ;
        s[r--]='0' ;
        x01-=diff ;
        x10+=diff ;
      }
    idx=l ;
    while(x01!=a01)
      {
        s[idx++]='1' ;
        s[idx]='0' ;
        x01-- ;
        x10++ ;
      }
    return s ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> a00 >> a01 >> a10 >> a11 ;
    cnt0=cnt(a00) ; cnt1=cnt(a11) ;
    if(cnt0==-1 || cnt1==-1) cout<< "Impossible" ;
    else if(!a01 && !a10)
      {
        if(!a11 && !a00) cout<< 0 ;
        else if(!a00) cout<< string(cnt1, '1') ;
        else if(!a11) cout<< string(cnt0, '0') ;
        else cout<< "Impossible" ;
      }
    else if(cnt0*cnt1!=a01+a10) cout<< "Impossible" ;
    else cout<< recover() ;
  }
