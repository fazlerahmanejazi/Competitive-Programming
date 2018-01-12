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

int check(vi a, vi b, int l, int r)
  {
    int curr=0 ;
    for(int i=0 ; i<n ; i++)
      if(a[i]<l || b[i]>r)
        curr++ ;
    return curr ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, e1, e2, ans=0, curr, l, r ;
    cin>> n >> e1 >> e2 ;
    vi a(n), b(n) ;
    for(int i=0 ; i<n ; i++) cin>> a[i] >> b[i] ;
    if(e2<e1) swap(e1, e2) ;
    curr=0 ;
    l=1 ; r=e2 ;
    for(int i=0 ; i<n ; i++)
      {
        bool check=false ;
        if(b[i]>a[i]) check=true ;
        if(a[i]>e2) check=true ;
        if(check) curr++ ;
      }
    ans=max(ans, n-curr) ;
    curr=0 ;
    l=e1 ; r=n ;
    for(int i=0 ; i<n ; i++)
      {
        bool check=false ;
        if(b[i]<a[i]) check=true ;
        if(a[i]<e1) check=true ;
        if(check) curr++ ;
      }
    ans=max(ans, n-curr) ;
    curr=0 ;
    l=1 ; r=n ;
    for(int i=0 ; i<n ; i++)
      {
        bool check=false ;
        if(a[i]>e2 && b[i]<a[i]) check=true ;
        if(a[i]<e1 && b[i]>a[i]) check=true ;
        if(check) curr++ ;
      }
    ans=max(ans, n-curr) ;
    curr=0 ;
    for(int i=0 ; i<n ; i++)
      {
        bool check=false ;
        if(a[i]>e1 && a[i]<e2) check=true ;
        if(b[i]>e1 && b[i]<e2) check=true ;
        if(a[i]<e1 && b[i]>e2) check=true ;
        if(a[i]<e2 && b[i]>a[i]) check=true ;
        if(a[i]>e1 && b[i]<a[i]) check=true ;
        if(check) curr++ ;
      }
    ans=max(ans, n-curr) ;
    cout<< ans ;
  }
