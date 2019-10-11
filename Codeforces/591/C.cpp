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
    int q ;
    cin>> q ;
    while(q--)
      {
        lli n, p[200005], cnt[200005], a, x, y, b, k, curr=0, ans=-1, idx1, idx2, l, r, m ;
        memset(cnt, 0, sizeof cnt) ;
        cin>> n ;
        for(int i=1 ; i<=n ; i++) cin>> p[i] ;
        cin>> x >> a >> y >> b >> k ;
        for(int i=a ; i<=n ; i+=a) cnt[i]+=x ;
        for(int i=b ; i<=n ; i+=b) cnt[i]+=y ;
        sort(p+1, p+n+1) ;
        l=1 ; r=n ;
        while(l<=r)
          {
            m=(l+r)/2 ;
            curr=0 ;
            vlli temp ;
            for(int i=1 ; i<=m ; i++) if(cnt[i]) temp.pb(cnt[i]) ;
            sort(all(temp)) ;
            idx1=temp.size()-1 ;
            idx2=n ;
            while(idx1) curr+=p[idx2]*temp[idx1], idx1--, idx2-- ;
            if(curr>=k) r=m-1, ans=m ;
            else l=m+1 ;
          }
        cout<< ans ;
      }
  }
