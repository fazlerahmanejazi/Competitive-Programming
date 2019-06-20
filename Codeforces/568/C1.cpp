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
    lli n, M, sum=0, l, r, m, curr, ans, cnt, stu ;
    cin>> n >> M ;
    vlli a(n), t(200, 0) ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    for(int i=0 ; i<n ; i++)
      {
        if(sum+a[i]<=M) cout<< 0 << " " ;
        else
          {
            l=1, r=i ;
            ans=i ;
            while(l<=r)
              {
                m=(l+r)/2 ;
                curr=0 ;
                cnt=0 ;
                for(lli j=100 ; j>=1 ; j--)
                  {
                    stu=min(t[j], max(m-cnt, 0LL)) ;
                    curr+=j*stu ;
                    cnt+=stu ;
                  }
                if(sum+a[i]-curr<=M) r=m-1, ans=min(ans, m) ;
                else l=m+1 ;
              }
            cout<< ans << " " ;
          }
        sum+=a[i] ;
        t[a[i]]++ ;
      }
  }
