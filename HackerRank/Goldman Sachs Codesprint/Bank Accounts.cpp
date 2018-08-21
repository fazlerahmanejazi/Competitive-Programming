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
    int T ;
    cin>> T ;
    while(T--)
      {
        int n, k, x, d ;
        double charge, upfront=0, fee=0, curr ;
        cin>> n >> k >> x >> d ;
        vi a(n+1), pre(n+1, 0) ;
        for(int i=1 ; i<=n ; i++)
          {
            cin>> a[i] ;
            pre[i]+=pre[i-1]+a[i] ;
          }
        upfront=pre[n]-d ;
        for(int i=1 ; i<=n ; i++)
          {
            charge=max(1.0*k, 1.0*x*a[i]/100.0) ;
            fee+=1.0*a[i]-charge ;
            curr=fee+1.0*(pre[n]-pre[i]-d) ;
            upfront=max(upfront, curr) ;
          }
        if(fee>=upfront) cout<< "fee" << endl ;
        else cout<< "upfront" << endl ;
      }
  }
