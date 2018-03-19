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
    string s ;
    cin>> s ;
    int n=s.length(), curr, ans=inf, cntA, cntB ;
    s='#'+s ;
    vi a(n+2, 0), b(n+2, 0) ;
    for(int i=1 ; i<=n ; i++)
      {
        a[i]+=a[i-1] ;
        if(s[i]=='a') a[i]++ ;
        b[i]+=b[i-1] ;
        if(s[i]=='b') b[i]++ ;
      }
    for(int i=0 ; i<=n+1 ; i++)
      for(int j=i+1 ; j<=n+1 ; j++)
        {
          curr=b[i]+max(b[n]-b[j-1], 0)+max(a[j-1]-a[i+1], 0) ;
          if(curr<ans) ans=curr ;
        }
    cout<< max(n-ans, 0) ;
  }
