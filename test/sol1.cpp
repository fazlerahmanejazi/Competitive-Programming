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
    lli n, q, idx, val, x, ans=0, res=0 ;
    cin>> n ;
    vlli a(n+1) ;
    map<lli, lli> cnt ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x ;
        a[i]=x ;
        cnt[x]++ ;
        if(cnt[x]>cnt[x-1] && cnt[x]>cnt[x+1]) ans++ ;
        else if(cnt[x]<=cnt[x-1] && cnt[x]<=cnt[x+1]) ans-- ;
      }
    cin>> q ;
    for(int i=1 ; i<=q ; i++)
      {
        cin>> idx >> val ;
        x=a[idx] ;
        if(cnt[x]<=cnt[x-1] && cnt[x]<=cnt[x+1]) ans++ ;
        else if(cnt[x]>cnt[x-1] && cnt[x]>cnt[x+1]) ans-- ;
        cnt[x]-- ;
        x=a[idx]=val ;
        cnt[x]++ ;
        if(cnt[x]>cnt[x-1] && cnt[x]>cnt[x+1]) ans++ ;
        else if(cnt[x]<=cnt[x-1] && cnt[x]<=cnt[x+1]) ans-- ;
        res=(res+ans*i)%mod ;
      }
    cout<< res ;
  }
