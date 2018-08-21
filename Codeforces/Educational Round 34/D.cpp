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
    lli n, sum=0, ans=0, curr, c=1, p, q, r ;
    cin>> n ;
    vlli a(n) ;
    unordered_map<lli, lli> cnt ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    for(int i=n-1 ; i>=0 ; i--)
      {
        sum+=a[i] ;
        cnt[a[i]]++ ;
        p=cnt[a[i]+1] ; q=cnt[a[i]-1] ; r=cnt[a[i]] ;
        curr=(sum-p*(a[i]+1)-q*(a[i]-1)-r*a[i])-(c-p-q-r)*a[i] ;
        ans+=curr ;
        c++ ;
      }
    cout<< ans ;
  }
