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

lli n, x, y, id, m, k, sz[30], sum[30], xSum[30], sqrSum[30], conc[30][30], dp[2000000] ;
map<lli, vlli> groups ;

lli getGroup(lli x)
  {
    lli cnt=0 ;
    for(lli i=2 ; i*i<=x ; i++) while(!(x%i)) x/=i, cnt++ ;
    if(x!=1) cnt++ ;
    return cnt ;
  }

lli getConc(lli idx, lli y)
  {
    lli res=y*y*sum[idx]+2*y*xSum[idx]+sqrSum[idx] ;
    return res ;
  }

void fillDP()
  {
    for(lli mask=0 ; mask<(1<<k) ; mask++)
      {
        x=0 ;
        for(lli i=0 ; i<30 ; i++) if(mask&(1<<i)) x+=sz[i] ;
        for(lli i=0 ; i<k ; i++)
          if(!(mask&(1<<i)))
            dp[mask|(1<<i)]=max(dp[mask|(1<<i)], dp[mask]+getConc(i, x)) ;
      }
  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> id >> m ;
        groups[getGroup(id)].pb(m) ;
      }
    k=groups.size() ;
    x=0 ;
    for(auto i:groups)
      {
        vlli &temp=i.se ;
        sort(all(temp)) ;
        for(int j=0 ; j<temp.size() ; j++)
          {
            sum[x]+=temp[j] ;
            xSum[x]+=(j+1)*temp[j] ;
            sqrSum[x]+=(j+1)*(j+1)*temp[j] ;
          }
        sz[x]=temp.size() ;
        x++ ;
      }
    fillDP() ;
    cout<< dp[(1<<k)-1] ;
  }
