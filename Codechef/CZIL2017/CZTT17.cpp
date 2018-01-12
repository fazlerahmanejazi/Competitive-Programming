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

int get(char x, char y)
  {
    return min(abs(x-y), abs(26-abs((x-y)))) ;
  }

int dpL[100005], dpR[100005], n, l, r, ans, curr ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        string a, b ;
        cin>> a >> b ;
        n=a.length() ;
        a='#'+a ;
        b='#'+b ;
        ans=inf ;
        memset(dpL, 0, sizeof dpL) ;
        memset(dpR, 0, sizeof dpR) ;
        dpR[1]=get(a[1], b[1]) ;
        for(int i=2 ; i<=n ; i++) dpR[i]=dpR[i-1]+get(a[i], b[i])+1 ;
        for(int i=n ; i>=1 ; i--) dpL[i]=dpL[i+1]+get(a[i], b[i])+1 ;
        r=1 ;
        for(int i=0 ; i<=n ; i++)
          {
            l=i ;
            if(r==l) r++ ;
            if(r-l==1) while(a[r]==b[r]) r++ ;
            if(r>n)
              {
                curr=dpR[l] ;
                ans=min(curr, ans) ;
                break ;
              }
            curr=dpL[r]+dpR[l]+max(l-1, 0) ;
            ans=min(curr, ans) ;
            curr=dpL[r]+dpR[l]+n-r+1 ;
            ans=min(curr, ans) ;
          }
        if(n==1) ans=get(a[1], b[1]) ;
        cout<< ans << endl ;
      }
  }
