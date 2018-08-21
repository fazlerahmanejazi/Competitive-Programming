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
    lli n, res=0 ;
    cin>> n ;
    vlli a(n), cnt(1000010, 0), ans(1000010, 0), p(1000010, 0) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    for(int i=0 ; i<n ; i++)
      for(int j=1 ; j*j<=a[i] ; j++)
        if(a[i]%j==0 && a[i]/j!=j) cnt[j]++, cnt[a[i]/j]++ ;
        else if(a[i]%j==0) cnt[j]++ ;
    p[0]=1 ;
    for(int i=1 ; i<=1000000 ; i++)
      p[i]=(p[i-1]*2)%mod ;
    for(int i=1000000 ; i>=2 ; i--)
      if(cnt[i])
        {
          ans[i]=(cnt[i]*p[cnt[i]-1])%mod ; ;
          for(int j=i+i ; j<=1000000 ; j+=i)
            ans[i]=(ans[i]-ans[j]+mod)%mod ;
          res=(res+i*ans[i])%mod ;
        }
    cout<< res ;
  }
